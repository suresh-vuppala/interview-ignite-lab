class MaxSumSubarrayK {
    public int maxSum(int[] arr, int k) {
        int sum = 0, maxSum = Integer.MIN_VALUE;
        for (int i = 0; i < arr.length; i++) {
            sum += arr[i];
            if (i >= k - 1) {
                maxSum = Math.max(maxSum, sum);
                sum -= arr[i - k + 1];
            }
        }
        return maxSum;
    }
}