// ============================================================
// Majority Element
// ============================================================

#include <vector>
#include <unordered_map>
#include <algorithm>
using namespace std;

// ============================================================
// Solution 1: Hash Map — Count Frequencies
// Time: O(N) | Space: O(N)
// ============================================================
class Solution1 {
public:
    int majorityElement(vector<int>& nums) {
        unordered_map<int, int> freq;
        int n = nums.size();

        for (int num : nums) {
            freq[num]++;
            // Early termination when majority found
            if (freq[num] > n / 2) return num;
        }

        return -1; // Shouldn't reach here
    }
};

// ============================================================
// Solution 2: Sort + Middle Element
// Time: O(N log N) | Space: O(1)
// ============================================================
class Solution2 {
public:
    int majorityElement(vector<int>& nums) {
        // After sorting, majority element must be at middle index
        sort(nums.begin(), nums.end());
        return nums[nums.size() / 2];
    }
};

// ============================================================
// Solution 3: Boyer-Moore Voting Algorithm (Optimal)
// Time: O(N) | Space: O(1)
// ============================================================
class Solution3 {
public:
    int majorityElement(vector<int>& nums) {
        int candidate = nums[0];
        int count = 1;

        // Voting phase: cancel different elements
        for (int i = 1; i < nums.size(); i++) {
            if (count == 0) {
                candidate = nums[i]; // New candidate
                count = 1;
            } else if (nums[i] == candidate) {
                count++;              // Same — vote for
            } else {
                count--;              // Different — cancel
            }
        }

        return candidate; // Majority guaranteed to survive
    }
};
