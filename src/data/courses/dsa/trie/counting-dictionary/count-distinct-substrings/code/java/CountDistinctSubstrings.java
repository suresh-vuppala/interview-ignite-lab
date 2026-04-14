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
class CountDistinctSubstrings {
    class TrieNode {
        TrieNode[] children = new TrieNode[26];
    }
    
    public int countDistinct(String s) {
        TrieNode root = new TrieNode();
        int count = 0;
        
        // Insert all substrings
        for (int i = 0; i < s.length(); i++) {
            TrieNode node = root;
            for (int j = i; j < s.length(); j++) {
                int idx = s.charAt(j) - 'a';
                if (node.children[idx] == null) {
                    node.children[idx] = new TrieNode();
                    count++; // New unique substring
                }
                node = node.children[idx];
            }
        }
        return count + 1; // +1 for empty string
    }
}
