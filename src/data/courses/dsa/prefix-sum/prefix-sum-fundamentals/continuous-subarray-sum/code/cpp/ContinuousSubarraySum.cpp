#include <vector>
#include <unordered_map>
using namespace std;
// ============================================================
// Solution 1: Brute Force — all subarrays of length ≥ 2 — O(N²)
// ============================================================
class Solution1 {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        int n = nums.size();
        for (int i = 0; i < n; i++) {
            int sum = nums[i];
            for (int j = i+1; j < n; j++) { sum += nums[j]; if (sum % k == 0) return true; }
        }
        return false;
    }
};

// ============================================================
// Solution 2: Prefix Sum mod K + HashMap — O(N)
// ============================================================
class Solution2 {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        unordered_map<int,int> modIndex; modIndex[0] = -1;
        int sum = 0;
        for (int i = 0; i < (int)nums.size(); i++) {
            sum += nums[i]; int mod = sum % k;
            if (modIndex.count(mod)) { if (i - modIndex[mod] >= 2) return true; }
            else modIndex[mod] = i;
        }
        return false;
    }
};
