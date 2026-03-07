// Time: O(2^(n/2) * n/2), Space: O(2^(n/2))

class PartitionArrayEqualSumsMITM {
public:
    bool canPartition(vector<int>& nums) {
        long long total = 0;
        for (int num : nums) total += num;
        if (total % 2 != 0) return false;
        
        long long target = total / 2;
        int n = nums.size(), mid = n / 2;
        
        unordered_set<long long> leftSums = generateSums(nums, 0, mid);
        unordered_set<long long> rightSums = generateSums(nums, mid, n);
        
        for (long long rightSum : rightSums) {
            if (leftSums.count(target - rightSum)) return true;
        }
        
        return false;
    }
    
private:
    unordered_set<long long> generateSums(vector<int>& nums, int start, int end) {
        unordered_set<long long> sums;
        int len = end - start;
        for (int mask = 0; mask < (1 << len); mask++) {
            long long sum = 0;
            for (int i = 0; i < len; i++) {
                if (mask & (1 << i)) sum += nums[start + i];
            }
            sums.insert(sum);
        }
        return sums;
    }
};
