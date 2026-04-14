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
import java.util.*;

class ReplaceWords {
    class TrieNode {
        TrieNode[] children = new TrieNode[26];
        boolean isEnd = false;
    }
    
    private TrieNode root = new TrieNode();
    
    public String replaceWords(List<String> dictionary, String sentence) {
        for (String word : dictionary) insert(word);
        
        String[] words = sentence.split(" ");
        for (int i = 0; i < words.length; i++) {
            words[i] = getRoot(words[i]);
        }
        return String.join(" ", words);
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
        node.isEnd = true;
    }
    
    private String getRoot(String word) {
        TrieNode node = root;
        StringBuilder prefix = new StringBuilder();
        for (char c : word.toCharArray()) {
            int idx = c - 'a';
            if (node.children[idx] == null) break;
            prefix.append(c);
            node = node.children[idx];
            if (node.isEnd) return prefix.toString();
        }
        return word;
    }
}
