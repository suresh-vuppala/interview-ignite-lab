// Time: O(N) | Space: O(1)

class Solution {
    public int[] singleNumber(int[] nums) {
        int xor = 0;
        for (int num : nums) xor ^= num;
        
        int rightmost = xor & -xor;
        int a = 0, b = 0;
        for (int num : nums) {
            if ((num & rightmost) != 0)
                a ^= num;
            else
                b ^= num;
        }
        return new int[]{a, b};
    }
}