# ============================================================
# Remove K Digits
# ============================================================

class Solution:
    def removeKdigits(self, num: str, k: int) -> str:
        stack = []

        for d in num:
            # Pop larger digits — greedy
            while k > 0 and stack and stack[-1] > d:
                stack.pop()
                k -= 1
            stack.append(d)

        # Remove remaining from end
        while k > 0:
            stack.pop()
            k -= 1

        # Strip leading zeros and build result
        result = ''.join(stack).lstrip('0')
        return result or '0'
