// ============================================================
// Fruits Into Baskets
// ============================================================

import java.util.*;

// ============================================================
// Solution 1: Brute Force
// Time: O(N²) | Space: O(N)
// ============================================================
class Solution1 {
    public int totalFruit(int[] fruits) {
        int max = 0;
        for (int i = 0; i < fruits.length; i++) {
            Map<Integer,Integer> f = new HashMap<>();
            for (int j = i; j < fruits.length; j++) {
                f.merge(fruits[j], 1, Integer::sum);
                if (f.size() > 2) break;
                max = Math.max(max, j - i + 1);
            }
        }
        return max;
    }
}

// ============================================================
// Solution 2: Sliding Window (Optimal)
// Time: O(N) | Space: O(1)
// ============================================================
class Solution2 {
    public int totalFruit(int[] fruits) {
        Map<Integer, Integer> freq = new HashMap<>();
        int left = 0, max = 0;
        for (int right = 0; right < fruits.length; right++) {
            freq.merge(fruits[right], 1, Integer::sum);
            while (freq.size() > 2) {
                freq.merge(fruits[left], -1, Integer::sum);
                if (freq.get(fruits[left]) == 0) freq.remove(fruits[left]);
                left++;
            }
            max = Math.max(max, right - left + 1);
        }
        return max;
    }
}
