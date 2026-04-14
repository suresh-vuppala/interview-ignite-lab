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
class LongestCommonPrefix {
    class TrieNode {
        TrieNode[] children = new TrieNode[26];
        boolean isEnd = false;
    }
    
    private TrieNode root = new TrieNode();
    
    public String longestCommonPrefix(String[] strs) {
        if (strs == null || strs.length == 0) return "";
        
        // Insert all words into trie
        for (String word : strs) {
            insert(word);
        }
        
        // Traverse trie to find common prefix
        StringBuilder prefix = new StringBuilder();
        TrieNode node = root;
        
        while (true) {
            // Count non-null children
            int childCount = 0;
            int childIdx = -1;
            for (int i = 0; i < 26; i++) {
                if (node.children[i] != null) {
                    childCount++;
                    childIdx = i;
                }
            }
            
            // Stop if branching or end of word
            if (childCount != 1 || node.isEnd) break;
            
            prefix.append((char)('a' + childIdx)); // Add character to prefix
            node = node.children[childIdx]; // Move to child
        }
        
        return prefix.toString();
    }
    
    private void insert(String word) {
        TrieNode node = root;
        for (char c : word.toCharArray()) {
            int idx = c - 'a';
            if (node.children[idx] == null) {
                node.children[idx] = new TrieNode();
            }
            node = node.children[idx];
        }
        node.isEnd = true; // Mark end of word
    }
}
