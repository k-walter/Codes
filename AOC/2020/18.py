from typing import List, Union


class Solution:
    def __init__(self, fname: str, test: bool = False):
        self.eqns: List[List[Union[str, int]]] = list()
        if test:
            self.test()
        with open(fname) as f:
            self.parse(f.read())

    def test(self):
        self.parse('1 + 2 * 3 + 4 * 5 + 6')
        assert self.solve() == 71
        self.parse('1 + (2 * 3) + (4 * (5 + 6))')
        assert self.solve() == 51
        self.parse('2 * 3 + (4 * 5)')
        assert self.solve() == 26
        self.parse('5 + (8 * 3 + 9 + 3 * 4 * 3)')
        assert self.solve() == 437
        self.parse('5 * 9 * (7 * 3 * 3 + 9 * 3 + (8 + 6 * 4))')
        assert self.solve() == 12240
        self.parse('((2 + 4 * 9) * (6 + 9 * 8 + 6) + 6) + 2 + 4 * 2')
        assert self.solve() == 13632
        # raise Exception

    def parse(self, param: str):
        lines = param.split('\n')
        self.eqns = list()
        for line in lines:
            chars = (ch for ch in list(line) if ch != ' ')
            noOrOp = ['('] + [int(ch) if ch.isdigit() else ch for ch in chars] + [')']
            self.eqns.append(noOrOp)

    def solve(self) -> int:
        ans: int = 0
        stack: List[Union[str, int]] = list()
        for eqn in self.eqns:
            for ch in eqn:
                if isinstance(ch, int):
                    self.pushNo(stack, ch)
                else:
                    self.pushOp(stack, ch)
            ans += stack.pop()
        return ans

    def pushNo(self, stack: List[Union[str, int]], ch: int):
        if len(stack) == 0:
            stack.append(ch)
            return
        top: str = stack[-1]
        assert isinstance(top, str), f"Should be operator|new={ch}|{stack}"
        assert top != ')', "Should have closed parenthesis"
        if top == '(':
            stack.append(ch)
        elif top == '+':
            stack.pop()
            no: int = stack.pop()
            assert isinstance(no, int)
            stack.append(no + ch)
        elif top == '*':
            stack.pop()
            no: int = stack.pop()
            assert isinstance(no, int)
            stack.append(no * ch)
        else:
            raise Exception(f"Unknown operator {top}")

    def pushOp(self, stack: List[Union[str, int]], ch: str):
        if ch not in {"(", ")", "+", "*"}:
            raise Exception(f"Unknown operator {ch}")
        if ch != ')':
            stack.append(ch)
            return
        no: int = stack.pop()
        assert isinstance(no, int)
        lbr: str = stack.pop()
        assert lbr == '(', lbr
        self.pushNo(stack, no)


s = Solution('18.in', True)
print(s.solve())
