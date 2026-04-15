#include <vector>
#include <unordered_set>
#include <unordered_map>
#include <algorithm>
using namespace std;
// ============================================================
// Solution 1: Brute Force — check all pairs — O(N²) Time
// ============================================================
class Solution1 {
public:
    int findPairs(vector<int>& nums, int k) {
        int count = 0, n = nums.size();
        sort(nums.begin(), nums.end());
        for (int i = 0; i < n; i++) {
            if (i > 0 && nums[i] == nums[i-1]) continue; // Skip duplicates
            for (int j = i + 1; j < n; j++) {
                if (nums[j] - nums[i] == k) { count++; break; }
                if (nums[j] - nums[i] > k) break; // Sorted, no point continuing
            }
        }
        return count;
    }
};

// ============================================================
// Solution 2: HashMap / Two Pointers — O(N) Time
// ============================================================
class Solution2 {
public:
    int findPairs(vector<int>& nums, int k) {
        if (k < 0) return 0;
        unordered_map<int, int> freq;
        for (int x : nums) freq[x]++;
        int count = 0;
        for (auto& [num, cnt] : freq) {
            if (k == 0) { if (cnt >= 2) count++; } // Same element pair
            else { if (freq.count(num + k)) count++; } // num + k exists
        }
        return count;
    }
};
