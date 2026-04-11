// ============================================================
// Product of Array Except Self
// ============================================================

#include <vector>
using namespace std;

// ============================================================
// Solution 1: Brute Force
// Time: O(N²) | Space: O(1) extra
// ============================================================
class Solution1 {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<int> result(n, 1);

        // For each position, multiply all OTHER elements
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (i != j) result[i] *= nums[j];
            }
        }

        return result;
    }
};

// ============================================================
// Solution 2: Prefix + Suffix Arrays
// Time: O(N) | Space: O(N)
// ============================================================
class Solution2 {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<int> prefix(n, 1), suffix(n, 1), result(n);

        // Build prefix products (left to right)
        for (int i = 1; i < n; i++)
            prefix[i] = prefix[i - 1] * nums[i - 1];

        // Build suffix products (right to left)
        for (int i = n - 2; i >= 0; i--)
            suffix[i] = suffix[i + 1] * nums[i + 1];

        // Combine: result[i] = left product × right product
        for (int i = 0; i < n; i++)
            result[i] = prefix[i] * suffix[i];

        return result;
    }
};

// ============================================================
// Solution 3: Two-Pass with Running Variable (Optimal)
// Time: O(N) | Space: O(1) extra
// ============================================================
class Solution3 {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<int> result(n);

        // Pass 1: Fill with left prefix products
        int leftProduct = 1;
        for (int i = 0; i < n; i++) {
            result[i] = leftProduct;   // Product of everything to the left
            leftProduct *= nums[i];     // Include current for next position
        }

        // Pass 2: Multiply by right suffix products
        int rightProduct = 1;
        for (int i = n - 1; i >= 0; i--) {
            result[i] *= rightProduct;  // Multiply by product of everything to the right
            rightProduct *= nums[i];    // Include current for next position
        }

        return result;
    }
};
