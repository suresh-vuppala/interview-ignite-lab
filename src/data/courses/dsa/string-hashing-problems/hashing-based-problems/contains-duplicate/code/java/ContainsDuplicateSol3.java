class Solution {
    // Optimal: O(n) time — HashSet tracks seen elements
    public boolean containsDuplicate(int[] nums) {
        Set<Integer> seen = new HashSet<>();
        for (int num : nums)
            if (!seen.add(num)) return true; // add returns false if exists
        return false;
    }
}