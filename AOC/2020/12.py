from typing import List, Tuple


class Solution:
    def __init__(self, fname: str):
        self.test()
        with open(fname) as f:
            self.parse(f.read())
        print(self.shipOnly())
        print(self.shipNWaypt())

    def parse(self, r: str):
        lines: List[str] = r.split()
        self.moves: List[Tuple[str, int]] = [(i[0], int(i[1:])) for i in lines]

    def shipNWaypt(self) -> int:
        pos: complex = 0 + 0j
        wpt: complex = 10 - 1j
        for ch, amt in self.moves:
            mv: complex = self.move(ch, amt)
            if ch == 'F':
                pos += mv * wpt
            elif ch in {'N', 'E', 'W', 'S'}:
                wpt += mv
            elif ch == 'R':
                wpt *= mv
            elif ch == 'L':
                wpt /= mv
        return self.manhatDist(pos)

    def shipOnly(self) -> int:
        pos: complex = 0 + 0j
        d: complex = 1 + 0j
        for ch, amt in self.moves:
            mv: complex = self.move(ch, amt)
            if ch == 'F':
                pos += mv * d
            elif ch in {'N', 'E', 'W', 'S'}:
                pos += mv
            elif ch == 'R':
                d *= mv
            elif ch == 'L':
                d /= mv
        return self.manhatDist(pos)

    def move(self, ch: str, amt: int) -> complex:
        if ch == 'N':
            return -1j * amt
        elif ch == 'S':
            return 1j * amt
        elif ch == 'E':
            return amt
        elif ch == 'W':
            return -amt
        elif ch in {'R', 'L'}:
            # division causes float inaccuries
            return 1j ** (amt // 90)
        elif ch == 'F':
            return amt
        raise Exception("invalid action")

    def manhatDist(self, i: complex) -> int:
        return int(abs(i.real) + abs(i.imag))

    def test(self):
        with open('12.test') as f:
            self.parse(f.read())
        assert self.shipOnly() == 17 + 8
        assert self.shipNWaypt() == 214 + 72
        with open('12.2.test') as f:
            self.parse(f.read())
        assert self.shipOnly() == 11 + 1
        assert self.shipNWaypt() == 0


s = Solution('12.in')
