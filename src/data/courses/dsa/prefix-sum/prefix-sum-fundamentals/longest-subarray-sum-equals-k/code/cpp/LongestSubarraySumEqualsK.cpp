#include <vector>
#include <unordered_map>
#include <algorithm>
using namespace std;
// ============================================================
// Solution 1: Brute Force — all subarrays — O(N²)
// ============================================================
class Solution1 {
public:
    int maxLen(vector<int>& nums, int k) {
        int n = nums.size(), maxLength = 0;
        for (int i = 0; i < n; i++) {
            int sum = 0;
            for (int j = i; j < n; j++) { sum += nums[j]; if (sum == k) maxLength = max(maxLength, j-i+1); }
        }
        return maxLength;
    }
};

// ============================================================
// Solution 2: Prefix Sum + HashMap (store first occurrence) — O(N)
// ============================================================
class Solution2 {
public:
    int maxLen(vector<int>& nums, int k) {
        unordered_map<long,int> first; first[0] = -1;
        long sum = 0; int maxLength = 0;
        for (int i = 0; i < (int)nums.size(); i++) {
            sum += nums[i];
            if (first.count(sum - k)) maxLength = max(maxLength, i - first[sum - k]);
            if (!first.count(sum)) first[sum] = i; // Only store FIRST occurrence
        }
        return maxLength;
    }
};
