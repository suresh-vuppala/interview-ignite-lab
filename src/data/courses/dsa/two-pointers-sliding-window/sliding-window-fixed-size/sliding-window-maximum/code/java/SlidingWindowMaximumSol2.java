class Solution {
    public int[] maxSlidingWindow(int[] nums, int k) {
        Deque<Integer> dq = new ArrayDeque<>();
        int[] res = new int[nums.length-k+1]; int idx=0;
        for (int i=0;i<nums.length;i++) {
            while(!dq.isEmpty()&&dq.peekFirst()<i-k+1) dq.pollFirst();
            while(!dq.isEmpty()&&nums[dq.peekLast()]<=nums[i]) dq.pollLast();
            dq.offerLast(i);
            if(i>=k-1) res[idx++]=nums[dq.peekFirst()];
        } return res;
    }
}