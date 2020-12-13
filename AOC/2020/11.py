from typing import List, Tuple, TypeVar, Generator

T = TypeVar('T')


class Solution:
    def __init__(self, fname: str):
        self.pt1: bool
        self.test()
        with open(fname) as f:
            r = f.read()
            self.pt1 = True
            self.parseInput(r)
            print(self.sim())
            self.pt1 = False
            self.parseInput(r)
            print(self.sim())

    def create2D(self, n: int, m: int, val: T) -> List[List[T]]:
        arr = [[val] * m for r in range(n)]
        return arr

    def sim(self) -> int:
        initialAmt: int = len(self.AL)
        self.q: List[int] = list(range(initialAmt))
        self.rnd: int = 0
        self.use: List[int] = [self.rnd] * initialAmt
        while len(self.q):
            self.rnd += 1
            changing = list(self.getChanging())
            self.q.clear()
            for u in changing:
                self.flip(u)
                self.addNeighbor(u)
        noOcc: int = sum(self.occ)
        return noOcc

    def flip(self, u: int):
        self.occ[u] ^= True

    def addNeighbor(self, u: int):
        dd: int = 1 if self.occ[u] else -1
        for v in self.AL[u]:
            self.deg[v] += dd
            isAdded: bool = self.use[v] == self.rnd
            if isAdded:
                continue
            self.use[v] = self.rnd
            self.q.append(v)

    def getChanging(self) -> Generator[int, None, None]:
        for i in self.q:
            if self.occ[i]:
                comp: int = 4 if self.pt1 else 5
                if self.deg[i] >= comp:
                    yield i
            else:
                if self.deg[i] == 0:
                    yield i

    def mapStrToInt(self, lines: str) -> Tuple[int, List[List[int]]]:
        lineL = lines.split()
        n: int = len(lineL)
        m: int = len(lineL[0])
        grid: List[List[int]] = self.create2D(n, m, -1)
        no: int = 0
        for y, line in enumerate(lineL):
            for x, ch in enumerate(line):
                if ch != '.':
                    grid[y][x] = no
                    no += 1
        return no, grid

    def initLTR(self, grid: List[List[int]]):
        for row in grid:
            prv: int = -1
            for cur in row:
                prv = self.initAdj(cur, prv)

    def initUTD(self, grid: List[List[int]]):
        for col in zip(*grid):
            prv: int = -1
            for cur in col:
                prv = self.initAdj(cur, prv)

    def iterDiagRight(self, grid: List[List[int]]) -> Generator[List[Tuple[int, int]], None, None]:
        n: int = len(grid)
        m: int = len(grid[0])

        def iterDiag(i: int):
            y: int = max(0, i)
            x: int = max(0, -i)
            while x < m and y < n:
                yield (y, x)
                y += 1
                x += 1
        for i in range(1 - m, n):
            yield list(iterDiag(i))

    def iterDiagLeft(self, grid: List[List[int]]) -> Generator[List[Tuple[int, int]], None, None]:
        n: int = len(grid)
        m: int = len(grid[0])

        def iterDiag(i: int):
            y: int = max(0, i)
            x: int = min(m - 1, m - 1 + i)
            while y < n and x >= 0:
                yield (y, x)
                y += 1
                x -= 1
        for i in range(1 - m, n):
            yield list(iterDiag(i))

    def initDiagRight(self, grid: List[List[int]]):
        for diag in self.iterDiagRight(grid):
            prv: int = -1
            for y, x in diag:
                cur: int = grid[y][x]
                prv = self.initAdj(cur, prv)

    def initDiagLeft(self, grid: List[List[int]]):
        for diag in self.iterDiagLeft(grid):
            prv: int = -1
            for y, x in diag:
                cur: int = grid[y][x]
                prv = self.initAdj(cur, prv)

    def initAdj(self, cur: int, prv: int) -> int:
        if cur == -1:
            return cur if self.pt1 else prv
        if prv != -1:
            self.AL[prv].append(cur)
            self.AL[cur].append(prv)
        return cur

    def parseInput(self, lines: str):
        noSeats, grid = self.mapStrToInt(lines)
        self.occ: List[bool] = [False] * noSeats
        self.deg: List[int] = [0] * noSeats
        self.AL: List[List[int]] = [[] for _ in range(noSeats)]
        self.initLTR(grid)
        self.initUTD(grid)
        self.initDiagLeft(grid)
        self.initDiagRight(grid)

    def test(self):
        """
        00  01
        10  11
        20  21

        -1  01
        0   00  11
        1   10  21
        2   20

        -1  00
        0   01  10
        1   11  20
        2   21

        00  01  02
        10  11  12

        -2  02
        -1  01  12
        0   00  11
        1   10

        -2  00
        -1  01  10
        0   02  11
        1   12
        """
        hor = [[None] * 3] * 2
        ver = [[None] * 2] * 3
        horRight = [[(0, 2)], [(0, 1), (1, 2)], [(0, 0), (1, 1)], [(1, 0)]]
        assert list(self.iterDiagRight(hor)) == horRight
        verRight = [[(0, 1)], [(0, 0), (1, 1)], [(1, 0), (2, 1)], [(2, 0)]]
        assert list(self.iterDiagRight(ver)) == verRight
        horLeft = [[(0, 0)], [(0, 1), (1, 0)], [(0, 2), (1, 1)], [(1, 2)]]
        assert list(self.iterDiagLeft(hor)) == horLeft
        verLeft = [[(0, 0)], [(0, 1), (1, 0)], [(1, 1), (2, 0)], [(2, 1)]]
        assert list(self.iterDiagLeft(ver)) == verLeft
        with open('11.test') as f:
            r = f.read()
            self.pt1 = True
            self.parseInput(r)
            assert self.sim() == 37
            self.pt1 = False
            self.parseInput(r)
            assert self.sim() == 26


s = Solution('11.in')
