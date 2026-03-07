// Time: O(N * log(sum - max))
// Space: O(1)

class SplitArrayLargestSum {
    public int splitArray(int[] nums, int k) {
        int left = getMax(nums), right = getSum(nums), result = right;
        
        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (canSplit(nums, k, mid)) {
                result = mid;
                right = mid - 1;
            } else {
                left = mid + 1;
            }
        }
        return result;
    }
    
    private boolean canSplit(int[] nums, int k, int maxSum) {
        int subarrays = 1, currentSum = 0;
        for (int num : nums) {
            if (currentSum + num > maxSum) {
                subarrays++;
                currentSum = num;
            } else {
                currentSum += num;
            }
        }
        return subarrays <= k;
    }
    
    private int getMax(int[] arr) {
        int max = arr[0];
        for (int num : arr) max = Math.max(max, num);
        return max;
    }
    
    private int getSum(int[] arr) {
        int sum = 0;
        for (int num : arr) sum += num;
        return sum;
    }
}
