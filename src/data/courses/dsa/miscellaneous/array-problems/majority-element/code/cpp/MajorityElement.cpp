#include <vector>
#include <unordered_map>
#include <algorithm>
using namespace std;
// ============================================================
// Solution 1: Hash Map — Count Frequencies — O(N) Time, O(N) Space
// ============================================================
class Solution1 {
public:
    int majorityElement(vector<int>& nums) {
        unordered_map<int, int> freq;
        int n = nums.size();
        for (int x : nums) {
            freq[x]++;
            if (freq[x] > n / 2) return x;
        }
        return -1;
    }
};

// ============================================================
// Solution 2: Sort + Middle Element — O(N log N) Time, O(1) Space
// ============================================================
class Solution2 {
public:
    int majorityElement(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        return nums[nums.size() / 2];
        // Why: majority element appears > N/2 times
        // After sorting, it MUST occupy the middle index regardless of position
    }
};

// ============================================================
// Solution 3: Boyer-Moore Voting Algorithm — O(N) Time, O(1) Space
// ============================================================
class Solution3 {
public:
    int majorityElement(vector<int>& nums) {
        int candidate = nums[0], count = 1;
        for (int i = 1; i < (int)nums.size(); i++) {
            if (count == 0) { candidate = nums[i]; count = 1; }
            else if (nums[i] == candidate) count++;
            else count--;
        }
        return candidate;
        // Why it works: majority element's count can never be fully cancelled
        // Every non-majority vote cancels one majority vote, but majority has > N/2
    }
};
