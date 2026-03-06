class Solution:
    # ==================== SOLUTION 1: RECURSIVE (BRUTE FORCE) ====================
    # Time: O(2^n) | Space: O(n)
    def binaryStringsRecursive(self, n):
        def solveEnd0(i):
            if i == 1: return 1
            return solveEnd0(i-1) + solveEnd1(i-1)
        
        def solveEnd1(i):
            if i == 1: return 1
            return solveEnd0(i-1)
        
        return solveEnd0(n) + solveEnd1(n)
    
    # ==================== SOLUTION 2: MEMOIZATION (TOP-DOWN DP) ====================
    # Time: O(n) | Space: O(n)
    def binaryStringsMemo(self, n):
        memo0 = {}
        memo1 = {}
        
        def solveEnd0(i):
            if i == 1: return 1
            if i in memo0: return memo0[i]
            memo0[i] = solveEnd0(i-1) + solveEnd1(i-1)
            return memo0[i]
        
        def solveEnd1(i):
            if i == 1: return 1
            if i in memo1: return memo1[i]
            memo1[i] = solveEnd0(i-1)
            return memo1[i]
        
        return solveEnd0(n) + solveEnd1(n)
    
    # ==================== SOLUTION 3: TABULATION (BOTTOM-UP DP) ====================
    # Time: O(n) | Space: O(n)
    def binaryStringsTab(self, n):
        if n == 1: return 2
        
        end0 = [0] * (n + 1)
        end1 = [0] * (n + 1)
        end0[1], end1[1] = 1, 1
        
        for i in range(2, n + 1):
            end0[i] = end0[i-1] + end1[i-1]
            end1[i] = end0[i-1]
        
        return end0[n] + end1[n]
    
    # ==================== SOLUTION 4: SPACE OPTIMIZED ====================
    # Time: O(n) | Space: O(1)
    def countBinaryStrings(self, n):
        if n == 1: return 2
        
        prev_end0, prev_end1 = 1, 1
        
        for i in range(2, n + 1):
            curr_end0 = prev_end0 + prev_end1
            curr_end1 = prev_end0
            prev_end0, prev_end1 = curr_end0, curr_end1
        
        return prev_end0 + prev_end1
    
    # ==================== ALTERNATIVE: FIBONACCI PATTERN ====================
    # Time: O(n) | Space: O(1)
    def countBinaryStringsFib(self, n):
        if n == 1: return 2
        prev2, prev1 = 2, 3  # f(1)=2, f(2)=3
        for i in range(3, n + 1):
            curr = prev1 + prev2
            prev2, prev1 = prev1, curr
        return prev1
