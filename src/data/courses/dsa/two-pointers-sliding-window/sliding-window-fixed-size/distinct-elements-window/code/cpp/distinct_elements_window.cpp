// ============================================================
// Distinct Elements in Every Window of Size K
// ============================================================

#include <vector>
#include <unordered_map>
#include <unordered_set>
using namespace std;

// ============================================================
// Solution 1: Brute Force — Set per Window
// Time: O(N×K) | Space: O(K)
// ============================================================
class Solution1 {
public:
    vector<int> distinctInWindow(vector<int>& nums, int k) {
        vector<int> result;
        for (int i = 0; i <= (int)nums.size() - k; i++) {
            unordered_set<int> s(nums.begin() + i, nums.begin() + i + k);
            result.push_back(s.size());
        }
        return result;
    }
};

// ============================================================
// Solution 2: Sliding Window + Frequency Map (Optimal)
// Time: O(N) | Space: O(K)
// ============================================================
class Solution2 {
public:
    vector<int> distinctInWindow(vector<int>& nums, int k) {
        unordered_map<int, int> freq;
        vector<int> result;

        for (int i = 0; i < nums.size(); i++) {
            // Add entering element
            freq[nums[i]]++;

            // Remove leaving element (once window is full)
            if (i >= k) {
                freq[nums[i - k]]--;
                if (freq[nums[i - k]] == 0) {
                    freq.erase(nums[i - k]); // Key deletion — crucial!
                }
            }

            // Window is full — record distinct count
            if (i >= k - 1) {
                result.push_back(freq.size()); // Map size = distinct count
            }
        }

        return result;
    }
};
