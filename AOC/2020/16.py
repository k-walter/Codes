from bisect import bisect
from collections import defaultdict
from itertools import chain, zip_longest
from math import prod

from typing import Dict, List, Tuple, Generator, Iterable, Set, Optional


class Solution:
    def __init__(self, fname: str, test: bool = False) -> None:
        self.nearby: List[List[int]] = list()
        self.yours: List[List[int]] = list()
        self.rules: Dict[str, List[Tuple[int, int]]] = defaultdict(list)
        if test:
            self.test()
        with open(fname) as f:
            self.parse(f.read())

    def test(self) -> None:
        with open('16.test') as f:
            self.parse(f.read())
        assert self.sumInvalid() == 4 + 55 + 12

    def parse(self, param: str) -> None:
        rules, yours, nearby = param.split("\n\n")
        self.parseRules(rules)
        self.nearby = list(self.parseTickets(nearby))
        self.yours = list(self.parseTickets(yours))

    def parseTickets(self, tickets: str) -> Generator[List[int], None, None]:
        for ticket in tickets.split('\n')[1:]:
            fields = ticket.split(',')
            fields_list = list(map(int, fields))
            yield fields_list

    def parseRules(self, rules: str) -> None:
        self.rules: Dict[str, List[Tuple[int, int]]] = defaultdict(list)
        for rule in rules.split('\n'):
            name, ranges = rule.split(': ')
            for r in ranges.split(' or '):
                left, right = map(int, r.split('-'))
                self.rules[name].append((left, right))

    def sumInvalid(self) -> int:
        invalidNos = self.getInvalid(self.nearby)
        return sum(invalidNos)

    def mergeRules(self) -> Iterable[Tuple[int, int]]:
        mergedRules = chain.from_iterable(self.rules.values())
        sortedRules = sorted(mergedRules, key=lambda x: (x[0], -x[1]))
        out: List[List[int]] = [list(sortedRules[0])]
        for r in sortedRules[1:]:
            i, j = r
            if out[-1][1] + 1 < i:
                out.append(list(r))
            else:
                out[-1][1] = max(out[-1][1], j)
        return map(tuple, out)

    def getInvalid(self, arr: List[List[int]]) -> Generator[int, None, None]:
        mergedRules = list(self.mergeRules())
        for no in chain.from_iterable(arr):
            isWithinRange = self.checkRange(mergedRules, no)
            if not isWithinRange:
                yield no

    def checkRange(self, rules: List[Tuple[int, int]], no: int) -> bool:
        idx = bisect([i[0] for i in rules], no) - 1
        isRightBound: bool = idx >= 0 and no <= rules[idx][1]
        return isRightBound

    def multiplyDest(self) -> int:
        ourTix = self.yours + self.nearby
        validTix = list(self.getValid(ourTix))
        domains = list(self.getDomain(validTix))
        self.assignDomains(domains)
        yourValidTix = validTix[0]
        destinations = self.getDest(domains, yourValidTix)
        return prod(destinations)

    def getValid(self, arr: List[List[int]]) -> Generator[List[int], None, None]:
        def filterValid(tickets: List[int]) -> Generator[int, None, None]:
            for ticket in tickets:
                if ticket not in invalidNos:
                    yield ticket
                # else:
                #     yield None
        invalidNos = set(self.getInvalid(arr))
        for tickets in arr:
            yield list(filterValid(tickets))

    def getDomain(self, validTix: List[List[int]]) -> Generator[Set[str], None, None]:
        colVals: List[Optional[int]]
        for colVals in zip_longest(*validTix):
            domain: Set[str] = set(self.rules.keys())
            for r, rules in self.rules.items():
                for v in colVals:
                    if v is None:
                        continue
                    isValidCol = self.checkRange(rules, v)
                    if not isValidCol:
                        domain.remove(r)
                        break
            yield domain

    def assignDomains(self, domains: List[Set[str]]) -> None:
        # similar to kahn's algo
        # extension could be backtracking / AC3
        adjList: Dict[str, List[int]] = defaultdict(list)
        stack: List[int] = list()
        for idx, domain in enumerate(domains):
            assert len(domain) >= 1
            for d in domain:
                adjList[d].append(idx)
            canAssign = len(domain) == 1
            if canAssign:
                stack.append(idx)
        while len(stack):
            u = stack.pop()
            domain = domains[u]
            assert len(domain) == 1, "Previous conflicting assignment"
            field: str = next(iter(domain))
            for v in adjList[field]:
                if u == v:
                    continue
                domains[v].remove(field)
                canAssign = len(domains[v]) == 1
                if canAssign:
                    stack.append(v)

    def getDest(self, domains: List[Set[str]], yours) -> Generator[int, None, None]:
        for idx, domain in enumerate(domains):
            assert len(domain) == 1, "Domain not properly assigned"
            field = next(iter(domain))
            if field.startswith('departure'):
                ticket = yours[idx]
                yield ticket


s = Solution('16.in', True)
print(s.sumInvalid())
print(s.multiplyDest())
