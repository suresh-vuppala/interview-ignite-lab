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
