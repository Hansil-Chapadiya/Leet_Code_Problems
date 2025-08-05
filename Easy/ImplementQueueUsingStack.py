class ImplementQueueUsingStack:

    def __init__(self):
        self.inputStack = []
        self.outputStack = []

    def push(self, x: int) -> None:
        self.inputStack.append(x)

    def pop(self) -> int:

        if not self.outputStack:
            if not self.inputStack:
                return None
            while self.inputStack:
                self.outputStack.append(self.inputStack.pop())

        return self.outputStack.pop()

    def peek(self) -> int:

        if not self.outputStack:
            if not self.inputStack:
                return None

        while self.inputStack:
            self.outputStack.append(self.inputStack.pop())

        return self.outputStack[-1]

    def empty(self) -> bool:
        return not self.inputStack and not self.outputStack

obj = ImplementQueueUsingStack()
print(obj.push(12))
print(obj.peek())
print(obj.pop())
print(obj.peek())
print(obj.empty())