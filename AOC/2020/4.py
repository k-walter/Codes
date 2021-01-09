from typing import List, Set
import re


def countValid(arr: List[str]) -> int:
    ans: int = 0
    for p in arr:
        fields: List[str] = p.split()
        requiredKeys: Set[str] = {'byr', 'iyr',
                                  'eyr', 'hgt', 'hcl', 'ecl', 'pid', }
        for f in fields:
            key, val = f.split(':')
            if checkKey(key, val):
                requiredKeys.discard(key)
        ans += len(requiredKeys) == 0
    return ans


def checkKey(key: str, val: str) -> bool:
    isLen4 = len(val) == 4
    isNumeric = val.isnumeric()
    if key == 'byr':
        withinRange = 1920 <= int(val) <= 2002
        return all((isLen4, isNumeric, withinRange))
    if key == 'iyr':
        withinRange = 2010 <= int(val) <= 2020
        return all((isLen4, isNumeric, withinRange))
    if key == 'eyr':
        withinRange = 2020 <= int(val) <= 2030
        return all((isLen4, isNumeric, withinRange))

    if key == 'hgt':
        no, unit = val[:-2], val[-2:]
        isNumeric = no.isnumeric()
        if not isNumeric:
            return False
        isCm = unit == 'cm' and 150 <= int(no) <= 193
        isIn = unit == 'in' and 59 <= int(no) <= 76
        return any((isCm, isIn))

    if key == 'hcl':
        res = re.match(r'^#[0-9a-f]{6}$', val)
        return not not res

    if key == 'ecl':
        return val in {'amb', 'blu', 'brn', 'gry', 'grn', 'hzl', 'oth'}

    if key == 'pid':
        isLen9 = len(val) == 9
        return all((isNumeric, isLen9))

    return False


with open("4.in") as f:
    passports = f.read().split('\n\n')
    print(countValid(passports))
