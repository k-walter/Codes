from typing import List, Tuple, Deque, TypeVar, Generator
from collections import deque

T = TypeVar('T')


class Solution:
    def __init__(self, fname: str):
        self.my = (-1, -1, -1, 0, 0, 1, 1, 1)
        self.mx = (-1, 0, 1, -1, 1, -1, 0, 1)
        self.grid: List[List[str]]
        self.test()
        with open(fname) as f:
            self.parseInput(f.read())
        print(self.sim())

    def create2D(self, val: T) -> List[List[T]]:
        arr = [[val] * self.m for r in range(self.n)]
        return arr

    def createDeque(self) -> Deque[Tuple[int, int]]:
        q: Deque[Tuple[int, int]] = deque()
        for y, line in enumerate(self.grid):
            for x, ch in enumerate(line):
                if ch == '.':
                    continue
                q.append((y, x))
        return q

    def sim(self) -> int:
        q = self.createDeque()
        rnd: int = 0
        use = self.create2D(rnd)
        grid: Tuple[List[List[str]], ...] = (self.grid, self.create2D(''))
        curr: bool = False
        noOcc: int = 0
        while len(q):
            V: int = len(q)
            rnd += 1
            for _ in range(V):
                y, x = q.popleft()
                ch = grid[curr][y][x]
                isFloor: bool = ch == '.'
                isEmpty: bool = ch == 'L'
                if isFloor:
                    pass
                elif isEmpty:
                    if self.checkEmpty(grid[curr], y, x):
                        # print(y, x, "flipped")
                        ch = '#'
                        noOcc += 1
                        adj = self.getUnusedAdj(grid[curr], y, x, use, rnd)
                        q.extend(adj)
                else:
                    if self.checkFull(grid[curr], y, x):
                        # print(y, x, "flipped")
                        ch = 'L'
                        noOcc -= 1
                        adj = self.getUnusedAdj(grid[curr], y, x, use, rnd)
                        q.extend(adj)
                grid[not curr][y][x] = ch
            curr = not curr
        return noOcc

    def getUnusedAdj(self, grid: List[List[str]], yy: int, xx: int, use: List[List[int]], rnd: int) -> Generator[Tuple[int, int], None, None]:
        adj = self.getAdj(grid, yy, xx)
        for y, x in adj:
            if use[y][x] != rnd:
                use[y][x] = rnd
                yield (y, x)

    def getAdj(self, grid: List[List[str]], yy: int, xx: int):
        for dy, dx in zip(self.my, self.mx):
            y: int = yy + dy
            x: int = xx + dx
            if any((y < 0, y >= self.n, x < 0, x >= self.m)):
                continue
            if grid[y][x] == '.':
                continue
            yield (y, x)

    def checkFull(self, grid: List[List[str]], yy: int, xx: int) -> bool:
        tot: int = 0
        adjs = self.getAdj(grid, yy, xx)
        for y, x in adjs:
            if grid[y][x] != '#':
                continue
            tot += 1
            if tot >= 4:
                return True
        return False

    def checkEmpty(self, grid: List[List[str]], yy: int, xx: int) -> bool:
        adjs = self.getAdj(grid, yy, xx)
        return all(grid[y][x] != '#' for y, x in adjs)

    def parseInput(self, lines: str):
        self.grid = [list(line) for line in lines.split()]
        self.n: int = len(self.grid)
        self.m: int = len(self.grid[0])

    def test(self):
        with open('11.test') as f:
            self.parseInput(f.read())
        assert self.sim() == 37


s = Solution('11.in')
