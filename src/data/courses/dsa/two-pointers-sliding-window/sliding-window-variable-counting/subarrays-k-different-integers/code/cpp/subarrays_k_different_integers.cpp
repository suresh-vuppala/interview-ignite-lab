class Solution {
public:
    // O(n) — exactly(k) = atMost(k) - atMost(k-1)
    int subarraysWithKDistinct(vector<int>& nums, int k) {
        return atMost(nums, k) - atMost(nums, k - 1);
    }
    int atMost(vector<int>& nums, int k) {
        unordered_map<int, int> freq;
        int left = 0, count = 0;
        for (int right = 0; right < nums.size(); right++) {
            if (++freq[nums[right]] == 1) k--; // New distinct element
            while (k < 0) { // Too many distinct
                if (--freq[nums[left]] == 0) k++;
                left++;
            }
            count += right - left + 1; // All subarrays ending at right
        }
        return count;
    }
};