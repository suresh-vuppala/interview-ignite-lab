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

// Time: O(N*L) build, O(26^W*N*L) search | Space: O(N*L)

class TrieNode {
    Map<Character, TrieNode> children = new HashMap<>();
    boolean isEnd = false;
    String word = null;
}

class Solution {
    private TrieNode root;
    
    public Solution() {
        root = new TrieNode();
    }
    
    public void addWord(String word) {
        TrieNode node = root;
        for (char ch : word.toCharArray()) {
            node.children.putIfAbsent(ch, new TrieNode());
            node = node.children.get(ch);
        }
        node.isEnd = true;
        node.word = word;
    }
    
    public List<String> search(String pattern) {
        List<String> result = new ArrayList<>();
        dfs(root, pattern, 0, result);
        return result;
    }
    
    private void dfs(TrieNode node, String pattern, int index, List<String> result) {
        if (index == pattern.length()) {
            if (node.isEnd) result.add(node.word);
            return;
        }
        
        char ch = pattern.charAt(index);
        if (ch == '.') {
            for (TrieNode child : node.children.values()) {
                dfs(child, pattern, index + 1, result);
            }
        } else if (ch == '*') {
            dfs(node, pattern, index + 1, result);
            for (TrieNode child : node.children.values()) {
                dfs(child, pattern, index, result);
            }
        } else {
            if (node.children.containsKey(ch)) {
                dfs(node.children.get(ch), pattern, index + 1, result);
            }
        }
    }
}
