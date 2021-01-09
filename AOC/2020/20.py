from collections import defaultdict, Counter
from itertools import chain
from math import prod
from typing import List, Dict, Iterable, Tuple, NamedTuple, NewType, Generator

UP, RIGHT, BTM, LEFT = range(4)
Tile = NewType('Tile', List[str])


class TileEdge(NamedTuple):
    up: int
    right: int
    btm: int
    left: int


class EdgeToTile(NamedTuple):
    id: int
    face: int
    angle: int


class Solution:
    def __init__(self, fname: str, test: bool = False):
        self.tiles: Dict[int, Tile] = dict()
        self.monster = ["                  # ", "#    ##    ##    ###", " #  #  #  #  #  #   "]
        if test:
            self.test()
        with open(fname) as f:
            self.parse(f.read())

    def test(self) -> None:
        with open('20.test') as f:
            self.parse(f.read())
        assert self.getSufficientCorners() == 1951 * 3079 * 2971 * 1171
        assert self.countSafe() == 273

    def parse(self, param: str) -> None:
        tiles = param.split('\n\n')
        self.tiles = dict()
        for tile in tiles:
            rows = tile.strip().split('\n')
            no = int(rows[0][5:-1])
            self.tiles[no] = rows[1:]

    def getSufficientCorners(self) -> int:
        """
        Having 2 unique edges for any rotation is sufficient
        to determine that the tile is a corner tile
        """
        edge_dict = self.getTileEdges(self.tiles)
        corners = self.getCorners(edge_dict)
        return prod(corners)

    def getTileEdges(self, tiles: Dict[int, List[str]]) -> Dict[int, Tuple[TileEdge, TileEdge]]:
        edge_dict: Dict[int, Tuple[Tuple[int, ...], Tuple[int, ...]]]
        edge_dict = {no: self.getEdges(t) for no, t in tiles.items()}
        return edge_dict

    def getCorners(self, edge_dict: Dict[int, Tuple[TileEdge, TileEdge]]) -> List[int]:
        edges = Counter(chain.from_iterable(chain.from_iterable(e) for e in edge_dict.values()))
        corners: List[int] = list()
        for no, (e1, e2) in edge_dict.items():
            e1MissingEdges = (1 for e in e1 if edges[e] <= 1)
            e2MissingEdges = (1 for e in e2 if edges[e] <= 1)
            if sum(e1MissingEdges) == 2 and sum(e2MissingEdges) == 2:
                corners.append(no)
        assert len(corners) == 4
        return corners

    def countSafe(self) -> int:
        """
        Assumes monsters don't overlap
        """
        patched_grid = self.greedyAssign()
        grid = list(self.removeBorders(patched_grid))
        monster_variations = (self.monster, self.rotate90(self.monster))
        monster_count = sum(self.countMonsters(grid, m) for m in monster_variations)
        no_hash = self.countHash(grid)
        no_unsafe = self.countHash(self.monster) * monster_count
        return no_hash - no_unsafe

    def greedyAssign(self) -> List[List[Tile]]:
        """
        Test Counter({2: 24, 1: 24})
        Ipput Counter({2: 528, 1: 96})
        Every edge appears at most once --> Greedily assign tile from corner
        """
        edge_dict = self.getTileEdges(self.tiles)
        edge_to_tile = self.createAdjEdgeDict(edge_dict)
        topLeftEdge = self.getTopLeft(edge_dict, edge_to_tile)
        n: int = int(len(self.tiles) ** .5)
        firstRow = self.getFirstRow(edge_to_tile, n, topLeftEdge.left)
        grid: List[List[Tile]] = [list(firstRow)]
        for _ in range(1, n):
            prvRow = grid[-1]
            newRow = self.getNextRow(edge_to_tile, prvRow)
            grid.append(list(newRow))
        return grid

    def getNextRow(self, edge_to_tile: Dict[int, List[EdgeToTile]], prvRow: List[Tile]) -> Generator[Tile, None, None]:
        for tile in prvRow:
            top_edge = self.mapStrToInt(tile[-1])
            candidateTiles = edge_to_tile[top_edge]
            assert len(candidateTiles) == 1, candidateTiles
            newTileEdge = candidateTiles[0]
            newTile = self.faceUp(newTileEdge)
            yield newTile
            # prepare for next tile by removing candidate
            tile_id = newTileEdge.id
            btmEdge = self.mapStrToInt(newTile[-1])
            self.removeTileEdge(edge_to_tile, btmEdge, tile_id)

    def getFirstRow(self, edge_to_tile: Dict[int, List[EdgeToTile]], n: int, left_edge: int) -> Generator[Tile, None, None]:
        for _ in range(n):
            candidateTiles = edge_to_tile[left_edge]
            assert len(candidateTiles) == 1
            newTileEdge = candidateTiles[0]
            newTile = self.faceLeft(newTileEdge)
            yield newTile
            # prepare for next tile by removing candidate
            tile_id = newTileEdge.id
            rightEdge = self.mapStrToInt(row[-1] for row in newTile)
            btmEdge = self.mapStrToInt(newTile[-1])
            self.removeTileEdge(edge_to_tile, rightEdge, tile_id)
            self.removeTileEdge(edge_to_tile, btmEdge, tile_id)
            # prepare new left edge
            left_edge = rightEdge

    def removeTileEdge(self, edge_to_tile: Dict[int, List[EdgeToTile]], edge: int, tile_id: int) -> None:
        candidateTiles = edge_to_tile[edge]
        for i, edgeTile in enumerate(candidateTiles):
            if edgeTile.id == tile_id:
                candidateTiles.pop(i)
                break
        else:
            raise Exception(edge, tile_id)

    def faceLeft(self, tile_edge: EdgeToTile) -> Tile:
        tile = self.tiles[tile_edge.id]
        if tile_edge.face == 0:
            if tile_edge.angle == LEFT:
                return tile
            if tile_edge.angle == RIGHT:
                return self.flipY(tile)
            if tile_edge.angle == BTM:
                return self.rotate90(tile)
            if tile_edge.angle == UP:
                return self.flipY(self.rotate90(tile))
        elif tile_edge.face == 1:
            if tile_edge.angle == LEFT:
                return self.rotate90(self.rotate90(self.flipY(tile)))
            if tile_edge.angle == RIGHT:
                return self.rotate90(self.rotate90(tile))
            if tile_edge.angle == BTM:
                return self.rotate90(self.flipY(tile))
            if tile_edge.angle == UP:
                return self.flipY(self.rotate90(self.flipY(tile)))
        raise Exception("Unable to face left")

    def faceUp(self, tile_edge: EdgeToTile) -> Tile:
        tile = self.tiles[tile_edge.id]
        if tile_edge.face == 0:
            if tile_edge.angle == UP:
                return tile
            if tile_edge.angle == BTM:
                return self.flipY(self.rotate90(self.rotate90(tile)))
            if tile_edge.angle == LEFT:
                return self.flipY(self.rotate90(tile))
            if tile_edge.angle == RIGHT:
                return self.flipY(self.rotate90(self.flipY(tile)))
        elif tile_edge.face == 1:
            if tile_edge.angle == UP:
                return self.flipY(tile)
            if tile_edge.angle == BTM:
                return self.rotate90(self.rotate90(tile))
            if tile_edge.angle == LEFT:
                return self.rotate90(tile)
            if tile_edge.angle == RIGHT:
                return self.rotate90(self.flipY(tile))
        raise Exception("Unable to face up", tile_edge)

    def flipY(self, tile: Tile) -> Tile:
        return [row[::-1] for row in tile]

    def rotate90(self, tile: Tile) -> Tile:
        return list(''.join(r) for r in zip(*reversed(tile)))

    def createAdjEdgeDict(self, edge_dict: Dict[int, Tuple[TileEdge, TileEdge]]):
        edge_to_tile: Dict[int, List[EdgeToTile]] = defaultdict(list)
        for no, E in edge_dict.items():
            for face, Ex in enumerate(E):
                for angle, e in enumerate(Ex):
                    edge_to_tile[e].append(EdgeToTile(no, face, angle))
        return edge_to_tile

    def getTopLeft(self, edge_dict: Dict[int, Tuple[TileEdge, TileEdge]], edge_to_tile: Dict[int, List[EdgeToTile]]) -> TileEdge:
        for corner in self.getCorners(edge_dict):
            edge = edge_dict[corner][0]
            isValid = lambda x: len(edge_to_tile[x]) == 2
            isTopLeft = isValid(edge.right) and isValid(edge.btm)
            if isTopLeft:
                return edge
        raise Exception("Top left corner not found")

    def getEdges(self, tile: List[str]) -> Tuple[TileEdge, TileEdge]:
        top, btm = tile[0], tile[-1]
        left = ''.join(r[0] for r in tile)
        right = ''.join(r[-1] for r in tile)
        cw_edges = (top, right, btm, left)
        edges = TileEdge(*map(self.mapStrToInt, cw_edges))
        reversed_edges = TileEdge(*map(self.mapStrToInt, map(reversed, cw_edges)))
        return edges, reversed_edges

    def mapStrToInt(self, edge: Iterable[str]) -> int:
        ans = 0
        for i, ch in enumerate(edge):
            if ch == '#':
                ans |= (1 << i)
        return ans

    def printGrid(self, grid: List[List[Tile]]):
        for row in grid:
            for tile_row in range(len(row[0])):
                for tile in row:
                    print(tile[tile_row], end='\t')
                print()
            print()

    def removeBorders(self, grid: List[List[Tile]]) -> Generator[str, None, None]:
        for tile_row in grid:
            rows = list(zip(*tile_row))
            for row in rows[1:-1]:
                tiles = (tile[1:-1] for tile in row)
                yield ''.join(tiles)

    def countMonsters(self, grid: List[str], base_monster: List[str]) -> int:
        monsters: Tuple[int, ...] = tuple(self.maskMonsters(base_monster))
        n: int = len(base_monster)
        m: int = len(base_monster[0])
        cnt: int = 0
        for idx in range(0, len(grid)-n+1):
            rows = grid[idx: idx + n]
            mask: int = 0
            for c, col in enumerate(zip(*rows)):
                mask = (mask << n) | self.maskCol(col)
                hasStrided = c >= m
                if hasStrided:
                    mask >>= n
                for m in monsters:
                    isMonster = (mask & m) == m
                    if isMonster:
                        cnt += 1
        return cnt

    def maskMonsters(self, base_monster: List[str]) -> Generator[int, None, None]:
        n: int = len(base_monster)
        for monster in self.flip(base_monster):
            mask: int = 0
            for col in zip(*monster):
                mask = (mask << n) | self.maskCol(col)
            yield mask

    def maskCol(self, col: str):
        mask: int = 0
        for r, ch in enumerate(col):
            if ch == '#':
                mask |= 1 << r
        return mask

    def flip(self, monster: List[str]) -> Generator[List[str], None, None]:
        yield monster
        yield monster[::-1]
        yield self.flipY(monster)
        yield self.flipY(monster[::-1])

    def countHash(self, grid: List[str]) -> int:
        cnt: int = 0
        for row in grid:
            cnt += row.count("#")
        return cnt


s = Solution('20.in', True)
print(s.getSufficientCorners())
print(s.countSafe())
