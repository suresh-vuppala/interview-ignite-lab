// ============================================================
// Word Ladder
// ============================================================
import java.util.*;
class Solution {
    public int ladderLength(String beginWord, String endWord, List<String> wordList) {
        Set<String> set = new HashSet<>(wordList);
        if (!set.contains(endWord)) return 0;
        Queue<String> q = new LinkedList<>(); q.add(beginWord); int steps = 1;
        while (!q.isEmpty()) {
            int size = q.size(); steps++;
            for (int i = 0; i < size; i++) {
                char[] word = q.poll().toCharArray();
                for (int j = 0; j < word.length; j++) {
                    char orig = word[j];
                    for (char c = 'a'; c <= 'z'; c++) {
                        word[j] = c;
                        String s = new String(word);
                        if (s.equals(endWord)) return steps;
                        if (set.contains(s)) { set.remove(s); q.add(s); }
                    }
                    word[j] = orig;
                }
            }
        }
        return 0;
    }
}
