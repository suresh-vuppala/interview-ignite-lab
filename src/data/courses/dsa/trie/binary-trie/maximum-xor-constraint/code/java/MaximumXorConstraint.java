// ============================================================
// Solution 1: Brute Force
// ============================================================
import java.util.*;

class Solution1 {
    // Brute force: hash set / nested loops / direct comparison
    // See Solution 2 below for optimal Trie-based approach
}

// ============================================================
// Solution 2: Optimal (Trie-based)
// ============================================================
class MaximumXorConstraint {
    class TrieNode {
        TrieNode[] children = new TrieNode[2];
    }
    
    private TrieNode root = new TrieNode();
    
    public int[] maximizeXor(int[] nums, int[][] queries) {
        // Insert all numbers into trie
        for (int num : nums) insert(num);
        
        int[] result = new int[queries.length];
        for (int i = 0; i < queries.length; i++) {
            result[i] = getMaxXor(queries[i][0], queries[i][1]);
        }
        return result;
    }
    
    private void insert(int num) {
        TrieNode node = root;
        for (int i = 31; i >= 0; i--) {
            int bit = (num >> i) & 1;
            if (node.children[bit] == null) {
                node.children[bit] = new TrieNode();
            }
            node = node.children[bit];
        }
    }
    
    private int getMaxXor(int x, int m) {
        TrieNode node = root;
        int xor = 0;
        for (int i = 31; i >= 0; i--) {
            int bit = (x >> i) & 1;
            int opposite = 1 - bit;
            if (node.children[opposite] != null) {
                xor |= (1 << i);
                node = node.children[opposite];
            } else if (node.children[bit] != null) {
                node = node.children[bit];
            } else {
                return -1;
            }
        }
        return xor <= m ? xor : -1;
    }
}
