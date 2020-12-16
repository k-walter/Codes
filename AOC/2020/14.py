from typing import List, Tuple, Dict, Generator


class Solution:
    def __init__(self, fname: str, test: bool = False):
        self.lines: List[Tuple[str, str]] = list()
        if test:
            self.test()
        with open(fname) as f:
            self.parse(f.read())

    def test(self):
        with open('14.test') as f:
            self.parse(f.read())
        assert self.bitMask() == 101 + 64
        with open('14.2.test') as f:
            self.parse(f.read())
        assert self.quantumMask() == 208

    def parse(self, r: str):
        lines = r.split('\n')
        self.lines = list()
        for line in lines:
            key, val = line.split(' = ')
            self.lines.append((key, val))

    def bitMask(self) -> int:
        zero, one = 0, 0
        ans: Dict[int, int] = dict()
        for key, val in self.lines:
            if key == "mask":
                zero, one = self.parseBitmask(val)
            else:
                idx = self.parseMem(key)
                ans[idx] = self.maskValue(zero, one, int(val))
        sum_changed = sum(ans.values())
        return sum_changed

    def parseMem(self, key):
        return int(key[4:-1])

    def parseBitmask(self, val: str) -> Tuple[int, int]:
        zero, one = 0, 0
        for cur, ch in enumerate(reversed(val)):
            if ch == 'X':
                continue
            elif ch == '1':
                one |= (1 << cur)
            elif ch == '0':
                zero |= (1 << cur)
        return zero, one

    def maskValue(self, zero: int, one: int, val: int) -> int:
        return (val | one) & (~zero)

    def quantumMask(self) -> int:
        ecks, one = 0, 0
        ans: Dict[int, int] = dict()
        for key, val in self.lines:
            if key == "mask":
                ecks, one = self.parseQuatumMask(val)
            else:
                addr = self.parseMem(key)
                addr_without_ecks = self.maskValue(ecks, one, addr)
                idxs = self.quantumIter(ecks, addr_without_ecks)
                for idx in idxs:
                    ans[idx] = int(val)
        sum_changed = sum(ans.values())
        return sum_changed

    def parseQuatumMask(self, val: str) -> Tuple[int, int]:
        ecks, one = 0, 0
        for cur, ch in enumerate(reversed(val)):
            if ch == '0':
                continue
            elif ch == '1':
                one |= (1 << cur)
            elif ch == 'X':
                ecks |= (1 << cur)
        return ecks, one

    def popCount(self, val: int) -> int:
        noOnes = 0
        while val:
            val -= val & (-val)
            noOnes += 1
        return noOnes

    def quantumSum(self, ecks: int, val: int) -> int:
        """
        IMPLEMENTED DUE TO MISUNDERSTANDING OF QUESTION AS MULTIPLE VALUES

        eg X10X
        noEcks = 2, since 2 'X'
        n = array size = 2 ^ noEcks
        each 'X' will occur in exactly half of the combinations, ie n / 2
        X10X = n * 0100 + X00X
        = n * 0100 + n/2 * X00X
        """
        onlyOnes = val & (~ecks)
        noEcks = self.popCount(ecks)
        return (onlyOnes << noEcks) + (ecks << (noEcks - 1))

    def quantumIter(self, ecks: int, addr: int) -> Generator[int, None, None]:
        if ecks == 0:
            return
        lsone = ecks & (-ecks)
        ecks -= lsone
        yield addr
        yield from self.quantumIter(ecks, addr)
        addr |= lsone
        yield addr
        yield from self.quantumIter(ecks, addr)


s = Solution("14.in", True)
print(s.bitMask())
print(s.quantumMask())
