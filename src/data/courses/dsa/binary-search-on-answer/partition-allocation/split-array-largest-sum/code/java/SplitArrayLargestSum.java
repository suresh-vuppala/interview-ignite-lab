// Time: O(N * log(sum - max))
// Space: O(1)

class SplitArrayLargestSum {
    public int splitArray(int[] nums, int k) {
        int n = nums.length;
        
        // Binary search range
        int low = getMax(nums);   // Minimum possible answer
        int high = getSum(nums);  // Maximum possible answer
        int result = high;
        
        while (low <= high) {
            int mid = low + (high - low) / 2;
            
            // Check if we can split with max sum = mid
            if (canSplit(nums, n, k, mid)) {
                result = mid;      // This works, try smaller
                high = mid - 1;
            } else {
                low = mid + 1;     // Too small, need larger limit
            }
        }
        
        return result;
    }
    
    private boolean canSplit(int[] nums, int n, int k, int maxSum) {
        int subarrayCount = 1;     // Start with first subarray
        int currentSum = 0;        // Sum of current subarray
        
        for (int i = 0; i < n; i++) {
            // If a single element is larger than our limit, impossible
            if (nums[i] > maxSum) return false;
            
            // Try to add current element to current subarray
            if (currentSum + nums[i] <= maxSum) {
                currentSum += nums[i];  // Add to current subarray
            } else {
                // Current subarray's limit reached, start new subarray
                subarrayCount++;
                currentSum = nums[i];   // Start new subarray with current element
                
                // If we need more subarrays than allowed, this limit is too small
                if (subarrayCount > k) return false;
            }
        }
        
        // Successfully split into k or fewer subarrays within the limit
        return true;
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
