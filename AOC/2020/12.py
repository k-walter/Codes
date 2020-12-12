from typing import List, Tuple

E, S, W, N = range(4)
dyx = ((0, 1), (1, 0), (0, -1), (-1, 0))


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

    def initDirection(self):
        self.wy: int = -1
        self.wx: int = 10
        self.d: int = E

    def rotateCWtoEast(self) -> int:
        if self.d == E:
            return 0
        d: int = self.d
        self.d = E
        if d == S:
            "3,1 --> -1,3"
            self.wy, self.wx = -self.wx, self.wy
            return 90
        if d == W:
            "1,-3 --> -1,3"
            self.wy, self.wx = -self.wy, -self.wx
            return 180
        if d == N:
            "-3,1 --> 1,3"
            self.wy, self.wx = self.wx, -self.wy
            return 270
        raise Exception('Direction not found')

    def rotateCWfromEast(self):
        assert 0 <= self.d < 4
        if self.d == E:
            return
        if self.d == S:
            "3,1 <-- -1,3"
            self.wy, self.wx = self.wx, -self.wy
        elif self.d == W:
            "1,-3 <-- -1,3"
            self.wy, self.wx = -self.wy, -self.wx
        elif self.d == N:
            "-3,1 <-- 1,3"
            self.wy, self.wx = -self.wx, self.wy

    def shipNWaypt(self):
        y: int = 0
        x: int = 0
        dy: int
        dx: int
        self.initDirection()
        for ch, amt in self.moves:
            if ch in {'R', 'L'}:
                isCW: int = 1 if 'R' else -1
                adjAmt: int = amt + self.rotateCWtoEast() * isCW
                self.rotateDir(ch, adjAmt)
                self.rotateCWfromEast()
            elif ch in {'N', 'E', 'W', 'S'}:
                dy, dx = self.move(ch, amt)
                self.wy += dy
                self.wx += dx
            elif ch == 'F':
                dy, dx = self.wy * amt, self.wx * amt
                y += dy
                x += dx
            # print(f"{ch}{amt:<5}(x,y) = ({x},{y}),\tdir = {self.d},\t(wx,wy) = ({self.wx},{self.wy})")
        return self.manhatDist(y, x)

    def manhatDist(self, y: int, x: int) -> int:
        return abs(y) + abs(x)

    def shipOnly(self):
        y: int = 0
        x: int = 0
        self.initDirection()
        for ch, amt in self.moves:
            if ch in {'R', 'L'}:
                self.rotateDir(ch, amt)
            elif ch in {'N', 'E', 'W', 'S', 'F'}:
                dy, dx = self.move(ch, amt)
                y += dy
                x += dx
        return self.manhatDist(y, x)

    def rotateDir(self, ch: str, amt: int):
        assert ch in {'R', 'L'}
        turn: int = int(amt / 90)
        if ch == 'R':
            self.d += turn
        elif ch == 'L':
            self.d -= turn
        self.d %= 4

    def move(self, ch: str, amt: int) -> Tuple[int, int]:
        assert ch not in {'R', 'L'}
        dy: int = 0
        dx: int = 0
        if ch == 'N':
            dy, dx = dyx[N]
        elif ch == 'S':
            dy, dx = dyx[S]
        elif ch == 'E':
            dy, dx = dyx[E]
        elif ch == 'W':
            dy, dx = dyx[W]
        elif ch == 'F':
            dy, dx = dyx[self.d]
        return dy * amt, dx * amt

    def test(self):
        with open('12.test') as f:
            self.parse(f.read())
        assert self.shipOnly() == 17 + 8
        assert self.shipNWaypt() == 214 + 72
        with open('12.2.test') as f:
            self.parse(f.read())
        assert self.shipNWaypt() == 0

s = Solution('12.in')
