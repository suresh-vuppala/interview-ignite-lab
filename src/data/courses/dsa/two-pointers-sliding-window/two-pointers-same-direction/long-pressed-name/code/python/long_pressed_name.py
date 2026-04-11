# ============================================================
# Long Pressed Name
# ============================================================

# ============================================================
# Solution: Two Pointers
# Time: O(N+M) | Space: O(1)
# ============================================================
class Solution:
    def isLongPressedName(self, name: str, typed: str) -> bool:
        i = j = 0

        while j < len(typed):
            if i < len(name) and name[i] == typed[j]:
                i += 1  # Normal match
                j += 1
            elif j > 0 and typed[j] == typed[j - 1]:
                j += 1  # Long press — skip
            else:
                return False  # Mismatch

        return i == len(name)  # All name characters consumed?
