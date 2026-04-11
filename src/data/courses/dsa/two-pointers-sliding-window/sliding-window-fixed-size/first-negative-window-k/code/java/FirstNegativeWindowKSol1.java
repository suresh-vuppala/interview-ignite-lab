class Solution {
    public int[] firstNegative(int[] nums, int k) {
        int[] res = new int[nums.length-k+1];
        for (int i=0; i<=nums.length-k; i++) {
            for (int j=i; j<i+k; j++) if (nums[j]<0) { res[i]=nums[j]; break; }
        } return res;
    }
}