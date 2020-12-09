from typing import List, Set, Deque
from collections import defaultdict, deque


class Solution:
    def __init__(self, fname):
        self.win: Deque[int]
        self.vis: Set[int]
        self.test()
        with open(fname) as f:
            self.parseInput(f.read())
        print(self.findAnomaly(25))
        print(self.findWeakness(25))

    def parseInput(self, lines: str):
        line: List[str] = lines.split('\n')
        self.arr: List[int] = list(map(int, line))

    def findAnomaly(self, winSize: int) -> int:
        self.win = deque(maxlen=winSize)
        self.vis = set()
        for no in self.arr:
            # start
            isNew = len(self.win) < winSize
            if isNew:
                self.pushWin(no)
                continue
            # check valid
            for i in self.win:
                complement: int = no - i
                hasComp: bool = complement in self.vis
                diffVal: bool = complement != i
                if hasComp and diffVal:
                    break
            else:
                return no
            # add cur
            self.popWin()
            self.pushWin(no)
        raise Exception('no violation found')

    def findWeakness(self, winSize: int) -> int:
        tot: int = self.findAnomaly(winSize)
        self.win = deque()
        for no in self.arr:
            tot -= no
            self.win.append(no)
            while tot < 0:
                tot += self.win.popleft()
            if tot == 0:
                break
        else:
            raise Exception('contiguous window not found')
        minNo: int = min(self.win)
        maxNo: int = max(self.win)
        return maxNo + minNo


    def pushWin(self, no):
        self.win.append(no)
        self.vis.add(no)

    def popWin(self):
        out: int = self.win.popleft()
        self.vis.remove(out)

    def test(self):
        with open('9.test') as f:
            self.parseInput(f.read())
        assert self.findAnomaly(5) == 127, (self.win, self.vis)
        assert self.findWeakness(5) == 62, (self.win, self.vis)


s = Solution('9.in')
