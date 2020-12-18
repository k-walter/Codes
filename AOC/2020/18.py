from typing import List, Union


class Solution:
    def __init__(self, fname: str, test: bool = False):
        self.addPrecedence: bool = False
        self.eqns: List[List[Union[str, int]]] = list()
        if test:
            self.test()
        with open(fname) as f:
            self.parse(f.read())

    def test(self) -> None:
        self.parse('1 + 2 * 3 + 4 * 5 + 6')
        assert self.evalNoPrecedence() == 71
        assert self.evalAddPrecedence() == 231
        self.parse('1 + (2 * 3) + (4 * (5 + 6))')
        assert self.evalNoPrecedence() == 51
        assert self.evalAddPrecedence() == 51
        self.parse('2 * 3 + (4 * 5)')
        assert self.evalNoPrecedence() == 26
        assert self.evalAddPrecedence() == 46
        self.parse('5 + (8 * 3 + 9 + 3 * 4 * 3)')
        assert self.evalNoPrecedence() == 437
        assert self.evalAddPrecedence() == 1445
        self.parse('5 * 9 * (7 * 3 * 3 + 9 * 3 + (8 + 6 * 4))')
        assert self.evalNoPrecedence() == 12240
        assert self.evalAddPrecedence() == 669060
        self.parse('((2 + 4 * 9) * (6 + 9 * 8 + 6) + 6) + 2 + 4 * 2')
        assert self.evalNoPrecedence() == 13632
        assert self.evalAddPrecedence() == 23340

    def parse(self, param: str):
        lines = param.split('\n')
        self.eqns = list()
        for line in lines:
            chars = (ch for ch in list(line) if ch != ' ')
            wrappedEqn = ['('] + [int(ch) if ch.isdigit() else ch for ch in chars] + [')']
            self.eqns.append(wrappedEqn)

    def evalNoPrecedence(self) -> int:
        self.addPrecedence = False
        return self.solve()

    def evalAddPrecedence(self) -> int:
        self.addPrecedence = True
        return self.solve()

    def solve(self) -> int:
        ans: int = 0
        stack: List[Union[str, int]] = list()
        for eqn in self.eqns:
            for ch in eqn:
                if isinstance(ch, int):
                    self.pushNo(stack, ch)
                elif ch != ')':
                    stack.append(ch)
                elif ch == ')':
                    self.eval(stack)
                else:
                    raise Exception(stack, ch)
            ans += stack.pop()
        return ans

    def eval(self, stack) -> None:
        left = self.findLeftBrkt(stack)
        ans: int = stack[left + 1]
        ops: List[str] = stack[left + 2::2]
        nos: List[int] = stack[left + 3::2]
        for op, no in zip(ops, nos):
            assert isinstance(op, str) and isinstance(no, int)
            if op == '*':
                ans *= no
            elif op == '+':
                ans += no
            else:
                raise Exception("Unknown op")
        self.popBack(stack, left)
        self.pushNo(stack, ans)

    def findLeftBrkt(self, stack) -> int:
        left: int = len(stack) - 1
        while stack[left] != '(':
            left -= 1
        return left

    def popBack(self, stack: List[Union[str, int]], n: int) -> None:
        n = len(stack) - n
        while n:
            stack.pop()
            n -= 1

    def pushNo(self, stack: List[Union[str, int]], ch: int) -> None:
        isAddOp = self.addPrecedence and len(stack) and stack[-1] == "+"
        if isAddOp:
            stack.pop()
            assert isinstance(stack[-1], int)
            stack[-1] += ch
        else:
            stack.append(ch)


s = Solution('18.in', True)
print(s.evalNoPrecedence())
print(s.evalAddPrecedence())
