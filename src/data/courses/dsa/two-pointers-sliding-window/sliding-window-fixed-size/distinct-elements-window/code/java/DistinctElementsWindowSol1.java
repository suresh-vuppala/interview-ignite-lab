class Solution {
    public int[] distinctInWindow(int[] nums, int k) {
        int[] res = new int[nums.length-k+1];
        for (int i=0;i<=nums.length-k;i++) {
            Set<Integer> s = new HashSet<>();
            for (int j=i;j<i+k;j++) s.add(nums[j]);
            res[i] = s.size();
        } return res;
    }
}