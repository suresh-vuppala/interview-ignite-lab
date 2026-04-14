// ============================================================
// Solution 1: Brute Force — HashSet / Direct comparison
// Time: O(N*L) or O(N²*L) | Space: O(N*L)
// ============================================================
import java.util.*;
class Solution1 {
    Set<String> words = new HashSet<>();
    public void insert(String word) { words.add(word); }
    public boolean hasPrefix(String prefix) {
        for (String w : words)
            if (w.startsWith(prefix)) return true;
        return false;
    }
}
// ============================================================
// Solution 2: Optimal (Trie-based)
// ============================================================
: Optimal (Trie-based)
// ============================================================
// Time: O(N²*L) | Space: O(1)

class Solution {
    public int countPrefixSuffixPairs(String[] words) {
        int count = 0;
        for (int i = 0; i < words.length; i++) {
            for (int j = i + 1; j < words.length; j++) {
                if (isPrefixAndSuffix(words[i], words[j])) {
                    count++;
                }
            }
        }
        return count;
    }
    
    private boolean isPrefixAndSuffix(String str1, String str2) {
        if (str1.length() > str2.length()) return false;
        return str2.startsWith(str1) && str2.endsWith(str1);
    }
}
