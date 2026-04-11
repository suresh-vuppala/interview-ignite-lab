class Solution {
    public int minimumSize(int[] nums, int maxOps) {
        int lo=1,hi=0; for(int n:nums) hi=Math.max(hi,n);
        while(lo<hi){int mid=lo+(hi-lo)/2,ops=0; for(int n:nums) ops+=(n-1)/mid; if(ops<=maxOps)hi=mid;else lo=mid+1;}
        return lo;
    }
}