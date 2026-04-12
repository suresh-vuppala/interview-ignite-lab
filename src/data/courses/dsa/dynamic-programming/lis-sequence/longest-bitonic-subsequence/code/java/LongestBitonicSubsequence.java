class Solution {
    public int longestBitonic(int[] nums) {
        int n=nums.length; int[] inc=new int[n],dec=new int[n];
        java.util.Arrays.fill(inc,1); java.util.Arrays.fill(dec,1);
        for(int i=1;i<n;i++) for(int j=0;j<i;j++) if(nums[j]<nums[i]) inc[i]=Math.max(inc[i],inc[j]+1);
        for(int i=n-2;i>=0;i--) for(int j=n-1;j>i;j--) if(nums[j]<nums[i]) dec[i]=Math.max(dec[i],dec[j]+1);
        int max=0; for(int i=0;i<n;i++) max=Math.max(max,inc[i]+dec[i]-1); return max;
    }
}