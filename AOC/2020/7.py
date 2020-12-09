from typing import List, Tuple, Dict, Set
from collections import defaultdict


class Solution:
    def __init__(self, fname: str):
        with open(fname) as f:
            self.bags: List[str] = f.read().split('\n')
        print(self.cntBags())

    def cntBags(self) -> int:
        self.createAL()
        target: str = 'shiny gold'
        amtBags: int = self.dfs(target) - 1
        return amtBags

    def createAL(self):
        self.AL: Dict[str, List[str]] = defaultdict(list)
        for bag in self.bags:
            src, dsts = self.parseBag(bag)
            noDests: bool = dsts == 'no other bags.'
            if noDests:
                continue
            for dst in self.parseDst(dsts):
                self.AL[dst].append(src)

    def parseBag(self, bag: str) -> Tuple[str, str]:
        src: str
        dsts: str
        delim: str = ' bags contain '
        src, dsts = bag.split(delim)
        return src, dsts

    def parseDst(self, dsts: str) -> List[str]:
        dstsList: List[str] = dsts[:-1].split(', ')
        names: List[str] = list()
        for dst in dstsList:
            dstList: List[str] = dst.split(' ')
            name: str = f"{dstList[1]} {dstList[2]}"
            names.append(name)
        return names

    def dfs(self, src: str) -> int:
        self.vis: Set[str] = set()
        self._dfs(src)
        ccSize: int = len(self.vis)
        return ccSize

    def _dfs(self, cur: str):
        self.vis.add(cur)
        for nex in self.AL[cur]:
            if nex not in self.vis:
                self._dfs(nex)


class Solution1(Solution):
    def __init__(self, fname: str):
        self.test()
        super().__init__(fname)

    def test(self):
        with open('7.test') as f:
            self.bags: List[str] = f.read().split('\n')
        assert self.cntBags() == 4, (self.vis, self.AL)


class Solution2(Solution):
    def __init__(self, fname: str):
        self.test()
        super().__init__(fname)

    def createAL(self):
        self.AL: Dict[str, List[Tuple[str, int]]] = defaultdict(list)
        for bag in self.bags:
            src, dsts = self.parseBag(bag)
            noDests: bool = dsts == 'no other bags.'
            if noDests:
                continue
            for dst in self.parseDst(dsts):
                self.AL[src].append(dst)

    def parseDst(self, dsts: str) -> List[Tuple[str, int]]:
        dstsList: List[str] = dsts[:-1].split(', ')
        names: List[Tuple[str, int]] = list()
        for dst in dstsList:
            dstList: List[str] = dst.split(' ')
            amt: int = int(dstList[0])
            name: str = f"{dstList[1]} {dstList[2]}"
            names.append((name, amt))
        return names

    def dfs(self, src: str) -> int:
        self.vis: Dict[str, int] = defaultdict(int)
        ans: int = self._dfs(src)
        return ans

    def _dfs(self, cur: str) -> int:
        if cur in self.vis:
            return self.vis[cur]
        self.vis[cur] = 1
        for nex, hz in self.AL[cur]:
            self.vis[cur] += hz * self._dfs(nex)
        return self.vis[cur]

    def test(self):
        with open('7.2.test') as f:
            self.bags: List[str] = f.read().split('\n')
        assert self.cntBags() == 126, (self.vis, self.AL)


s = Solution1('7.in')
s = Solution2('7.in')
