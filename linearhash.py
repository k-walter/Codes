import swifter
import numpy as np
import pandas as pd

class LinearHash:
	def __init__(self):
		self.size = 0
		self.tab = [[], []]

	def insert(self, u: int):
		print("\nInsert", bin(u))
		for i in range(len(self.tab)-1, -1, -1):
			if (u & i) == i:
				self.tab[i].append(u)
				break
		self.size += 1
		print(pd.DataFrame(self.tab).apply(lambda x: bin(x) if isinstance(x,int) else 'x'))
		if self.resize():
			df = pd.DataFrame(self.tab)\
				   .swifter\
				   .apply(lambda x: 'y' if isinstance(x,int) else 'x')
			print(df)

	def one_mask(self, u: int) -> int:
		u |= (u >> 1)
		u |= (u >> 2)
		u |= (u >> 4)
		u |= (u >> 8)
		u |= (u >> 16)
		return u

	def msb(self, u: int) -> int:
		return (self.one_mask(u) + 1) >> 1

	def resize(self) -> bool:
		if self.size <= 3 * len(self.tab) / 2:
			return False
		newHash = len(self.tab)
		prvHash = newHash ^ self.msb(newHash)
		old, new = [], []
		for i in self.tab[prvHash]:
			if (i & newHash) == newHash:
				new.append(i)
			else:
				old.append(i)
		self.tab[prvHash] = old
		self.tab.append(new)
		return True

lh = LinearHash()
for i in range(0b1111, 0-1, -1):
	lh.insert(i)