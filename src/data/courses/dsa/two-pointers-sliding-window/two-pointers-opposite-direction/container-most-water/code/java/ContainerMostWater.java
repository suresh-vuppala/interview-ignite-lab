// ============================================================
// Container With Most Water
// ============================================================

// ============================================================
// Solution 1: Brute Force — All Pairs
// Time: O(N²) | Space: O(1)
// ============================================================
class Solution1 {
    public int maxArea(int[] height) {
        int max = 0;
        for (int i = 0; i < height.length - 1; i++)
            for (int j = i + 1; j < height.length; j++)
                max = Math.max(max, Math.min(height[i], height[j]) * (j - i));
        return max;
    }
}

// ============================================================
// Solution 2: Two Pointers — Move Shorter Side (Optimal)
// Time: O(N) | Space: O(1)
// ============================================================
class Solution2 {
    public int maxArea(int[] height) {
        int left = 0, right = height.length - 1, max = 0;

        while (left < right) {
            max = Math.max(max, Math.min(height[left], height[right]) * (right - left));

            if (height[left] < height[right]) left++;
            else right--;
        }

        return max;
    }
}
