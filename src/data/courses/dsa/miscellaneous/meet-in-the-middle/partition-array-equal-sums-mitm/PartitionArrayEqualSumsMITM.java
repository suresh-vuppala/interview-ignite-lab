// Time: O(2^(n/2) * n/2), Space: O(2^(n/2))

class PartitionArrayEqualSumsMITM {
    public boolean canPartition(int[] nums) {
        long total = 0;
        for (int num : nums) total += num;
        if (total % 2 != 0) return false;
        
        long target = total / 2;
        int n = nums.length, mid = n / 2;
        
        Set<Long> leftSums = generateSums(nums, 0, mid);
        Set<Long> rightSums = generateSums(nums, mid, n);
        
        for (long rightSum : rightSums) {
            if (leftSums.contains(target - rightSum)) return true;
        }
        
        return false;
    }
    
    private Set<Long> generateSums(int[] nums, int start, int end) {
        Set<Long> sums = new HashSet<>();
        int len = end - start;
        for (int mask = 0; mask < (1 << len); mask++) {
            long sum = 0;
            for (int i = 0; i < len; i++) {
                if ((mask & (1 << i)) != 0) sum += nums[start + i];
            }
            sums.add(sum);
        }
        return sums;
    }
}
