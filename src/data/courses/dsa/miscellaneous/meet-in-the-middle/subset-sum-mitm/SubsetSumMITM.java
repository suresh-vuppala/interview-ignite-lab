// Time: O(2^(n/2) * n/2), Space: O(2^(n/2))

class SubsetSumMITM {
    public boolean subsetSum(int[] arr, int target) {
        int n = arr.length, mid = n / 2;
        
        List<Long> leftSums = generateSums(arr, 0, mid);
        List<Long> rightSums = generateSums(arr, mid, n);
        
        Collections.sort(leftSums);
        
        for (long rightSum : rightSums) {
            long need = target - rightSum;
            if (Collections.binarySearch(leftSums, need) >= 0) return true;
        }
        
        return false;
    }
    
    private List<Long> generateSums(int[] arr, int start, int end) {
        List<Long> sums = new ArrayList<>();
        int len = end - start;
        for (int mask = 0; mask < (1 << len); mask++) {
            long sum = 0;
            for (int i = 0; i < len; i++) {
                if ((mask & (1 << i)) != 0) sum += arr[start + i];
            }
            sums.add(sum);
        }
        return sums;
    }
}
