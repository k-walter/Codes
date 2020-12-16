from typing import Dict


class Solution:
    def __init__(self, test: bool = False):
        self.start: List[int] = list()
        if test:
            self.test()
        self.parse('1,0,16,5,17,4')

    def test(self):
        self.parse('0,3,6')
        assert self.solve(4) == 0
        assert self.solve(5) == 3
        assert self.solve(6) == 3
        assert self.solve(7) == 1
        assert self.solve(8) == 0
        assert self.solve(9) == 4
        assert self.solve(10) == 0
        assert self.solve() == 436
        assert self.solve(30000000) == 175594
        self.parse('1,3,2')
        assert self.solve() == 1
        assert self.solve(30000000) == 2578
        self.parse('2,1,3')
        assert self.solve() == 10
        assert self.solve(30000000) == 3544142
        self.parse('1,2,3')
        assert self.solve() == 27
        assert self.solve(30000000) == 261214
        self.parse('2,3,1')
        assert self.solve() == 78
        assert self.solve(30000000) == 6895259
        self.parse('3,2,1')
        assert self.solve() == 438
        assert self.solve(30000000) == 18
        self.parse('3,1,2')
        assert self.solve() == 1836
        assert self.solve(30000000) == 362

    def parse(self, param: str):
        nos = map(int, param.split(','))
        self.start = list(nos)

    def solve(self, end: int = 2020) -> int:
        turn: int = 1
        spoken: Dict[int, int] = dict()
        for no in self.start[:-1]:
            spoken[no] = turn
            turn += 1
        cur: int = self.start[-1]
        while turn < end:
            if cur not in spoken:
                spoken[cur], cur = turn, 0
            else:
                # some weird bug with reversed order
                # and lazy evaluating dictionaries
                spoken[cur], cur = (turn, turn - spoken[cur])
            turn += 1
        return cur


s = Solution(True)
print(s.solve())
print(s.solve(30000000))
