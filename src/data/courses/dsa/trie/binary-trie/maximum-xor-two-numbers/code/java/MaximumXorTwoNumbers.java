// ============================================================
// Solution 1: Check all pairs — O(N²)
// ============================================================
class Solution1 {
    public int findMaximumXOR(int[] nums) {
        int max = 0;
        for (int i = 0; i < nums.length; i++)
            for (int j = i+1; j < nums.length; j++)
                max = Math.max(max, nums[i] ^ nums[j]);
        return max;
    }
}

// ============================================================
// Solution 2: Binary Trie — O(N*32) = O(N)
// ============================================================
class Solution2 {
    int[][] ch = new int[3200001][2]; int cnt = 0;
    void insert(int num) { int n=0; for(int i=31;i>=0;i--){int b=(num>>i)&1;if(ch[n][b]==0)ch[n][b]=++cnt;n=ch[n][b];}}
    int query(int num) { int n=0,xor_val=0; for(int i=31;i>=0;i--){int b=(num>>i)&1,opp=1-b;if(ch[n][opp]!=0){xor_val|=(1<<i);n=ch[n][opp];}else n=ch[n][b];}return xor_val;}
    public int findMaximumXOR(int[] nums) {
        for(int num:nums) insert(num);
        int max=0; for(int num:nums) max=Math.max(max,query(num)); return max;
    }
}
