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

// Time: O(N*L*log N) build, O(L) query | Space: O(N*L)

class TrieNode {
    Map<Character, TrieNode> children = new HashMap<>();
    List<String> suggestions = new ArrayList<>();
}

class Solution {
    public List<List<String>> suggestedProducts(String[] products, String searchWord) {
        Arrays.sort(products);
        TrieNode root = new TrieNode();
        
        // Build trie with top 3 suggestions
        for (String product : products) {
            TrieNode node = root;
            for (char ch : product.toCharArray()) {
                node.children.putIfAbsent(ch, new TrieNode());
                node = node.children.get(ch);
                if (node.suggestions.size() < 3) {
                    node.suggestions.add(product);
                }
            }
        }
        
        // Query for each prefix
        List<List<String>> result = new ArrayList<>();
        TrieNode node = root;
        for (char ch : searchWord.toCharArray()) {
            if (node != null && node.children.containsKey(ch)) {
                node = node.children.get(ch);
                result.add(new ArrayList<>(node.suggestions));
            } else {
                node = null;
                result.add(new ArrayList<>());
            }
        }
        return result;
    }
}
