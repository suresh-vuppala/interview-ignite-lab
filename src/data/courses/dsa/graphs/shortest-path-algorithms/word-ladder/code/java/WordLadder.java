import java.util.*;

public class WordLadder {
    
    // ==================== SOLUTION 1: BFS WITH NEIGHBOR GENERATION ====================
    // Time: O(N×L²×26) | Space: O(N×L)
    
    public static int ladderLengthBFS(String beginWord, String endWord, List<String> wordList) {
        /*
         * Generate all possible one-letter changes for each word.
         * Try all 26 letters at each position.
         */
        Set<String> wordSet = new HashSet<>(wordList);
        if (!wordSet.contains(endWord)) return 0;
        
        Queue<Pair> queue = new LinkedList<>();
        Set<String> visited = new HashSet<>();
        queue.offer(new Pair(beginWord, 1));
        visited.add(beginWord);
        
        while (!queue.isEmpty()) {
            Pair current = queue.poll();
            String word = current.word;
            int level = current.level;
            
            if (word.equals(endWord)) return level;
            
            char[] chars = word.toCharArray();
            for (int i = 0; i < chars.length; i++) {
                char old = chars[i];
                for (char c = 'a'; c <= 'z'; c++) {
                    chars[i] = c;
                    String nextWord = new String(chars);
                    if (wordSet.contains(nextWord) && !visited.contains(nextWord)) {
                        visited.add(nextWord);
                        queue.offer(new Pair(nextWord, level + 1));
                    }
                }
                chars[i] = old;
            }
        }
        return 0;
    }
    
    
    // ==================== SOLUTION 2: BFS WITH PATTERN MATCHING ====================
    // Time: O(N×L²) | Space: O(N×L²)
    
    public static int ladderLengthPattern(String beginWord, String endWord, List<String> wordList) {
        /*
         * Preprocess words into patterns (e.g., "hot" -> "*ot", "h*t", "ho*").
         * Words sharing a pattern are neighbors.
         */
        if (!wordList.contains(endWord)) return 0;
        
        Map<String, List<String>> patternMap = new HashMap<>();
        for (String word : wordList) {
            for (int i = 0; i < word.length(); i++) {
                String pattern = word.substring(0, i) + "*" + word.substring(i + 1);
                patternMap.computeIfAbsent(pattern, k -> new ArrayList<>()).add(word);
            }
        }
        
        Queue<Pair> queue = new LinkedList<>();
        Set<String> visited = new HashSet<>();
        queue.offer(new Pair(beginWord, 1));
        visited.add(beginWord);
        
        while (!queue.isEmpty()) {
            Pair current = queue.poll();
            String word = current.word;
            int level = current.level;
            
            if (word.equals(endWord)) return level;
            
            for (int i = 0; i < word.length(); i++) {
                String pattern = word.substring(0, i) + "*" + word.substring(i + 1);
                if (patternMap.containsKey(pattern)) {
                    for (String neighbor : patternMap.get(pattern)) {
                        if (!visited.contains(neighbor)) {
                            visited.add(neighbor);
                            queue.offer(new Pair(neighbor, level + 1));
                        }
                    }
                }
            }
        }
        return 0;
    }
    
    
    // ==================== SOLUTION 3: BIDIRECTIONAL BFS (OPTIMAL) ====================
    // Time: O(N×L²) | Space: O(N×L)
    
    public static int ladderLength(String beginWord, String endWord, List<String> wordList) {
        /*
         * Search from both beginWord and endWord simultaneously.
         * When searches meet, we found the shortest path.
         * Explores exponentially fewer nodes.
         */
        Set<String> wordSet = new HashSet<>(wordList);
        if (!wordSet.contains(endWord)) return 0;
        
        Set<String> beginSet = new HashSet<>();
        Set<String> endSet = new HashSet<>();
        Set<String> visited = new HashSet<>();
        
        beginSet.add(beginWord);
        endSet.add(endWord);
        int level = 1;
        
        while (!beginSet.isEmpty() && !endSet.isEmpty()) {
            // Always expand smaller set
            if (beginSet.size() > endSet.size()) {
                Set<String> temp = beginSet;
                beginSet = endSet;
                endSet = temp;
            }
            
            Set<String> nextSet = new HashSet<>();
            for (String word : beginSet) {
                char[] chars = word.toCharArray();
                
                for (int i = 0; i < chars.length; i++) {
                    char old = chars[i];
                    
                    for (char c = 'a'; c <= 'z'; c++) {
                        chars[i] = c;
                        String nextWord = new String(chars);
                        
                        if (endSet.contains(nextWord)) {
                            return level + 1;
                        }
                        
                        if (wordSet.contains(nextWord) && !visited.contains(nextWord)) {
                            visited.add(nextWord);
                            nextSet.add(nextWord);
                        }
                    }
                    
                    chars[i] = old;
                }
            }
            
            beginSet = nextSet;
            level++;
        }
        
        return 0;
    }
    
    // Helper class for BFS
    static class Pair {
        String word;
        int level;
        Pair(String word, int level) {
            this.word = word;
            this.level = level;
        }
    }
}
