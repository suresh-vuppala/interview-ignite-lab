class Solution {
    // O(n) time, O(n) space — HashSet, only start from sequence beginnings
    public int longestConsecutive(int[] nums) {
        Set<Integer> set = new HashSet<>();
        for (int n : nums) set.add(n);
        
        int maxLen = 0;
        for (int num : set) {
            // Only start if num is beginning of a sequence
            if (!set.contains(num - 1)) {
                int cur = num, len = 1;
                while (set.contains(cur + 1)) { cur++; len++; }
                maxLen = Math.max(maxLen, len);
            }
        }
        return maxLen;
    }
}