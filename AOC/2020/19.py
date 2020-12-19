import re
from typing import List


class Solution:
    def __init__(self, fname: str, test: bool = False):
        self.rules: List[str] = list()
        self.patterns: List[str] = list()
        self.msgs: List[str] = list()
        if test:
            self.test()
        with open(fname) as f:
            self.parse(f.read())

    def test(self):
        with open('19.test') as f:
            self.parse(f.read())
        assert self.matchAcyclic() == 2
        with open('19.2.test') as f:
            self.parse(f.read())
        assert self.matchAcyclic() == 3
        assert self.matchCyclic() == 12

    def parse(self, param: str) -> None:
        rules, msgs = param.split('\n\n')
        self.msgs = msgs.split('\n')
        rules_list = (r.split(': ') for r in rules.split('\n'))
        rules_list = [(int(r[0]), r[1]) for r in rules_list]
        size = max(i[0] for i in rules_list) + 1
        self.rules = [None] * size
        for k, v in rules_list:
            isLeaf = v[0] == '"'
            if isLeaf:
                v = v[1]
            self.rules[int(k)] = v

    def matchAcyclic(self) -> int:
        self.patterns = [None] * len(self.rules)
        ptn = f'^{self.buildPattern(0)}$'
        msgs = (re.search(ptn, msg) for msg in self.msgs)
        matches = (1 for m in msgs if m)
        return sum(matches)

    def matchCyclic(self) -> int:
        """
        8: 42 | 42 8
        11: 42 31 | 42 11 31
        """
        self.rules[8] = '42 | 42 +'
        base11 = '42 31'
        self.rules[11] = base11
        # brute force to see if answer changes
        # not guaranteed AC
        prv, ans = -1, 0
        while prv != ans:
            base11 = f"42 {base11} 31"
            self.rules[11] += f" | {base11}"
            prv, ans = ans, self.matchAcyclic()
        return ans

    def buildPattern(self, idx: int) -> str:
        rule = self.rules[idx]
        if not rule[0].isdigit():
            return rule
        rules = map(self.buildRules, rule.split(" | "))
        self.patterns[idx] = f'({"|".join(rules)})'
        return self.patterns[idx]

    def buildRules(self, rules: str) -> str:
        ptn = ''
        for rule in rules.split(' '):
            isSelfLoop = rule == "+"
            if isSelfLoop:
                ptn = f"({ptn})+"
            else:
                sub_rule = int(rule)
                ptn += self.buildPattern(sub_rule)
        return ptn


s = Solution('19.in', True)
print(s.matchAcyclic())
print(s.matchCyclic())
