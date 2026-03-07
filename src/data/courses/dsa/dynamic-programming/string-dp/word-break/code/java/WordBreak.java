import java.util.*;

class Solution {
    // ==================== SOLUTION 1: RECURSIVE (BRUTE FORCE) ====================
    // Time: O(2^N) | Space: O(N)
    public boolean wordBreakRecursive(String s, List<String> wordDict) {
        Set<String> wordSet = new HashSet<>(wordDict);
        return solve(s, 0, wordSet);
    }
    
    private boolean solve(String s, int i, Set<String> wordSet) {
        if (i == s.length()) return true;
        for (int j = i + 1; j <= s.length(); j++) {
            if (wordSet.contains(s.substring(i, j)) && solve(s, j, wordSet)) {
                return true;
            }
        }
        return false;
    }
    
    // ==================== SOLUTION 2: MEMOIZATION (TOP-DOWN DP) ====================
    // Time: O(N²) | Space: O(N)
    public boolean wordBreakMemo(String s, List<String> wordDict) {
        Set<String> wordSet = new HashSet<>(wordDict);
        Map<Integer, Boolean> memo = new HashMap<>();
        return solveMemo(s, 0, wordSet, memo);
    }
    
    private boolean solveMemo(String s, int i, Set<String> wordSet, Map<Integer, Boolean> memo) {
        if (i == s.length()) return true;
        if (memo.containsKey(i)) return memo.get(i);
        for (int j = i + 1; j <= s.length(); j++) {
            if (wordSet.contains(s.substring(i, j)) && solveMemo(s, j, wordSet, memo)) {
                memo.put(i, true);
                return true;
            }
        }
        memo.put(i, false);
        return false;
    }
    
    // ==================== SOLUTION 3: TABULATION (BOTTOM-UP DP) ====================
    // Time: O(N²) | Space: O(N)
    public boolean wordBreakTab(String s, List<String> wordDict) {
        Set<String> wordSet = new HashSet<>(wordDict);
        int n = s.length();
        boolean[] dp = new boolean[n + 1];
        dp[0] = true;
        for (int i = 1; i <= n; i++) {
            for (int j = 0; j < i; j++) {
                if (dp[j] && wordSet.contains(s.substring(j, i))) {
                    dp[i] = true;
                    break;
                }
            }
        }
        return dp[n];
    }
    
    // ==================== SOLUTION 4: SPACE OPTIMIZED (BFS) ====================
    // Time: O(N²) | Space: O(N)
    public boolean wordBreak(String s, List<String> wordDict) {
        Set<String> wordSet = new HashSet<>(wordDict);
        Set<Integer> visited = new HashSet<>();
        Queue<Integer> queue = new LinkedList<>();
        queue.offer(0);
        while (!queue.isEmpty()) {
            int start = queue.poll();
            if (visited.contains(start)) continue;
            visited.add(start);
            for (int end = start + 1; end <= s.length(); end++) {
                if (wordSet.contains(s.substring(start, end))) {
                    if (end == s.length()) return true;
                    queue.offer(end);
                }
            }
        }
        return false;
    }
}
