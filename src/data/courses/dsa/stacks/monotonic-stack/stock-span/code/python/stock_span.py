# ============================================================
# Online Stock Span
# ============================================================

# ============================================================
# Solution 1: Brute Force
# Time: O(N) per call | Space: O(N)
# ============================================================
class StockSpanner1:
    def __init__(self):
        self.prices = []

    def next(self, price: int) -> int:
        self.prices.append(price)
        span = 1
        i = len(self.prices) - 2
        while i >= 0 and self.prices[i] <= price:
            span += 1
            i -= 1
        return span

# ============================================================
# Solution 2: Monotonic Stack (Optimal)
# Time: O(1) amortized | Space: O(N)
# ============================================================
class StockSpanner2:
    def __init__(self):
        self.stack = []  # (price, index)
        self.day = 0

    def next(self, price: int) -> int:
        # Pop all prices <= current
        while self.stack and self.stack[-1][0] <= price:
            self.stack.pop()

        # Span = distance to previous greater
        span = self.day + 1 if not self.stack else self.day - self.stack[-1][1]

        self.stack.append((price, self.day))
        self.day += 1
        return span
