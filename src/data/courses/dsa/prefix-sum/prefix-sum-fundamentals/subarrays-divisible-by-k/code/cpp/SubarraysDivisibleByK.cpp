#include <vector>
#include <unordered_map>
using namespace std;
// ============================================================
// Solution 1: Brute Force — all subarrays — O(N²)
// ============================================================
class Solution1 {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        int count = 0, n = nums.size();
        for (int i = 0; i < n; i++) {
            int sum = 0;
            for (int j = i; j < n; j++) { sum += nums[j]; if (sum % k == 0) count++; }
        }
        return count;
    }
};

// ============================================================
// Solution 2: Prefix mod + count pairs — O(N)
// ============================================================
class Solution2 {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        unordered_map<int,int> modCount; modCount[0] = 1;
        int sum = 0, count = 0;
        for (int x : nums) {
            sum += x;
            int mod = ((sum % k) + k) % k; // Handle negative mod
            count += modCount[mod];
            modCount[mod]++;
        }
        return count;
    }
};
