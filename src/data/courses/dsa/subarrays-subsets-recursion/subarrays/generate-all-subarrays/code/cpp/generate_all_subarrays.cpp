#include <vector>
using namespace std;
// ============================================================
// Solution 1: Two nested loops — O(N²) subarrays, O(N³) with copy
// ============================================================
class Solution1 {
public:
    vector<vector<int>> allSubarrays(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> result;
        for (int i = 0; i < n; i++)
            for (int j = i; j < n; j++)
                result.push_back(vector<int>(nums.begin()+i, nums.begin()+j+1));
        return result; // O(N³) total elements copied
    }
};

// ============================================================
// Solution 2: Incremental build — O(N²) subarrays, O(N²) amortized
// ============================================================
class Solution2 {
public:
    vector<vector<int>> allSubarrays(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> result;
        for (int i = 0; i < n; i++) {
            vector<int> sub;
            for (int j = i; j < n; j++) {
                sub.push_back(nums[j]); // Extend instead of copy
                result.push_back(sub);
            }
        }
        return result;
    }
};
