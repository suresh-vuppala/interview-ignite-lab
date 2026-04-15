import java.util.*;

// ============================================================
// Solution 1: Brute Force - Check All Pairs
// Time: O(N² × L) | Space: O(1)
// ============================================================
class Solution1 {
    public int countPrefixSuffixPairs(String[] words) {
        int count = 0;
        int n = words.length;
        
        // Check every pair (i, j) where i < j
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                // Skip if words[i] is longer than words[j]
                if (words[i].length() > words[j].length()) continue;
                
                // Check if words[i] is both prefix and suffix of words[j]
                if (isPrefixAndSuffix(words[i], words[j])) {
                    count++;
                }
            }
        }
        return count;
    }
    
    private boolean isPrefixAndSuffix(String str1, String str2) {
        // Check if str1 is both prefix and suffix of str2
        return str2.startsWith(str1) && str2.endsWith(str1);
    }
}

// ============================================================
// Solution 2: Double Trie (Prefix Trie + Suffix Trie)
// Time: O(N × L²) | Space: O(N × L)
// ============================================================
class TrieNode {
    Map<Character, TrieNode> children = new HashMap<>();
    List<Integer> wordIndices = new ArrayList<>();
}

class Solution2 {
    public int countPrefixSuffixPairs(String[] words) {
        int n = words.length;
        TrieNode prefixRoot = new TrieNode();
        TrieNode suffixRoot = new TrieNode();
        
        // Build prefix trie and suffix trie
        for (int i = 0; i < n; i++) {
            insertPrefix(prefixRoot, words[i], i);
            insertSuffix(suffixRoot, words[i], i);
        }
        
        int count = 0;
        // For each word, find matches
        for (int j = 0; j < n; j++) {
            List<Integer> prefixMatches = searchPrefix(prefixRoot, words[j]);
            List<Integer> suffixMatches = searchSuffix(suffixRoot, words[j]);
            
            // Find intersection (words that are both prefix and suffix)
            Set<Integer> suffixSet = new HashSet<>(suffixMatches);
            for (int i : prefixMatches) {
                if (i < j && suffixSet.contains(i)) {
                    count++;
                }
            }
        }
        
        return count;
    }
    
    private void insertPrefix(TrieNode root, String word, int index) {
        TrieNode node = root;
        for (char c : word.toCharArray()) {
            node.children.putIfAbsent(c, new TrieNode());
            node = node.children.get(c);
        }
        node.wordIndices.add(index);
    }
    
    private void insertSuffix(TrieNode root, String word, int index) {
        TrieNode node = root;
        // Insert reversed word
        for (int i = word.length() - 1; i >= 0; i--) {
            char c = word.charAt(i);
            node.children.putIfAbsent(c, new TrieNode());
            node = node.children.get(c);
        }
        node.wordIndices.add(index);
    }
    
    private List<Integer> searchPrefix(TrieNode root, String word) {
        List<Integer> result = new ArrayList<>();
        TrieNode node = root;
        
        for (char c : word.toCharArray()) {
            if (!node.children.containsKey(c)) break;
            node = node.children.get(c);
            result.addAll(node.wordIndices);
        }
        return result;
    }
    
    private List<Integer> searchSuffix(TrieNode root, String word) {
        List<Integer> result = new ArrayList<>();
        TrieNode node = root;
        
        // Search with reversed word
        for (int i = word.length() - 1; i >= 0; i--) {
            char c = word.charAt(i);
            if (!node.children.containsKey(c)) break;
            node = node.children.get(c);
            result.addAll(node.wordIndices);
        }
        return result;
    }
}

// ============================================================
// Solution 3: Combined Trie (Optimal)
// Time: O(N × L²) | Space: O(N × L)
// ============================================================
class PairTrieNode {
    Map<Integer, PairTrieNode> children = new HashMap<>();
    int count = 0;
}

class Solution {
    public int countPrefixSuffixPairs(String[] words) {
        PairTrieNode root = new PairTrieNode();
        int totalCount = 0;
        
        for (String word : words) {
            // Search first: count how many existing words are prefix-suffix of current word
            totalCount += search(root, word);
            
            // Then insert current word
            insert(root, word);
        }
        
        return totalCount;
    }
    
    private void insert(PairTrieNode root, String word) {
        PairTrieNode node = root;
        int len = word.length();
        
        // Traverse from both ends simultaneously
        for (int i = 0; i < len; i++) {
            int key = (word.charAt(i) << 8) | word.charAt(len - 1 - i);
            
            node.children.putIfAbsent(key, new PairTrieNode());
            node = node.children.get(key);
        }
        node.count++;
    }
    
    private int search(PairTrieNode root, String word) {
        PairTrieNode node = root;
        int len = word.length();
        int count = 0;
        
        // Traverse from both ends simultaneously
        for (int i = 0; i < len; i++) {
            int key = (word.charAt(i) << 8) | word.charAt(len - 1 - i);
            
            if (!node.children.containsKey(key)) {
                break;
            }
            node = node.children.get(key);
            count += node.count;
        }
        
        return count;
    }
}
