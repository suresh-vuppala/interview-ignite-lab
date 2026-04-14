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

// Time: O(N*L) build, O(L+K) query | Space: O(N*L)

class TrieNode {
    Map<Character, TrieNode> children = new HashMap<>();
    List<Integer> indices = new ArrayList<>();
}

class Solution {
    private TrieNode forwardTrie;
    private TrieNode reverseTrie;
    
    public Solution() {
        forwardTrie = new TrieNode();
        reverseTrie = new TrieNode();
    }
    
    public void build(String[] words) {
        for (int i = 0; i < words.length; i++) {
            // Forward trie
            TrieNode node = forwardTrie;
            for (char ch : words[i].toCharArray()) {
                node.children.putIfAbsent(ch, new TrieNode());
                node = node.children.get(ch);
            }
            node.indices.add(i);
            
            // Reverse trie
            node = reverseTrie;
            for (int j = words[i].length() - 1; j >= 0; j--) {
                char ch = words[i].charAt(j);
                node.children.putIfAbsent(ch, new TrieNode());
                node = node.children.get(ch);
            }
            node.indices.add(i);
        }
    }
    
    public List<Integer> search(String prefix, String suffix) {
        // Prefix matches
        TrieNode node = forwardTrie;
        for (char ch : prefix.toCharArray()) {
            if (!node.children.containsKey(ch)) return new ArrayList<>();
            node = node.children.get(ch);
        }
        List<Integer> prefixIndices = collectAll(node);
        
        // Suffix matches
        node = reverseTrie;
        for (int i = suffix.length() - 1; i >= 0; i--) {
            char ch = suffix.charAt(i);
            if (!node.children.containsKey(ch)) return new ArrayList<>();
            node = node.children.get(ch);
        }
        List<Integer> suffixIndices = collectAll(node);
        
        // Intersection
        Set<Integer> prefixSet = new HashSet<>(prefixIndices);
        List<Integer> result = new ArrayList<>();
        for (int idx : suffixIndices) {
            if (prefixSet.contains(idx)) {
                result.add(idx);
            }
        }
        return result;
    }
    
    private List<Integer> collectAll(TrieNode node) {
        List<Integer> result = new ArrayList<>(node.indices);
        for (TrieNode child : node.children.values()) {
            result.addAll(collectAll(child));
        }
        return result;
    }
}
