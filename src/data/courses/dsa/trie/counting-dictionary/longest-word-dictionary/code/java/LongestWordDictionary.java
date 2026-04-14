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
import java.util.*;

class LongestWordDictionary {
    class TrieNode {
        TrieNode[] children = new TrieNode[26];
        boolean isEnd = false;
    }
    
    public String longestWord(String[] words) {
        TrieNode root = new TrieNode();
        for (String word : words) insert(root, word);
        
        String longest = "";
        for (String word : words) {
            if (canBuild(root, word)) {
                if (word.length() > longest.length() || 
                    (word.length() == longest.length() && word.compareTo(longest) < 0)) {
                    longest = word;
                }
            }
        }
        return longest;
    }
    
    private void insert(TrieNode root, String word) {
        TrieNode node = root;
        for (char c : word.toCharArray()) {
            int idx = c - 'a';
            if (node.children[idx] == null) node.children[idx] = new TrieNode();
            node = node.children[idx];
        }
        node.isEnd = true;
    }
    
    private boolean canBuild(TrieNode root, String word) {
        TrieNode node = root;
        for (char c : word.toCharArray()) {
            int idx = c - 'a';
            node = node.children[idx];
            if (!node.isEnd) return false;
        }
        return true;
    }
}
