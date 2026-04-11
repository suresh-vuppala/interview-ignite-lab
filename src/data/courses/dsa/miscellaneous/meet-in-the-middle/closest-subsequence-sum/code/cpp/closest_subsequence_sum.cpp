class Solution {
public:
    // O(2^(n/2) * log) — Meet in the Middle
    int minAbsDifference(vector<int>& nums, int goal) {
        int n = nums.size(), half = n / 2;
        vector<int> left, right;
        for (int m = 0; m < (1<<half); m++) { int s=0; for(int i=0;i<half;i++) if(m&(1<<i)) s+=nums[i]; left.push_back(s); }
        for (int m = 0; m < (1<<(n-half)); m++) { int s=0; for(int i=0;i<n-half;i++) if(m&(1<<i)) s+=nums[half+i]; right.push_back(s); }
        sort(right.begin(), right.end());
        int best = INT_MAX;
        for (int s : left) {
            int need = goal - s;
            auto it = lower_bound(right.begin(), right.end(), need);
            if (it != right.end()) best = min(best, abs(s + *it - goal));
            if (it != right.begin()) best = min(best, abs(s + *prev(it) - goal));
        }
        return best;
    }
};