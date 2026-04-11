class Solution {
    public int[] distinctInWindow(int[] nums, int k) {
        Map<Integer,Integer> freq = new HashMap<>();
        int[] res = new int[nums.length-k+1];
        for (int i=0;i<nums.length;i++) {
            freq.merge(nums[i],1,Integer::sum);
            if (i>=k) { freq.merge(nums[i-k],-1,Integer::sum); if(freq.get(nums[i-k])==0)freq.remove(nums[i-k]); }
            if (i>=k-1) res[i-k+1]=freq.size();
        } return res;
    }
}