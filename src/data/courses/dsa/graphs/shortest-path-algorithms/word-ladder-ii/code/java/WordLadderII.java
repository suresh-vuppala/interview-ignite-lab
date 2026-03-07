import java.util.*;

public class WordLadderII {
    
    // ==================== SOLUTION 1: BFS + DFS (TWO-PASS) ====================
    // Time: O(N×L² + P×L) | Space: O(N×L + P×L)
    
    public static List<List<String>> findLadders(String beginWord, String endWord, List<String> wordList) {
        /*
         * Phase 1: BFS to build parent relationships.
         * Phase 2: DFS to backtrack and construct all paths.
         */
        Set<String> wordSet = new HashSet<>(wordList);
        List<List<String>> result = new ArrayList<>();
        
        if (!wordSet.contains(endWord)) return result;
        
        // BFS Phase: Build parent relationships
        Map<String, List<String>> parents = new HashMap<>();
        Map<String, Integer> level = new HashMap<>();
        Queue<String> queue = new LinkedList<>();
        
        queue.offer(beginWord);
        level.put(beginWord, 0);
        boolean found = false;
        int currentLevel = 0;
        
        while (!queue.isEmpty() && !found) {
            int size = queue.size();
            currentLevel++;
            Set<String> visitedThisLevel = new HashSet<>();
            
            for (int i = 0; i < size; i++) {
                String word = queue.poll();
                char[] chars = word.toCharArray();
                
                for (int j = 0; j < chars.length; j++) {
                    char old = chars[j];
                    
                    for (char c = 'a'; c <= 'z'; c++) {
                        chars[j] = c;
                        String nextWord = new String(chars);
                        
                        if (wordSet.contains(nextWord)) {
                            if (!level.containsKey(nextWord)) {
                                visitedThisLevel.add(nextWord);
                                parents.computeIfAbsent(nextWord, k -> new ArrayList<>()).add(word);
                                
                                if (nextWord.equals(endWord)) {
                                    found = true;
                                }
                            } else if (level.get(nextWord) == currentLevel) {
                                parents.get(nextWord).add(word);
                            }
                        }
                    }
                    
                    chars[j] = old;
                }
            }
            
            for (String word : visitedThisLevel) {
                level.put(word, currentLevel);
                queue.offer(word);
            }
        }
        
        // DFS Phase: Construct paths
        if (found) {
            List<String> path = new ArrayList<>();
            path.add(endWord);
            dfs(endWord, beginWord, parents, path, result);
        }
        
        return result;
    }
    
    private static void dfs(String word, String beginWord, Map<String, List<String>> parents,
                           List<String> path, List<List<String>> result) {
        if (word.equals(beginWord)) {
            List<String> newPath = new ArrayList<>(path);
            Collections.reverse(newPath);
            result.add(newPath);
            return;
        }
        
        if (parents.containsKey(word)) {
            for (String parent : parents.get(word)) {
                path.add(parent);
                dfs(parent, beginWord, parents, path, result);
                path.remove(path.size() - 1);
            }
        }
    }
    
    
    // ==================== SOLUTION 2: BFS LEVEL-BY-LEVEL ====================
    // Time: O(N×L² + P×L) | Space: O(P×L)
    
    public static List<List<String>> findLaddersLevelByLevel(String beginWord, String endWord, List<String> wordList) {
        /*
         * Build paths incrementally level by level.
         * More space-efficient than storing parent map.
         */
        Set<String> wordSet = new HashSet<>(wordList);
        List<List<String>> result = new ArrayList<>();
        
        if (!wordSet.contains(endWord)) return result;
        
        List<List<String>> currentPaths = new ArrayList<>();
        currentPaths.add(Arrays.asList(beginWord));
        
        while (!currentPaths.isEmpty()) {
            // Remove words used in current level
            for (List<String> path : currentPaths) {
                wordSet.remove(path.get(path.size() - 1));
            }
            
            List<List<String>> nextPaths = new ArrayList<>();
            for (List<String> path : currentPaths) {
                String word = path.get(path.size() - 1);
                
                if (word.equals(endWord)) {
                    result.add(new ArrayList<>(path));
                    continue;
                }
                
                char[] chars = word.toCharArray();
                for (int i = 0; i < chars.length; i++) {
                    char old = chars[i];
                    for (char c = 'a'; c <= 'z'; c++) {
                        chars[i] = c;
                        String nextWord = new String(chars);
                        if (wordSet.contains(nextWord)) {
                            List<String> newPath = new ArrayList<>(path);
                            newPath.add(nextWord);
                            nextPaths.add(newPath);
                        }
                    }
                    chars[i] = old;
                }
            }
            
            if (!result.isEmpty()) return result;
            currentPaths = nextPaths;
        }
        
        return result;
    }
}
