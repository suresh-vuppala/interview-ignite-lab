# ============================================================
# Reverse String Using Stack
# ============================================================

# ============================================================
# Solution 1: Two-Pointer Swap
# Time: O(N) | Space: O(1)
# ============================================================
class Solution1:
    def reverseString(self, s: str) -> str:
        # Pythonic: slicing
        return s[::-1]

# ============================================================
# Solution 2: Stack — Push All, Pop All
# Time: O(N) | Space: O(N)
# ============================================================
class Solution2:
    def reverseString(self, s: str) -> str:
        stack = list(s)  # Push all characters
        result = []

        while stack:
            result.append(stack.pop())  # Pop in LIFO order

        return ''.join(result)
