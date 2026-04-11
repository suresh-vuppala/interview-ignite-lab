class Solution {
    public int subarraysWithKDistinct(int[] nums, int k) {
        return atMost(nums,k) - atMost(nums,k-1);
    }
    int atMost(int[] nums, int k) {
        Map<Integer,Integer> freq = new HashMap<>(); int left=0, count=0;
        for (int r=0;r<nums.length;r++) { if(freq.merge(nums[r],1,Integer::sum)==1) k--;
            while(k<0) { if(freq.merge(nums[left],-1,Integer::sum)==0) { freq.remove(nums[left]); k++; } left++; }
            count += r-left+1; }
        return count;
    }
}