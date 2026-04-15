#include <vector>
using namespace std;
// ============================================================
// Solution 1: Sort + scan — O(N log N)
// ============================================================
#include <algorithm>
class Solution1 {
public:
    int missingNumber(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        for (int i = 0; i < (int)nums.size(); i++)
            if (nums[i] != i) return i;
        return nums.size();
    }
};

// ============================================================
// Solution 2: XOR — O(N) Time, O(1) Space
// ============================================================
class Solution2 {
public:
    int missingNumber(vector<int>& nums) {
        int n = nums.size(), result = n;
        for (int i = 0; i < n; i++) result ^= i ^ nums[i];
        return result; // XOR(0..n) ^ XOR(nums) = missing number
    }
};
