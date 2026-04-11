# ============================================================
# Valid Palindrome
# ============================================================

# ============================================================
# Solution 1: Filter + Reverse
# Time: O(N) | Space: O(N)
# ============================================================
class Solution1:
    def isPalindrome(self, s: str) -> bool:
        # Build cleaned lowercase alphanumeric string
        clean = ''.join(c.lower() for c in s if c.isalnum())
        return clean == clean[::-1]

# ============================================================
# Solution 2: Two Pointers In-Place (Optimal)
# Time: O(N) | Space: O(1)
# ============================================================
class Solution2:
    def isPalindrome(self, s: str) -> bool:
        left, right = 0, len(s) - 1

        while left < right:
            # Skip non-alphanumeric
            while left < right and not s[left].isalnum():
                left += 1
            while left < right and not s[right].isalnum():
                right -= 1

            # Compare lowercase
            if s[left].lower() != s[right].lower():
                return False

            left += 1
            right -= 1

        return True
