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
// Time: O(L + log N) | Space: O(N)

class TSTNode {
    char ch;
    TSTNode left, middle, right;
    boolean isEnd = false;
    
    TSTNode(char c) {
        this.ch = c;
    }
}

class TernarySearchTree {
    private TSTNode root;
    
    public void insert(String word) {
        root = insert(root, word, 0);
    }
    
    private TSTNode insert(TSTNode node, String word, int index) {
        char ch = word.charAt(index);
        if (node == null) node = new TSTNode(ch);
        
        if (ch < node.ch) {
            node.left = insert(node.left, word, index);
        } else if (ch > node.ch) {
            node.right = insert(node.right, word, index);
        } else {
            if (index < word.length() - 1) {
                node.middle = insert(node.middle, word, index + 1);
            } else {
                node.isEnd = true;
            }
        }
        return node;
    }
    
    public boolean search(String word) {
        TSTNode node = search(root, word, 0);
        return node != null && node.isEnd;
    }
    
    private TSTNode search(TSTNode node, String word, int index) {
        if (node == null) return null;
        
        char ch = word.charAt(index);
        if (ch < node.ch) {
            return search(node.left, word, index);
        } else if (ch > node.ch) {
            return search(node.right, word, index);
        } else {
            if (index == word.length() - 1) return node;
            return search(node.middle, word, index + 1);
        }
    }
}
