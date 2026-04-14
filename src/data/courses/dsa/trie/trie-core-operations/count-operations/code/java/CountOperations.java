// ============================================================
// Solution 1: HashMap counting
// Time: O(N*L) prefix count — scan all words
// ============================================================
import java.util.*;
class Solution1 {
    Map<String,Integer> map = new HashMap<>();
    public void insert(String w) { map.merge(w, 1, Integer::sum); }
    public int countWordsEqualTo(String w) { return map.getOrDefault(w, 0); }
    public int countWordsStartingWith(String prefix) {
        int count = 0;
        for (var e : map.entrySet())
            if (e.getKey().startsWith(prefix)) count += e.getValue();
        return count;
    }
}

// ============================================================
// Solution 2: Optimal (Trie-based)
// ============================================================
class CountOperations {
    class TrieNode {
        TrieNode[] children = new TrieNode[26];
        int wordCount = 0;
        int prefixCount = 0;
    }
    
    private TrieNode root = new TrieNode();
    
    public void insert(String word) {
        TrieNode node = root;
        for (char c : word.toCharArray()) {
            int idx = c - 'a';
            if (node.children[idx] == null) {
                node.children[idx] = new TrieNode();
            }
            node = node.children[idx];
            node.prefixCount++;
        }
        node.wordCount++;
    }
    
    public int countWordsEqualTo(String word) {
        TrieNode node = root;
        for (char c : word.toCharArray()) {
            int idx = c - 'a';
            if (node.children[idx] == null) return 0;
            node = node.children[idx];
        }
        return node.wordCount;
    }
    
    public int countWordsStartingWith(String prefix) {
        TrieNode node = root;
        for (char c : prefix.toCharArray()) {
            int idx = c - 'a';
            if (node.children[idx] == null) return 0;
            node = node.children[idx];
        }
        return node.prefixCount;
    }
}
