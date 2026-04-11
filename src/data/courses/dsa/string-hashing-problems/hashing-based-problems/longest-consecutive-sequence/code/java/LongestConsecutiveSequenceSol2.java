class Solution {
    // Optimal: O(n) — Only count from sequence beginnings
    public int longestConsecutive(int[] nums) {
        Set<Integer> set = new HashSet<>();
        for (int n : nums) set.add(n);
        int max = 0;
        for (int num : set) {
            if (!set.contains(num-1)) { // Sequence beginning
                int cur = num, len = 1;
                while (set.contains(cur+1)) { cur++; len++; }
                max = Math.max(max, len);
            }
        }
        return max;
    }
}