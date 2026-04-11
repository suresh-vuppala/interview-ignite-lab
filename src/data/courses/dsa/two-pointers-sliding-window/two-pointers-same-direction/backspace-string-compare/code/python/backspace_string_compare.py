# ============================================================
# Backspace String Compare
# ============================================================

# ============================================================
# Solution 1: Stack — Build Processed Strings
# Time: O(N+M) | Space: O(N+M)
# ============================================================
class Solution1:
    def backspaceCompare(self, s: str, t: str) -> bool:
        def process(string):
            result = []
            for c in string:
                if c == '#':
                    if result: result.pop()
                else:
                    result.append(c)
            return result

        return process(s) == process(t)

# ============================================================
# Solution 2: Two Pointers from End (Optimal)
# Time: O(N+M) | Space: O(1)
# ============================================================
class Solution2:
    def backspaceCompare(self, s: str, t: str) -> bool:
        def get_next(string, idx):
            skip = 0
            while idx >= 0:
                if string[idx] == '#': skip += 1; idx -= 1
                elif skip > 0: skip -= 1; idx -= 1
                else: break
            return idx

        i, j = len(s) - 1, len(t) - 1
        while i >= 0 or j >= 0:
            i = get_next(s, i)
            j = get_next(t, j)
            if i >= 0 and j >= 0 and s[i] != t[j]: return False
            if (i >= 0) != (j >= 0): return False
            i -= 1; j -= 1

        return True
