// ============================================================
// Solution 1: Brute Force — Linear scan all words O(N*L)
// ============================================================
import java.util.*;
class Solution1 {
    List<String> words = new ArrayList<>();
    public void addWord(String word) { words.add(word); }
    public List<String> search(String query) {
        List<String> result = new ArrayList<>();
        for (String w : words) {
            boolean match = w.length() == query.length();
            if (match) for (int i = 0; i < query.length(); i++)
                if (query.charAt(i) != '.' && query.charAt(i) != w.charAt(i)) { match = false; break; }
            if (match) result.add(w);
        }
        return result;
    }
}
// ============================================================
// Solution 2: Optimal (Trie-based)
// ============================================================
: Optimal (Trie-based)
// ============================================================
import java.util.*;

// Time: O(L) add, O(26^W*L) search | Space: O(N*L)

class TrieNode {
    Map<Character, TrieNode> children = new HashMap<>();
    boolean isEnd = false;
}

class WordDictionary {
    private TrieNode root;
    
    public WordDictionary() {
        root = new TrieNode();
    }
    
    public void addWord(String word) {
        TrieNode node = root;
        for (char ch : word.toCharArray()) {
            node.children.putIfAbsent(ch, new TrieNode());
            node = node.children.get(ch);
        }
        node.isEnd = true;
    }
    
    public boolean search(String word) {
        return searchHelper(word, 0, root);
    }
    
    private boolean searchHelper(String word, int index, TrieNode node) {
        if (index == word.length()) return node.isEnd;
        
        char ch = word.charAt(index);
        if (ch == '.') {
            for (TrieNode child : node.children.values()) {
                if (searchHelper(word, index + 1, child)) return true;
            }
            return false;
        } else {
            if (!node.children.containsKey(ch)) return false;
            return searchHelper(word, index + 1, node.children.get(ch));
        }
    }
}
