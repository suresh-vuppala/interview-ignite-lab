# ============================================================
# Min Stack
# ============================================================

# ============================================================
# Solution 1: Two Stacks
# All operations O(1)
# ============================================================
class MinStack1:
    def __init__(self):
        self.main = []
        self.min_stack = []

    def push(self, val: int) -> None:
        self.main.append(val)
        # Track minimum at each level
        self.min_stack.append(
            val if not self.min_stack else min(val, self.min_stack[-1])
        )

    def pop(self) -> None:
        self.main.pop()
        self.min_stack.pop()  # Stay in sync

    def top(self) -> int:
        return self.main[-1]

    def getMin(self) -> int:
        return self.min_stack[-1]  # O(1) min access

# ============================================================
# Solution 2: Optimized — Push Min Only When Needed
# All operations O(1)
# ============================================================
class MinStack2:
    def __init__(self):
        self.main = []
        self.min_stack = []

    def push(self, val: int) -> None:
        self.main.append(val)
        if not self.min_stack or val <= self.min_stack[-1]:
            self.min_stack.append(val)

    def pop(self) -> None:
        if self.main[-1] == self.min_stack[-1]:
            self.min_stack.pop()
        self.main.pop()

    def top(self) -> int:
        return self.main[-1]

    def getMin(self) -> int:
        return self.min_stack[-1]
