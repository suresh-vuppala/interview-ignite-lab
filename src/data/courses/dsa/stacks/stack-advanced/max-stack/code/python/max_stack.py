# ============================================================
# Max Stack
# ============================================================

class MaxStack:
    def __init__(self):
        self.main = []
        self.max_stack = []

    def push(self, val: int) -> None:
        self.main.append(val)
        self.max_stack.append(
            val if not self.max_stack else max(val, self.max_stack[-1])
        )

    def pop(self) -> None:
        self.main.pop()
        self.max_stack.pop()

    def top(self) -> int:
        return self.main[-1]

    def get_max(self) -> int:
        return self.max_stack[-1]
