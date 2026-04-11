class Solution {
    // O(n) time, O(1) space — Negate value at index to mark visited
    public List<Integer> findDuplicates(int[] nums) {
        List<Integer> result = new ArrayList<>();
        for (int num : nums) {
            int idx = Math.abs(num) - 1;
            if (nums[idx] < 0) result.add(idx + 1); // Already seen
            else nums[idx] = -nums[idx]; // Mark visited
        }
        return result;
    }
}