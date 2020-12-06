from typing import List


def binSearch(val: str, trueS: str) -> int:
    ans: int = 0
    for ch in val:
        ans <<= 1
        ans |= (ch == trueS)
    return ans


def getCol(bp: str) -> int:
    colS: str = bp[7:]
    rightHalf = 'R'
    c: int = binSearch(colS, rightHalf)
    return c


def getRow(bp: str) -> int:
    rowS: str = bp[:7]
    upperHalf = 'B'
    r: int = binSearch(rowS, upperHalf)
    return r


def getSID(row: int, col: int) -> int:
    return (row << 3) + col


def getPID(bp: str) -> int:
    row: int = getRow(bp)
    col: int = getCol(bp)
    sid: int = getSID(row, col)
    return sid


def getMaxPass(bps: List[str]) -> int:
    pids = map(getPID, bps)
    return max(pids)


def getMissingPass(bps: List[str]) -> int:
    pids = map(getPID, bps)
    pidsSorted = sorted(pids)
    for i, j in zip(pidsSorted, pidsSorted[1:]):
        isAdjSeat: bool = i + 2 == j
        if isAdjSeat:
            sid: int = i + 1
            return sid
    raise Exception('Seat in front or back')


assert binSearch('FBFBBFF', 'B') == 44
assert getPID('BFFFBBFRRR') == 567, getPID('BFFFBBFRRR')

with open('5.in') as f:
    bps: List[str] = f.read().split()
    print(getMaxPass(bps))
    print(getMissingPass(bps))
