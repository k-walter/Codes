from collections import deque
from itertools import chain, islice

from typing import Deque, Tuple, Set, NamedTuple, Optional

DRAW, P1, P2 = range(3)


class GameState(NamedTuple):
    p1: Deque[int]
    p2: Deque[int]
    vis: Optional[Set[Tuple[int, ...]]] = None


class Solution:
    def __init__(self, fname: str, test: bool = False):
        self.p1: Deque[int] = deque()
        self.p2: Deque[int] = deque()
        if test:
            self.test()
        self.fname: str = fname

    def test(self) -> None:
        self.fname = '22.test'
        assert self.iterateCombat() == 306
        assert self.recurseCombat() == 291

    def parse(self) -> None:
        with open(self.fname) as f:
            r = f.read()
        p1, p2 = r.split('\n\n')
        p1_cards = map(int, p1.split('\n')[1:])
        p2_cards = map(int, p2.split('\n')[1:])
        self.p1 = deque(p1_cards)
        self.p2 = deque(p2_cards)

    def iterateCombat(self) -> int:
        self.parse()
        state = GameState(self.p1, self.p2)
        while not self.checkGameOver(state):
            p1, p2 = self.drawCard(state)
            self.iterateRound(p1, p2, state)
        return self.score(state.p1) + self.score(state.p2)

    def drawCard(self, state: GameState) -> Tuple[int, int]:
        p1 = state.p1.popleft()
        p2 = state.p2.popleft()
        return p1, p2

    def iterateRound(self, p1: int, p2: int, state: GameState):
        p1Wins = p1 > p2
        if p1Wins:
            state.p1.extend((p1, p2))
        else:
            state.p2.extend((p2, p1))

    def score(self, arr: Deque[int]) -> int:
        ans = 0
        for i, val in enumerate(reversed(arr), 1):
            ans += i * val
        return ans

    def recurseCombat(self) -> int:
        self.parse()
        state = GameState(self.p1, self.p2, set())
        winner = self.game(state)
        if winner == P1:
            return self.score(state.p1)
        elif winner == P2:
            return self.score(state.p2)
        raise Exception("Nobody won")

    def game(self, state: GameState) -> int:
        # Iterative solution
        while self.checkGameOver(state) == DRAW:
            if self.checkSimilarRound(state):
                return P1
            p1, p2 = self.drawCard(state)
            isRecursive = p1 <= len(state.p1) and p2 <= len(state.p2)
            if isRecursive:
                self.recurseRound(p1, p2, state)
            else:
                self.iterateRound(p1, p2, state)
        return self.checkGameOver(state)

    def recurseRound(self, p1: int, p2: int, state):
        p1_slice = deque(islice(state.p1, p1))
        p2_slice = deque(islice(state.p2, p2))
        p1Wins = self.game(GameState(p1_slice, p2_slice, set())) == P1
        if p1Wins:
            state.p1.extend((p1, p2))
        else:
            state.p2.extend((p2, p1))

    def checkSimilarRound(self, state: GameState) -> bool:
        p1_tuple = tuple(chain((P1,), state.p1))
        p2_tuple = tuple(chain((P2,), state.p2))
        p1_wins = p1_tuple in state.vis or p2_tuple in state.vis
        if p1_wins:
            return True
        state.vis.add(p1_tuple)
        state.vis.add(p2_tuple)
        return False

    def checkGameOver(self, state: GameState) -> int:
        if len(state.p1) == 0:
            return P2
        if len(state.p2) == 0:
            return P1
        return DRAW


s = Solution('22.in', True)
print(s.iterateCombat())
print(s.recurseCombat())
