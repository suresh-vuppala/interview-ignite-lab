class Solution {
    // Extra Array: O(n) space
    public int removeDuplicates(int[] nums) {
        List<Integer> uniq = new ArrayList<>();
        uniq.add(nums[0]);
        for (int i = 1; i < nums.length; i++)
            if (nums[i] != uniq.get(uniq.size()-1)) uniq.add(nums[i]);
        for (int i = 0; i < uniq.size(); i++) nums[i] = uniq.get(i);
        return uniq.size();
    }
}