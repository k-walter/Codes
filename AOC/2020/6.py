from typing import List, Set, Dict, Iterable, Callable
from collections import Counter


class Solution:
    def __init__(self, fname):
        with open(fname) as f:
            self.grps: List[str] = f.read().split('\n\n')
        self.test()
        print(self.sumGroups(self.unionGroup))
        print(self.sumGroups(self.intersectGroup))

    def sumGroups(self, method: Callable[[str], int]) -> int:
        grpSums: Iterable[int] = map(method, self.grps)
        return sum(grpSums)

    def intersectGroup(self, grp: str) -> int:
        cnt: Dict[str, int] = Counter(grp)
        noPax: int = cnt.get('\n', 0) + 1
        intersectQns: List[str] = [qn for qn, hz in cnt.items() if hz == noPax]
        return len(intersectQns)

    def unionGroup(self, grp: str) -> int:
        qns: Set[str] = {c for c in grp if c.isalpha()}
        return len(qns)

    def test(self):
        assert self.intersectGroup('abc') == 3
        assert self.intersectGroup('ab\nac') == 1


s = Solution('6.in')
