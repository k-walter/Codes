from typing import List, Dict
from collections import defaultdict, deque


class Solution:
    def __init__(self, fname):
        self.test()
        with open(fname) as f:
            self.parse(f.read())
        print(self.mult1and3())
        print(self.dp())

    def parse(self, lines: str):
        self.adaps: List[int] = list(map(int, lines.split()))
        self.adaps.append(0)
        self.adaps.sort()

    def mult1and3(self) -> int:
        diff: Dict[int, int] = defaultdict(int)
        for i, j in zip(self.adaps, self.adaps[1:]):
            diff[j - i] += 1
        no1: int = diff[1]
        no3: int = diff[3] + 1
        return no1 * no3

    def dp(self) -> int:
        last: int = self.adaps[-1] + 3
        q = deque([(last, 1)], maxlen=3)
        for i in reversed(self.adaps):
            while len(q) and i + 3 < q[-1][0]:
                q.pop()
            tot: int = sum(j[1] for j in q)
            q.appendleft((i, tot))
        noPaths: int = q[0][1]
        return noPaths

    def test(self):
        with open('10.1.test') as f:
            self.parse(f.read())
            assert self.mult1and3() == 7 * 5
            assert self.dp() == 8
        with open('10.2.test') as f:
            self.parse(f.read())
            assert self.mult1and3() == 22 * 10
            assert self.dp() == 19208


s = Solution('10.in')
