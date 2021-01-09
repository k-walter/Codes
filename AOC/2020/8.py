from typing import List, Tuple

NEW: int
BAD: int
OK: int
NEW, BAD, OK = range(3)


class Solution:
    def __init__(self, fname):
        self.vis: List[int]
        self.test()
        with open(fname) as f:
            self.lines: List[str] = f.read().split('\n')
            print(self.getAccum())
            print(self.changeOne())

    def getAccum(self) -> int:
        vis: List[bool] = [False] * len(self.lines)
        cur: int = 0
        acc: int = 0
        axn: str
        amt: int
        while not vis[cur]:
            vis[cur] = True
            axn, amt = self.parseLine(cur)
            if axn == 'acc':
                acc += amt
            cur += self._parseAction(axn, amt)
        return acc

    def changeOne(self) -> int:
        n: int = len(self.lines)
        self.vis = [NEW] * n
        cur: int = 0
        acc: int = 0
        axn: str
        amtS: str
        while cur < n:
            axn, amt = self.parseLine(cur)
            if axn == 'acc':
                acc += amt

            if self.vis[cur] != OK:
                self.vis[cur] = BAD
                if axn == 'jmp':
                    if self.dfs(cur + 1) == OK:
                        axn = 'nop'
                elif axn == 'nop':
                    isSelfLoop = amt == 0
                    if not isSelfLoop and self.dfs(cur + amt) == OK:
                        axn = 'jmp'

            cur += self._parseAction(axn, amt)
        return acc

    def dfs(self, cur: int) -> int:
        isOk = cur >= len(self.vis)
        if isOk:
            return OK
        if self.vis[cur] != NEW:
            return self.vis[cur]
        self.vis[cur] = BAD
        nex: int = cur + self.parseAction(cur)
        self.vis[cur] = self.dfs(nex)
        return self.vis[cur]

    def parseLine(self, cur: int) -> Tuple[str, int]:
        axn: str
        amtS: str
        axn, amtS = self.lines[cur].split(' ')
        return axn, int(amtS)

    def parseAction(self, cur: int) -> int:
        axn, amt = self.parseLine(cur)
        return self._parseAction(axn, amt)

    def _parseAction(self, axn: str, val: int) -> int:
        if axn == 'jmp':
            return val
        return 1

    def test(self):
        with open('8.1.test') as f:
            self.lines: List[str] = f.read().split('\n')
            assert self.getAccum() == 5
            assert self.changeOne() == 8


s = Solution('8.in')
