# ============================================================
# Least Consecutive Cards to Match
# ============================================================

from typing import List

# ============================================================
# Solution 1: Brute Force
# Time: O(N²) | Space: O(1)
# ============================================================
class Solution1:
    def minimumCardPickup(self, cards: List[int]) -> int:
        min_len = float('inf')
        for i in range(len(cards)):
            for j in range(i + 1, len(cards)):
                if cards[i] == cards[j]:
                    min_len = min(min_len, j - i + 1)
                    break
        return -1 if min_len == float('inf') else min_len

# ============================================================
# Solution 2: Hash Map (Optimal)
# Time: O(N) | Space: O(N)
# ============================================================
class Solution2:
    def minimumCardPickup(self, cards: List[int]) -> int:
        last_seen = {}
        min_len = float('inf')

        for i, card in enumerate(cards):
            if card in last_seen:
                min_len = min(min_len, i - last_seen[card] + 1)
            last_seen[card] = i

        return -1 if min_len == float('inf') else min_len
