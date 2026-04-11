class Solution {
    public boolean findPair(int[] nums, int target) {
        Arrays.sort(nums);
        int i=0, j=1;
        while (i<nums.length && j<nums.length) {
            if (i==j) { j++; continue; }
            int d = nums[j]-nums[i];
            if (d==target) return true;
            if (d<target) j++; else i++;
        }
        return false;
    }
}