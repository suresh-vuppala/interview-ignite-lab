// ============================================================
// Solution 1: Brute Force — Check all pairs O(N²)
// ============================================================
class Solution1 {
    public int solve(int[] nums) {
        int result = 0;
        for (int i = 0; i < nums.length; i++)
            for (int j = i+1; j < nums.length; j++)
                result = Math.max(result, nums[i] ^ nums[j]);
        return result;
    }
}
// ============================================================
// Solution 2: Optimal (Trie-based)
// ============================================================
: Optimal (Trie-based)
// ============================================================
class ImplementBinaryTrie {
    class TrieNode {
        TrieNode[] children = new TrieNode[2];
    }
    
    private TrieNode root = new TrieNode();
    
    public void insert(int num) {
        TrieNode node = root;
        for (int i = 31; i >= 0; i--) {
            int bit = (num >> i) & 1;
            if (node.children[bit] == null) {
                node.children[bit] = new TrieNode();
            }
            node = node.children[bit];
        }
    }
    
    public int getMaxXor(int num) {
        TrieNode node = root;
        int maxXor = 0;
        for (int i = 31; i >= 0; i--) {
            int bit = (num >> i) & 1;
            int oppositeBit = 1 - bit;
            
            if (node.children[oppositeBit] != null) {
                maxXor |= (1 << i);
                node = node.children[oppositeBit];
            } else {
                node = node.children[bit];
            }
        }
        return maxXor;
    }
}
