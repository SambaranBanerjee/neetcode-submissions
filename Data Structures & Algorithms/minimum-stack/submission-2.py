class MinStack:
    def __init__(self):
        self.stack = []
        self.minStack = []

    def push(self, val: int) -> None:
        self.stack.append(val)

        if not self.minStack or val <= self.minStack[-1]:
            self.minStack.append(val)
        else:
            self.minStack.append(self.minStack[-1])

    def pop(self) -> None:
        if self.stack:
            self.stack.pop()
            self.minStack.pop()

    def top(self) -> int:
        top_element = self.stack[-1]
        return top_element

    def getMin(self) -> int:
        if self.minStack:
            return self.minStack[-1]
        else:
            return 0
