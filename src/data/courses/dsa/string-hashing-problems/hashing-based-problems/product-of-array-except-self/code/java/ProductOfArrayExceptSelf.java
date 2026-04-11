// ============================================================
// Product of Array Except Self
// ============================================================

// ============================================================
// Solution 1: Brute Force
// Time: O(N²) | Space: O(1) extra
// ============================================================
class Solution1 {
    public int[] productExceptSelf(int[] nums) {
        int n = nums.length;
        int[] result = new int[n];
        java.util.Arrays.fill(result, 1);

        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++)
                if (i != j) result[i] *= nums[j];

        return result;
    }
}

// ============================================================
// Solution 2: Prefix + Suffix Arrays
// Time: O(N) | Space: O(N)
// ============================================================
class Solution2 {
    public int[] productExceptSelf(int[] nums) {
        int n = nums.length;
        int[] prefix = new int[n], suffix = new int[n], result = new int[n];
        prefix[0] = 1; suffix[n - 1] = 1;

        for (int i = 1; i < n; i++) prefix[i] = prefix[i - 1] * nums[i - 1];
        for (int i = n - 2; i >= 0; i--) suffix[i] = suffix[i + 1] * nums[i + 1];
        for (int i = 0; i < n; i++) result[i] = prefix[i] * suffix[i];

        return result;
    }
}

// ============================================================
// Solution 3: Two-Pass with Running Variable (Optimal)
// Time: O(N) | Space: O(1) extra
// ============================================================
class Solution3 {
    public int[] productExceptSelf(int[] nums) {
        int n = nums.length;
        int[] result = new int[n];

        // Pass 1: left prefix products
        int left = 1;
        for (int i = 0; i < n; i++) { result[i] = left; left *= nums[i]; }

        // Pass 2: multiply by right suffix products
        int right = 1;
        for (int i = n - 1; i >= 0; i--) { result[i] *= right; right *= nums[i]; }

        return result;
    }
}
