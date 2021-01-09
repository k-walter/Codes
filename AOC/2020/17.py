from typing import Tuple, Set, Generator, Callable


class Solution:
    def __init__(self, fname: str, test: bool):
        # Can be sped up with bounded array size
        # due to cache locality
        self.fname: str = fname
        self.active: Set[Tuple[int, ...]] = set()
        self.get_neighbors: Callable[[Tuple[int, ...], bool], Generator[Tuple[int, ...], None, None]]
        if test:
            self.test()

    def parse(self) -> None:
        with open(self.fname) as f:
            r = f.read()
        self.active = set()
        rows = r.split('\n')
        for y, row in enumerate(rows):
            for x, ch in enumerate(row):
                if ch == '#':
                    coord = (x, y, 0, 0)
                    self.active.add(coord)

    def test(self) -> None:
        original_fname = self.fname
        self.fname = '17.test'
        assert self.cycle3d() == 112
        assert self.cycle4d() == 848
        self.fname = original_fname

    def cycle3d(self) -> int:
        self.parse()
        self.get_neighbors = self.neighbors3d
        return self.cycle()

    def cycle4d(self) -> int:
        self.parse()
        self.get_neighbors = self.neighbors4d
        return self.cycle()

    def cycle(self) -> int:
        for _ in range(6):
            newActives: Set[Tuple[int, ...]] = set()
            for coord in self.active:
                neighbors = tuple(self.get_neighbors(coord, True))
                staysActive = 2 <= len(neighbors) <= 3
                if staysActive:
                    newActives.add(coord)
            inactiveNeighbors = set(self.getInactive())
            for coord in inactiveNeighbors:
                neighbors = tuple(self.get_neighbors(coord, True))
                becomesActive = len(neighbors) == 3
                if becomesActive:
                    newActives.add(coord)
            self.active = newActives
        return len(self.active)

    def neighbors4d(self, xyzw: Tuple[int, ...], keep_active: bool) -> Generator[Tuple[int, ...], None, None]:
        xx, yy, zz, ww = xyzw
        for w in range(ww - 1, ww + 2):
            for x in range(xx - 1, xx + 2):
                for y in range(yy - 1, yy + 2):
                    for z in range(zz - 1, zz + 2):
                        coord = (x, y, z, w)
                        isSameCoord = coord == xyzw
                        if isSameCoord:
                            continue
                        shouldKeep = keep_active == (coord in self.active)
                        if shouldKeep:
                            yield coord

    def neighbors3d(self, xyz: Tuple[int, ...], keep_active: bool) -> Generator[Tuple[int, ...], None, None]:
        xx, yy, zz, w = xyz
        for x in range(xx - 1, xx + 2):
            for y in range(yy - 1, yy + 2):
                for z in range(zz - 1, zz + 2):
                    coord = (x, y, z, w)
                    isSameCoord = coord == xyz
                    if isSameCoord:
                        continue
                    shouldKeep = keep_active == (coord in self.active)
                    if shouldKeep:
                        yield coord

    def getInactive(self) -> Generator[Tuple[int, ...], None, None]:
        for active in self.active:
            yield from self.get_neighbors(active, False)


s = Solution("17.in", True)
print(s.cycle3d())
print(s.cycle4d())
