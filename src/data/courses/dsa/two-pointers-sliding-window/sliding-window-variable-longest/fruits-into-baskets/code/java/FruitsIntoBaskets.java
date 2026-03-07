import java.util.*;

// Time: O(N³), Space: O(N)
class FruitsIntoBaskets {
    public int totalFruitBruteForce(int[] fruits) {
        int n = fruits.length, maxLen = 0;
        for (int i = 0; i < n; i++) {
            for (int j = i; j < n; j++) {
                Set<Integer> types = new HashSet<>();
                for (int p = i; p <= j; p++) types.add(fruits[p]);
                if (types.size() <= 2) maxLen = Math.max(maxLen, j - i + 1);
            }
        }
        return maxLen;
    }

    // ============================================================

    // Time: O(N²), Space: O(2)
    public int totalFruitBruteOptimized(int[] fruits) {
        int n = fruits.length, maxLen = 0;
        for (int i = 0; i < n; i++) {
            Set<Integer> types = new HashSet<>();
            for (int j = i; j < n; j++) {
                types.add(fruits[j]);
                if (types.size() <= 2) maxLen = Math.max(maxLen, j - i + 1);
                else break;
            }
        }
        return maxLen;
    }

    // ============================================================

    // Time: O(N²), Space: O(2)
    public int totalFruitTwoPointerShrink(int[] fruits) {
        int n = fruits.length, maxLen = 0;
        for (int i = 0; i < n; i++) {
            Map<Integer, Integer> freq = new HashMap<>();
            int j = i;
            while (j < n) {
                freq.put(fruits[j], freq.getOrDefault(fruits[j], 0) + 1);
                if (freq.size() <= 2) {
                    maxLen = Math.max(maxLen, j - i + 1);
                    j++;
                } else break;
            }
        }
        return maxLen;
    }

    // ============================================================

    // Time: O(N), Space: O(2)
    public int totalFruitSlidingWindow(int[] fruits) {
        int left = 0, maxLen = 0;
        Map<Integer, Integer> freq = new HashMap<>();
        for (int right = 0; right < fruits.length; right++) {
            freq.put(fruits[right], freq.getOrDefault(fruits[right], 0) + 1);
            while (freq.size() > 2) {
                freq.put(fruits[left], freq.get(fruits[left]) - 1);
                if (freq.get(fruits[left]) == 0) freq.remove(fruits[left]);
                left++;
            }
            maxLen = Math.max(maxLen, right - left + 1);
        }
        return maxLen;
    }

    // ============================================================

    // Time: O(N), Space: O(2)
    public int totalFruitSlidingWindowOptimized(int[] fruits) {
        int left = 0;
        Map<Integer, Integer> freq = new HashMap<>();
        for (int right = 0; right < fruits.length; right++) {
            freq.put(fruits[right], freq.getOrDefault(fruits[right], 0) + 1);
            if (freq.size() > 2) {
                freq.put(fruits[left], freq.get(fruits[left]) - 1);
                if (freq.get(fruits[left]) == 0) freq.remove(fruits[left]);
                left++;
            }
        }
        return fruits.length - left;
    }
}
