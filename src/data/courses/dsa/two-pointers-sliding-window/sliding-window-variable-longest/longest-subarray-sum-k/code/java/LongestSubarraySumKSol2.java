class Solution {
    public int longestSubarray(int[] nums, int k) {
        int l=0, sum=0, max=0;
        for (int r=0;r<nums.length;r++) { sum+=nums[r]; while(sum>k) sum-=nums[l++]; max=Math.max(max,r-l+1); }
        return max;
    }
}