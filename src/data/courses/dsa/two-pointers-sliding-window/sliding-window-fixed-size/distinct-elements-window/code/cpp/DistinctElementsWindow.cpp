#include <vector>
#include <unordered_map>
#include <unordered_set>
using namespace std;
// ============================================================
// Solution 1: HashSet for each window — O(N*K)
// ============================================================
class Solution1 {
public:
    vector<int> countDistinct(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> result;
        for (int i = 0; i <= n - k; i++) {
            unordered_set<int> s(nums.begin() + i, nums.begin() + i + k);
            result.push_back(s.size());
        }
        return result;
    }
};

// ============================================================
// Solution 2: Sliding Window + HashMap frequency — O(N)
// ============================================================
class Solution2 {
public:
    vector<int> countDistinct(vector<int>& nums, int k) {
        int n = nums.size();
        unordered_map<int, int> freq;
        vector<int> result;
        for (int i = 0; i < n; i++) {
            freq[nums[i]]++;
            if (i >= k) { freq[nums[i - k]]--; if (freq[nums[i - k]] == 0) freq.erase(nums[i - k]); }
            if (i >= k - 1) result.push_back(freq.size());
        }
        return result;
    }
};
