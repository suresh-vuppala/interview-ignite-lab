class Solution {
    public boolean findPair(int[] nums, int target) {
        for (int i=0;i<nums.length;i++)
            for (int j=i+1;j<nums.length;j++)
                if (Math.abs(nums[i]-nums[j])==target) return true;
        return false;
    }
}