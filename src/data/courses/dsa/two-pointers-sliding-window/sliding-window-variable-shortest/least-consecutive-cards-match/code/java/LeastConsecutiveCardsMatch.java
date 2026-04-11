// ============================================================
// Least Consecutive Cards to Match
// ============================================================

import java.util.*;

// ============================================================
// Solution 1: Brute Force
// Time: O(N²) | Space: O(1)
// ============================================================
class Solution1 {
    public int minimumCardPickup(int[] cards) {
        int min = Integer.MAX_VALUE;
        for (int i = 0; i < cards.length; i++)
            for (int j = i+1; j < cards.length; j++)
                if (cards[i] == cards[j]) { min = Math.min(min, j-i+1); break; }
        return min == Integer.MAX_VALUE ? -1 : min;
    }
}

// ============================================================
// Solution 2: Hash Map (Optimal)
// Time: O(N) | Space: O(N)
// ============================================================
class Solution2 {
    public int minimumCardPickup(int[] cards) {
        Map<Integer, Integer> last = new HashMap<>();
        int min = Integer.MAX_VALUE;
        for (int i = 0; i < cards.length; i++) {
            if (last.containsKey(cards[i]))
                min = Math.min(min, i - last.get(cards[i]) + 1);
            last.put(cards[i], i);
        }
        return min == Integer.MAX_VALUE ? -1 : min;
    }
}
