class Solution {
    // Hash Set: O(n) time, O(n) space
    public int firstMissingPositive(int[] nums) {
        Set<Integer> set = new HashSet<>();
        for (int n : nums) set.add(n);
        for (int i = 1; i <= nums.length + 1; i++)
            if (!set.contains(i)) return i;
        return nums.length + 1;
    }
}