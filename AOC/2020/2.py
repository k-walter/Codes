def checkBound(line: str) -> bool:
    bound, char, pwd = line.split()
    lo, hi = map(int, bound.split("-"))
    ch: str = char[0]
    cnt: int = 0
    for c in pwd:
        if c == ch:
            cnt += 1
    return lo <= cnt <= hi


def checkPos(line: str) -> bool:
    bound, char, pwd = line.split()
    l, r = map(int, bound.split("-"))
    ch: str = char[0]
    validLeft: bool = pwd[l - 1] == ch
    validRight: bool = pwd[r - 1] == ch
    return validRight + validLeft == 1


with open('2.in') as f:
    ans: int = 0
    for line in f:
        ans += checkBound(line)
    print(ans)
