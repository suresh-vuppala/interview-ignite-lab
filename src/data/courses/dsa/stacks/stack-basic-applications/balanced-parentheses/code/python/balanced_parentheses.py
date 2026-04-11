# ============================================================
# Valid Parentheses (Balanced Brackets)
# ============================================================

# ============================================================
# Solution 1: Brute Force — Repeatedly Remove Pairs
# Time: O(N²) | Space: O(N)
# ============================================================
class Solution1:
    def isValid(self, s: str) -> bool:
        while '()' in s or '[]' in s or '{}' in s:
            s = s.replace('()', '').replace('[]', '').replace('{}', '')
        return s == ''

# ============================================================
# Solution 2: Stack — Single Pass (Optimal)
# Time: O(N) | Space: O(N)
# ============================================================
class Solution2:
    def isValid(self, s: str) -> bool:
        stack = []
        match = {')': '(', ']': '[', '}': '{'}

        for c in s:
            if c in '([{':
                stack.append(c)  # Opening → push
            else:
                # Closing → check match
                if not stack or stack[-1] != match[c]:
                    return False
                stack.pop()  # Matched pair

        return len(stack) == 0  # Any unmatched?
