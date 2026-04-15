#include <vector>
#include <unordered_map>
#include <algorithm>
using namespace std;
// ============================================================
// Solution 1: HashMap frequency count — O(N) Time, O(N) Space
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
        return -1; // Should never reach here if majority exists
    }
};

// ============================================================
// Solution 2: Boyer-Moore Voting — O(N) Time, O(1) Space
// ============================================================
class Solution2 {
public:
    int majorityElement(vector<int>& nums) {
        int candidate = nums[0], count = 1;
        for (int i = 1; i < (int)nums.size(); i++) {
            if (count == 0) { candidate = nums[i]; count = 1; }
            else if (nums[i] == candidate) count++;
            else count--;
        }
        return candidate; // Guaranteed to be majority element
    }
};
