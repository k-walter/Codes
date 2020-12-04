from typing import List


def checkSlope(grid: List[str], right: int, down: int) -> int:
    col: int = 0
    ans: int = 0
    for row in grid[::down]:
        x = col % len(row)
        isTree: bool = row[x] == '#'
        ans += isTree
        col += right
    return ans


def checkSlopes(grid: List[str]) -> int:
    slopes = [(1, 1), (3, 1), (5, 1), (7, 1), (1, 2)]
    ans: int = 1
    for right, down in slopes:
        ans *= checkSlope(grid, right, down)
    return ans


with open('3.in') as f:
    grid = f.read().split('\n')
    print(checkSlopes(grid))
