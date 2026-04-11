// ============================================================
// Subarrays with K Different Integers
// ============================================================

#include <vector>
#include <unordered_map>
using namespace std;

// ============================================================
// Solution 1: Brute Force
// Time: O(N²) | Space: O(N)
// ============================================================
class Solution1 {
public:
    int subarraysWithKDistinct(vector<int>& nums, int k) {
        int count = 0;
        for (int i = 0; i < nums.size(); i++) {
            unordered_map<int,int> freq;
            for (int j = i; j < nums.size(); j++) {
                freq[nums[j]]++;
                if ((int)freq.size() == k) count++;
                if ((int)freq.size() > k) break;
            }
        }
        return count;
    }
};

// ============================================================
// Solution 2: At Most K Decomposition (Optimal)
// Time: O(N) | Space: O(N)
// ============================================================
class Solution2 {
public:
    int subarraysWithKDistinct(vector<int>& nums, int k) {
        // exactly(k) = atMost(k) - atMost(k-1)
        return atMostK(nums, k) - atMostK(nums, k - 1);
    }

    int atMostK(vector<int>& nums, int k) {
        unordered_map<int, int> freq;
        int left = 0, count = 0;

        for (int right = 0; right < nums.size(); right++) {
            freq[nums[right]]++;

            while ((int)freq.size() > k) {
                freq[nums[left]]--;
                if (freq[nums[left]] == 0) freq.erase(nums[left]);
                left++;
            }

            count += right - left + 1; // All valid subarrays ending at right
        }

        return count;
    }
};
