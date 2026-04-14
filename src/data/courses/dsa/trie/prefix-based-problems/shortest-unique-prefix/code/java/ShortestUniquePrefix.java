// ============================================================
// Solution 1: Brute Force — HashSet / Direct comparison
// Time: O(N*L) or O(N²*L) | Space: O(N*L)
// ============================================================
import java.util.*;
class Solution1 {
    Set<String> words = new HashSet<>();
    public void insert(String word) { words.add(word); }
    public boolean hasPrefix(String prefix) {
        for (String w : words)
            if (w.startsWith(prefix)) return true;
        return false;
    }
}
// ============================================================
// Solution 2: Optimal (Trie-based)
// ============================================================
: Optimal (Trie-based)
// ============================================================
class ShortestUniquePrefix {
    class TrieNode {
        TrieNode[] children = new TrieNode[26];
        int prefixCount = 0; // Count of words passing through
    }
    
    private TrieNode root = new TrieNode();
    
    public String[] shortestUniquePrefixes(String[] words) {
        // Build trie with prefix counts
        for (String word : words) {
            insert(word);
        }
        
        // Find shortest unique prefix for each word
        String[] result = new String[words.length];
        for (int i = 0; i < words.length; i++) {
            result[i] = findPrefix(words[i]);
        }
        return result;
    }
    
    private void insert(String word) {
        TrieNode node = root;
        for (char c : word.toCharArray()) {
            int idx = c - 'a';
            if (node.children[idx] == null) {
                node.children[idx] = new TrieNode();
            }
            node = node.children[idx];
            node.prefixCount++; // Increment count
        }
    }
    
    private String findPrefix(String word) {
        TrieNode node = root;
        StringBuilder prefix = new StringBuilder();
        
        for (char c : word.toCharArray()) {
            int idx = c - 'a';
            prefix.append(c);
            node = node.children[idx];
            
            if (node.prefixCount == 1) {
                return prefix.toString(); // Unique prefix found
            }
        }
        return word; // Entire word is the prefix
    }
}
