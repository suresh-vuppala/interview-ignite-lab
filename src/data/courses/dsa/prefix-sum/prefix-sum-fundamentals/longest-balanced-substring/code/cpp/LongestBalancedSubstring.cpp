#include <vector>
#include <unordered_map>
#include <algorithm>
using namespace std;
// ============================================================
// Solution 1: Brute Force — check all substrings — O(N²)
// ============================================================
class Solution1 {
public:
    int findMaxLength(vector<int>& nums) {
        int n = nums.size(), maxLen = 0;
        for (int i = 0; i < n; i++) {
            int zeros = 0, ones = 0;
            for (int j = i; j < n; j++) {
                if (nums[j] == 0) zeros++; else ones++;
                if (zeros == ones) maxLen = max(maxLen, j - i + 1);
            }
        }
        return maxLen;
    }
};

// ============================================================
// Solution 2: Prefix Sum (0→-1) + HashMap — O(N)
// ============================================================
class Solution2 {
public:
    int findMaxLength(vector<int>& nums) {
        unordered_map<int,int> first; first[0] = -1;
        int sum = 0, maxLen = 0;
        for (int i = 0; i < (int)nums.size(); i++) {
            sum += (nums[i] == 1) ? 1 : -1; // Treat 0 as -1
            if (first.count(sum)) maxLen = max(maxLen, i - first[sum]);
            else first[sum] = i;
        }
        return maxLen;
    }
};
