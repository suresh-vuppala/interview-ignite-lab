class Solution {
    public List<List<Integer>> subsetsWithDup(int[] nums) {
        Arrays.sort(nums);
        List<List<Integer>> res = new ArrayList<>();
        backtrack(nums, 0, new ArrayList<>(), res);
        return res;
    }
    void backtrack(int[] nums, int start, List<Integer> cur, List<List<Integer>> res) {
        res.add(new ArrayList<>(cur));
        for (int i = start; i < nums.length; i++) {
            if (i > start && nums[i] == nums[i-1]) continue;
            cur.add(nums[i]); backtrack(nums, i+1, cur, res); cur.remove(cur.size()-1);
        }
    }
}