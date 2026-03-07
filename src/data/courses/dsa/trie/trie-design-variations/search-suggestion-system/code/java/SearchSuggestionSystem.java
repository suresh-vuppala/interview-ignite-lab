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
