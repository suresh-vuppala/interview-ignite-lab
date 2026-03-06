class Solution:
    # ==================== SOLUTION 1: RECURSIVE (BRUTE FORCE) ====================
    # Time: O(2^n) | Space: O(n)
    def tilingRecursive(self, n):
        def solveFull(i):
            if i == 0: return 1
            if i == 1: return 1
            if i < 0: return 0
            return solveFull(i-1) + solveFull(i-2) + 2 * solvePartial(i-1)
        
        def solvePartial(i):
            if i == 0: return 0
            if i == 1: return 1
            if i < 0: return 0
            return solveFull(i-2) + solvePartial(i-1)
        
        return solveFull(n)
    
    # ==================== SOLUTION 2: MEMOIZATION (TOP-DOWN DP) ====================
    # Time: O(n) | Space: O(n)
    def tilingMemo(self, n):
        memoFull = {}
        memoPartial = {}
        
        def solveFull(i):
            if i == 0: return 1
            if i == 1: return 1
            if i < 0: return 0
            if i in memoFull: return memoFull[i]
            memoFull[i] = solveFull(i-1) + solveFull(i-2) + 2 * solvePartial(i-1)
            return memoFull[i]
        
        def solvePartial(i):
            if i == 0: return 0
            if i == 1: return 1
            if i < 0: return 0
            if i in memoPartial: return memoPartial[i]
            memoPartial[i] = solveFull(i-2) + solvePartial(i-1)
            return memoPartial[i]
        
        return solveFull(n)
    
    # ==================== SOLUTION 3: TABULATION (BOTTOM-UP DP) ====================
    # Time: O(n) | Space: O(n)
    def tilingTab(self, n):
        if n == 0: return 1
        if n == 1: return 1
        
        full = [0] * (n + 1)
        partial = [0] * (n + 1)
        full[0], full[1] = 1, 1
        partial[0], partial[1] = 0, 1
        
        for i in range(2, n + 1):
            full[i] = full[i-1] + full[i-2] + 2 * partial[i-1]
            partial[i] = full[i-2] + partial[i-1]
        
        return full[n]
    
    # ==================== SOLUTION 4: SPACE OPTIMIZED ====================
    # Time: O(n) | Space: O(1)
    def numTilings(self, n):
        if n == 0: return 1
        if n == 1: return 1
        
        full_prev2, full_prev1 = 1, 1
        partial_prev2, partial_prev1 = 0, 1
        
        for i in range(2, n + 1):
            full_curr = full_prev1 + full_prev2 + 2 * partial_prev1
            partial_curr = full_prev2 + partial_prev1
            full_prev2, full_prev1 = full_prev1, full_curr
            partial_prev2, partial_prev1 = partial_prev1, partial_curr
        
        return full_prev1
