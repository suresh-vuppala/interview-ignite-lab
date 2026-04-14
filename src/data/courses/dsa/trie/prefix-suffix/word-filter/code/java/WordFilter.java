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

// Time: O(N*L²) build, O(P+S) query | Space: O(N*L²)

class TrieNode {
    Map<Character, TrieNode> children = new HashMap<>();
    int weight = -1;
}

class WordFilter {
    private TrieNode root;
    
    public WordFilter(String[] words) {
        root = new TrieNode();
        for (int weight = 0; weight < words.length; weight++) {
            String word = words[weight];
            for (int i = 0; i <= word.length(); i++) {
                String suffix = word.substring(i);
                String key = suffix + "#" + word;
                insert(key, weight);
            }
        }
    }
    
    private void insert(String word, int weight) {
        TrieNode node = root;
        for (char ch : word.toCharArray()) {
            node.children.putIfAbsent(ch, new TrieNode());
            node = node.children.get(ch);
            node.weight = weight;
        }
    }
    
    public int f(String prefix, String suffix) {
        TrieNode node = root;
        String searchKey = suffix + "#" + prefix;
        for (char ch : searchKey.toCharArray()) {
            if (!node.children.containsKey(ch)) return -1;
            node = node.children.get(ch);
        }
        return node.weight;
    }
}
