// ============================================================
// Two Sum II — Input Array Is Sorted
// ============================================================

// ============================================================
// Solution 1: Brute Force — All Pairs
// Time: O(N²) | Space: O(1)
// ============================================================
class Solution1 {
    public int[] twoSum(int[] numbers, int target) {
        for (int i = 0; i < numbers.length - 1; i++)
            for (int j = i + 1; j < numbers.length; j++)
                if (numbers[i] + numbers[j] == target)
                    return new int[]{i + 1, j + 1};
        return new int[]{};
    }
}

// ============================================================
// Solution 2: Two Pointers — Converge from Ends (Optimal)
// Time: O(N) | Space: O(1)
// ============================================================
class Solution2 {
    public int[] twoSum(int[] numbers, int target) {
        int left = 0, right = numbers.length - 1;

        while (left < right) {
            int sum = numbers[left] + numbers[right];

            if (sum == target) return new int[]{left + 1, right + 1};
            else if (sum < target) left++;
            else right--;
        }

        return new int[]{};
    }
}
