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

// Time: O(L) all operations | Space: O(N) nodes

class RadixNode {
    Map<Character, RadixNode> children = new HashMap<>();
    boolean isEnd = false;
    String edgeLabel = "";
}

class CompressedTrie {
    private RadixNode root;
    
    public CompressedTrie() {
        root = new RadixNode();
    }
    
    public void insert(String word) {
        RadixNode node = root;
        int i = 0;
        
        while (i < word.length()) {
            char ch = word.charAt(i);
            if (!node.children.containsKey(ch)) {
                RadixNode newNode = new RadixNode();
                newNode.edgeLabel = word.substring(i);
                newNode.isEnd = true;
                node.children.put(ch, newNode);
                return;
            }
            
            RadixNode child = node.children.get(ch);
            String label = child.edgeLabel;
            int j = 0;
            
            while (j < label.length() && i < word.length() && label.charAt(j) == word.charAt(i)) {
                i++; j++;
            }
            
            if (j < label.length()) {
                // Split edge
                RadixNode splitNode = new RadixNode();
                splitNode.edgeLabel = label.substring(0, j);
                splitNode.children.put(label.charAt(j), child);
                child.edgeLabel = label.substring(j);
                node.children.put(ch, splitNode);
                
                if (i < word.length()) {
                    RadixNode newNode = new RadixNode();
                    newNode.edgeLabel = word.substring(i);
                    newNode.isEnd = true;
                    splitNode.children.put(word.charAt(i), newNode);
                } else {
                    splitNode.isEnd = true;
                }
                return;
            }
            node = child;
        }
        node.isEnd = true;
    }
    
    public boolean search(String word) {
        RadixNode node = root;
        int i = 0;
        
        while (i < word.length()) {
            char ch = word.charAt(i);
            if (!node.children.containsKey(ch)) return false;
            
            RadixNode child = node.children.get(ch);
            String label = child.edgeLabel;
            
            for (char c : label.toCharArray()) {
                if (i >= word.length() || word.charAt(i) != c) return false;
                i++;
            }
            node = child;
        }
        return node.isEnd;
    }
}
