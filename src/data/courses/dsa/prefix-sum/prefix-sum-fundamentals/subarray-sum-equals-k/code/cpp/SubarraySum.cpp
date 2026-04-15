#include <vector>
#include <unordered_map>
using namespace std;
// ============================================================
// Solution 1: Brute Force — check all subarrays — O(N²)
// ============================================================
class Solution1 {
public:
    int subarraySum(vector<int>& nums, int k) {
        int count = 0, n = nums.size();
        for (int i = 0; i < n; i++) {
            int sum = 0;
            for (int j = i; j < n; j++) { sum += nums[j]; if (sum == k) count++; }
        }
        return count;
    }
};

// ============================================================
// Solution 2: Prefix Sum + HashMap — O(N) Time, O(N) Space
// ============================================================
class Solution2 {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int,int> prefixCount; prefixCount[0] = 1;
        int sum = 0, count = 0;
        for (int x : nums) {
            sum += x;
            if (prefixCount.count(sum - k)) count += prefixCount[sum - k];
            prefixCount[sum]++;
        }
        return count;
    }
};
