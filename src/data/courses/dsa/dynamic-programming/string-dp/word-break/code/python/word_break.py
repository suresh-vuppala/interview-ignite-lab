class Solution:
    # ==================== SOLUTION 1: RECURSIVE (BRUTE FORCE) ====================
    # Time: O(2^N) | Space: O(N)
    def wordBreakRecursive(self, s, wordDict):
        wordSet = set(wordDict)
        def solve(i):
            if i == len(s): return True
            for j in range(i + 1, len(s) + 1):
                if s[i:j] in wordSet and solve(j):
                    return True
            return False
        return solve(0)
    
    # ==================== SOLUTION 2: MEMOIZATION (TOP-DOWN DP) ====================
    # Time: O(N²) | Space: O(N)
    def wordBreakMemo(self, s, wordDict):
        wordSet = set(wordDict)
        memo = {}
        def solve(i):
            if i == len(s): return True
            if i in memo: return memo[i]
            for j in range(i + 1, len(s) + 1):
                if s[i:j] in wordSet and solve(j):
                    memo[i] = True
                    return True
            memo[i] = False
            return False
        return solve(0)
    
    # ==================== SOLUTION 3: TABULATION (BOTTOM-UP DP) ====================
    # Time: O(N²) | Space: O(N)
    def wordBreakTab(self, s, wordDict):
        wordSet = set(wordDict)
        n = len(s)
        dp = [False] * (n + 1)
        dp[0] = True
        for i in range(1, n + 1):
            for j in range(i):
                if dp[j] and s[j:i] in wordSet:
                    dp[i] = True
                    break
        return dp[n]
    
    # ==================== SOLUTION 4: SPACE OPTIMIZED (BFS) ====================
    # Time: O(N²) | Space: O(N)
    def wordBreak(self, s, wordDict):
        wordSet = set(wordDict)
        visited = set()
        queue = [0]
        while queue:
            start = queue.pop(0)
            if start in visited: continue
            visited.add(start)
            for end in range(start + 1, len(s) + 1):
                if s[start:end] in wordSet:
                    if end == len(s): return True
                    queue.append(end)
        return False
