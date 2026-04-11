class Solution {
public:
    // Counting Sort: Two passes
    void sortColors(vector<int>& nums) {
        int count[3] = {};
        for (int n : nums) count[n]++;         // Pass 1: Count
        int idx = 0;
        for (int c = 0; c < 3; c++)            // Pass 2: Write
            for (int i = 0; i < count[c]; i++)
                nums[idx++] = c;
    }
};