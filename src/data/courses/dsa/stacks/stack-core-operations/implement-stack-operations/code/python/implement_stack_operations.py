# ============================================================
# Implement Stack Operations
# ============================================================

# ============================================================
# Solution: Array-Based Stack
# All operations O(1) amortized
# ============================================================
class MyStack:
    def __init__(self):
        self.data = []

    def push(self, x: int) -> None:
        self.data.append(x)  # O(1) amortized

    def pop(self) -> int:
        return self.data.pop()  # O(1)

    def top(self) -> int:
        return self.data[-1]  # O(1)

    def is_empty(self) -> bool:
        return len(self.data) == 0  # O(1)

    def size(self) -> int:
        return len(self.data)  # O(1)
