// ============================================================
// Sort Colors (Dutch National Flag)
// ============================================================

// ============================================================
// Solution 1: Counting Sort — Two Pass
// Time: O(N) | Space: O(1)
// ============================================================
class Solution1 {
    public void sortColors(int[] nums) {
        int[] count = new int[3];
        for (int n : nums) count[n]++;

        int idx = 0;
        for (int c = 0; c < 3; c++)
            for (int i = 0; i < count[c]; i++)
                nums[idx++] = c;
    }
}

// ============================================================
// Solution 2: Dutch National Flag — Single Pass (Optimal)
// Time: O(N) | Space: O(1)
// ============================================================
class Solution2 {
    public void sortColors(int[] nums) {
        int lo = 0, mid = 0, hi = nums.length - 1;

        while (mid <= hi) {
            if (nums[mid] == 0) {
                int t = nums[lo]; nums[lo] = nums[mid]; nums[mid] = t;
                lo++; mid++;
            } else if (nums[mid] == 1) {
                mid++;
            } else {
                int t = nums[mid]; nums[mid] = nums[hi]; nums[hi] = t;
                hi--;
            }
        }
    }
}
