// Time: O(N) | Space: O(1)

class Solution {
    public int missingNumber(int[] nums) {
        int result = nums.length;
        for (int i = 0; i < nums.length; i++)
            result ^= i ^ nums[i];
        return result;
    }
}