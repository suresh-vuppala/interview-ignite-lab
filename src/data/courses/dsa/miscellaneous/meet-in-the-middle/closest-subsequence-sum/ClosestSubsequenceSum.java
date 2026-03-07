// Time: O(2^(n/2) * n), Space: O(2^(n/2))

class ClosestSubsequenceSum {
    public int minAbsDifference(int[] nums, int goal) {
        int n = nums.length, mid = n / 2;
        
        List<Integer> leftSums = generateSums(nums, 0, mid);
        List<Integer> rightSums = generateSums(nums, mid, n);
        
        Collections.sort(leftSums);
        
        int minDiff = Math.abs(goal);
        
        for (int rightSum : rightSums) {
            int need = goal - rightSum;
            int idx = Collections.binarySearch(leftSums, need);
            
            if (idx < 0) idx = -(idx + 1);
            
            if (idx < leftSums.size()) {
                minDiff = Math.min(minDiff, Math.abs(leftSums.get(idx) + rightSum - goal));
            }
            if (idx > 0) {
                minDiff = Math.min(minDiff, Math.abs(leftSums.get(idx - 1) + rightSum - goal));
            }
        }
        
        return minDiff;
    }
    
    private List<Integer> generateSums(int[] nums, int start, int end) {
        List<Integer> sums = new ArrayList<>();
        int len = end - start;
        for (int mask = 0; mask < (1 << len); mask++) {
            int sum = 0;
            for (int i = 0; i < len; i++) {
                if ((mask & (1 << i)) != 0) sum += nums[start + i];
            }
            sums.add(sum);
        }
        return sums;
    }
}
