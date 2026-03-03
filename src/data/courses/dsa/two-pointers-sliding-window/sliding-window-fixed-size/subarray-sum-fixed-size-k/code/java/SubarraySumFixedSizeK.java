class SubarraySumFixedK {
    public List<Integer> subarraySum(int[] arr, int k) {
        List<Integer> res = new ArrayList<>();
        int sum = 0;
        for (int i = 0; i < arr.length; i++) {
            sum += arr[i];
            if (i >= k - 1) {
                res.add(sum);
                sum -= arr[i - k + 1];
            }
        }
        return res;
    }
}