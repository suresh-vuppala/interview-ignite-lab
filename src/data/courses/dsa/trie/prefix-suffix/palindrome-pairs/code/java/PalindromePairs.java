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

// Time: O(N*L²) | Space: O(N*L)

class TrieNode {
    Map<Character, TrieNode> children = new HashMap<>();
    int index = -1;
    List<Integer> palindromeSuffixes = new ArrayList<>();
}

class Solution {
    public List<List<Integer>> palindromePairs(String[] words) {
        TrieNode root = new TrieNode();
        
        // Build trie with reversed words
        for (int i = 0; i < words.length; i++) {
            TrieNode node = root;
            String word = words[i];
            for (int j = word.length() - 1; j >= 0; j--) {
                if (isPalindrome(word, 0, j)) {
                    node.palindromeSuffixes.add(i);
                }
                char ch = word.charAt(j);
                node.children.putIfAbsent(ch, new TrieNode());
                node = node.children.get(ch);
            }
            node.index = i;
            node.palindromeSuffixes.add(i);
        }
        
        List<List<Integer>> result = new ArrayList<>();
        for (int i = 0; i < words.length; i++) {
            TrieNode node = root;
            String word = words[i];
            for (int j = 0; j < word.length(); j++) {
                if (node.index >= 0 && node.index != i && isPalindrome(word, j, word.length() - 1)) {
                    result.add(Arrays.asList(i, node.index));
                }
                char ch = word.charAt(j);
                if (!node.children.containsKey(ch)) break;
                node = node.children.get(ch);
            }
            if (node != null) {
                for (int idx : node.palindromeSuffixes) {
                    if (idx != i) {
                        result.add(Arrays.asList(i, idx));
                    }
                }
            }
        }
        return result;
    }
    
    private boolean isPalindrome(String word, int left, int right) {
        while (left < right) {
            if (word.charAt(left++) != word.charAt(right--)) return false;
        }
        return true;
    }
}
