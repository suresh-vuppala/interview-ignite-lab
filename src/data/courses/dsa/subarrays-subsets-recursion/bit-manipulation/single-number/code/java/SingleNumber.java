// Time: O(N) | Space: O(1)

class Solution {
    public int singleNumber(int[] nums) {
        int result = 0;
        for (int num : nums)
            result ^= num;
        return result;
    }
}