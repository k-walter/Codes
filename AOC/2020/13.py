from typing import List, Generator
from math import prod


class Solution:
    def __init__(self, fname, doTest=False):
        if doTest:
            self.test()
        with open(fname) as f:
            self.parse(f.read())

    def parse(self, r: str):
        dep: str
        buses: str
        dep, buses = r.split()
        busL: List[str] = buses.split(',')
        self.dep: int = int(dep)
        self.buses: List[int] = [int(i) for i in busL if i.isnumeric()]
        self.rem: List[int] = [self.calcWait(
            i, int(b)) for i, b in enumerate(busL) if b.isnumeric()]

    def calcWait(self, n: int, d: int) -> int:
        return d - (n % d) if n % d else 0

    def earliestBus(self) -> int:

        def argFn(i: int) -> int:
            return mods[i]
        mods: List[int] = [self.calcWait(self.dep, b) for b in self.buses]
        minIdx: int = min(range(len(mods)), key=argFn)
        minBus: int = self.buses[minIdx]
        minWait: int = mods[minIdx]
        return minBus * minWait

    def crt(self) -> int:
        # assumes coprime
        pi: int = prod(self.buses)
        pp: List[int] = [int(pi / i) for i in self.buses]
        inv: Generator[int, None, None] = (
            pow(m, -1, d) for d, m in zip(self.buses, pp))
        soln: int = sum(r * p * i for r, p, i in zip(self.rem, pp, inv))
        smallestSoln: int = soln % pi
        return smallestSoln

    def test(self):
        t = Solution('13.test')
        assert t.earliestBus() == 5 * 59
        assert t.crt() == 1068781
        t.parse('0\n17,x,13,19')
        assert t.crt() == 3417
        t.parse('0\n67,7,59,61')
        t.crt
        assert t.crt() == 754018
        t.parse('0\n67,x,7,59,61')
        t.crt
        assert t.crt() == 779210
        t.parse('0\n67,7,x,59,61')
        t.crt
        assert t.crt() == 1261476
        t.parse('0\n1789,37,47,1889')
        t.crt
        assert t.crt() == 1202161486


s = Solution('13.in', True)
print(s.earliestBus())
print(s.crt())
