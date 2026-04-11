class Solution {
    public int removeElement(int[] nums, int val) {
        int j = 0;
        for (int n : nums) if (n != val) nums[j++] = n;
        return j;
    }
}