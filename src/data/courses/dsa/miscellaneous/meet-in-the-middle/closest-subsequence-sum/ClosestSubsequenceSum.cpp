// Time: O(2^(n/2) * n), Space: O(2^(n/2))

class ClosestSubsequenceSum {
public:
    int minAbsDifference(vector<int>& nums, int goal) {
        int n = nums.size(), mid = n / 2;
        
        vector<int> leftSums = generateSums(nums, 0, mid);
        vector<int> rightSums = generateSums(nums, mid, n);
        
        sort(leftSums.begin(), leftSums.end());
        
        int minDiff = abs(goal);
        
        for (int rightSum : rightSums) {
            int need = goal - rightSum;
            auto it = lower_bound(leftSums.begin(), leftSums.end(), need);
            
            if (it != leftSums.end()) {
                minDiff = min(minDiff, abs(*it + rightSum - goal));
            }
            if (it != leftSums.begin()) {
                minDiff = min(minDiff, abs(*(--it) + rightSum - goal));
            }
        }
        
        return minDiff;
    }
    
private:
    vector<int> generateSums(vector<int>& nums, int start, int end) {
        vector<int> sums;
        int len = end - start;
        for (int mask = 0; mask < (1 << len); mask++) {
            int sum = 0;
            for (int i = 0; i < len; i++) {
                if (mask & (1 << i)) sum += nums[start + i];
            }
            sums.push_back(sum);
        }
        return sums;
    }
};
