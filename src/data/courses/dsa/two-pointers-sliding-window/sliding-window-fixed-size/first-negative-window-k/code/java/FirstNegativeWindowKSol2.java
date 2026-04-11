class Solution {
    public int[] firstNegative(int[] nums, int k) {
        Deque<Integer> dq = new ArrayDeque<>();
        int[] res = new int[nums.length-k+1];
        for (int i=0; i<nums.length; i++) {
            if (nums[i]<0) dq.offer(i);
            if (i>=k-1) {
                while (!dq.isEmpty() && dq.peek()<i-k+1) dq.poll();
                res[i-k+1] = dq.isEmpty() ? 0 : nums[dq.peek()];
            }
        } return res;
    }
}