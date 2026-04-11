class Solution {
    public void sortColors(int[] nums) {
        int[] cnt = new int[3];
        for (int n : nums) cnt[n]++;
        int idx = 0;
        for (int c = 0; c < 3; c++) for (int i = 0; i < cnt[c]; i++) nums[idx++] = c;
    }
}