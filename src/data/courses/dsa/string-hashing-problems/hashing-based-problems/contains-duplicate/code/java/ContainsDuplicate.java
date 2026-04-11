class Solution {
    // O(n) time, O(n) space — HashSet tracks seen elements
    public boolean containsDuplicate(int[] nums) {
        Set<Integer> seen = new HashSet<>();
        for (int num : nums) {
            if (!seen.add(num)) return true; // add returns false if already present
        }
        return false;
    }
}