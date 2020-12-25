from functools import lru_cache
from typing import Tuple, Final


class Solution:
    def __init__(self, public_keys: Tuple[int, int], test: bool = False):
        self.public_keys: Tuple[int, int]
        self.MOD: Final[int] = 20201227
        self.BASE: Final[int] = 7
        if test:
            self.test()
        self.public_keys = public_keys

    def test(self) -> None:
        self.public_keys = (5764801, 17807724)
        assert self.crack() == 14897079

    def crack(self) -> int:
        card, door = self.public_keys
        card_round = self.findRound(card)
        encryption_key = self.pow(door, card_round)
        return encryption_key

    def findRound(self, public: int) -> int:
        round: int = 1
        while self.pow(self.BASE, round) != public:
            round += 1
        return round

    @lru_cache(maxsize=None)
    def pow(self, base, exp) -> int:
        if exp == 1:
            return base % self.MOD
        half = self.pow(base, (exp >> 1))
        ans = half * half
        is_odd = exp & 1
        if is_odd:
            ans *= base
        return ans % self.MOD


public_keys = (14222596, 4057428)
s = Solution(public_keys, True)
print(s.crack())
