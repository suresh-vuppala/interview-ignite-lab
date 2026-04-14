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
class SumPrefixScores {
    class TrieNode {
        TrieNode[] children = new TrieNode[26];
        int count = 0; // Count of words passing through
    }
    
    private TrieNode root = new TrieNode();
    
    public int[] sumPrefixScores(String[] words) {
        // Insert all words
        for (String word : words) insert(word);
        
        // Calculate scores
        int[] result = new int[words.length];
        for (int i = 0; i < words.length; i++) {
            result[i] = getScore(words[i]);
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
            node.count++; // Increment count
        }
    }
    
    private int getScore(String word) {
        TrieNode node = root;
        int score = 0;
        for (char c : word.toCharArray()) {
            int idx = c - 'a';
            node = node.children[idx];
            score += node.count; // Sum all prefix counts
        }
        return score;
    }
}
