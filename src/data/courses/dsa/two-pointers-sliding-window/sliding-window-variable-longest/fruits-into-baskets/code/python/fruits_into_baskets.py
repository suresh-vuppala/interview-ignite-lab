# ============================================================
# Fruits Into Baskets
# ============================================================

from typing import List
from collections import defaultdict

# ============================================================
# Solution 1: Brute Force
# Time: O(N²) | Space: O(N)
# ============================================================
class Solution1:
    def totalFruit(self, fruits: List[int]) -> int:
        max_len = 0
        for i in range(len(fruits)):
            types = set()
            for j in range(i, len(fruits)):
                types.add(fruits[j])
                if len(types) > 2: break
                max_len = max(max_len, j - i + 1)
        return max_len

# ============================================================
# Solution 2: Sliding Window (Optimal)
# Time: O(N) | Space: O(1)
# ============================================================
class Solution2:
    def totalFruit(self, fruits: List[int]) -> int:
        freq = defaultdict(int)
        left = max_len = 0

        for right in range(len(fruits)):
            freq[fruits[right]] += 1

            while len(freq) > 2:
                freq[fruits[left]] -= 1
                if freq[fruits[left]] == 0:
                    del freq[fruits[left]]
                left += 1

            max_len = max(max_len, right - left + 1)

        return max_len
