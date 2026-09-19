class Solution:
    def evalRPN(self, tokens: List[str]) -> int:
        stk = []
        for i in range(0, len(tokens)):
            if tokens[i] == "+":
                num1 = stk[-1]
                stk.pop()
                num2 = stk[-1]
                stk.pop()
                result = num1 + num2
                stk.append(result)
            elif tokens[i] == "-":
                num1 = stk[-1]
                stk.pop()
                num2 = stk[-1]
                stk.pop()
                stk.append(num2 - num1)
            elif tokens[i] == "*":
                num1 = stk[-1]
                stk.pop()
                num2 = stk[-1]
                stk.pop()
                stk.append(num2 * num1)
            elif tokens[i] == "/":
                num1 = stk[-1]
                stk.pop()
                num2 = stk[-1]
                stk.pop()
                stk.append(int(num2 / num1))
            else:
                stk.append(int(tokens[i]))
        return stk[-1]