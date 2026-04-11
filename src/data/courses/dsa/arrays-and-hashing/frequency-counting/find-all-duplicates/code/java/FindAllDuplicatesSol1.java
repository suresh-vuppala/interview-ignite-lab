class Solution {
    public List<Integer> findDuplicates(int[] nums) {
        Set<Integer> seen = new HashSet<>();
        List<Integer> res = new ArrayList<>();
        for (int n : nums) { if (!seen.add(n)) res.add(n); }
        return res;
    }
}