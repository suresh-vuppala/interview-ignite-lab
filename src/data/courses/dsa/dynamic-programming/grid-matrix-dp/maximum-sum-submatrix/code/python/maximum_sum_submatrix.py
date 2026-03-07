class Solution:
    # ==================== SOLUTION 1: BRUTE FORCE ====================
    # Time: O(M^3 * N^3) | Space: O(1)
    def maxSumSubmatrixBrute(self, matrix):
        if not matrix or not matrix[0]:
            return 0
        
        M, N = len(matrix), len(matrix[0])
        maxSum = float('-inf')
        
        for r1 in range(M):
            for r2 in range(r1, M):
                for c1 in range(N):
                    for c2 in range(c1, N):
                        currentSum = 0
                        for i in range(r1, r2 + 1):
                            for j in range(c1, c2 + 1):
                                currentSum += matrix[i][j]
                        maxSum = max(maxSum, currentSum)
        
        return maxSum
    
    # ==================== SOLUTION 2: PREFIX SUM OPTIMIZATION ====================
    # Time: O(M^2 * N^2) | Space: O(M * N)
    def maxSumSubmatrixPrefix(self, matrix):
        if not matrix or not matrix[0]:
            return 0
        
        M, N = len(matrix), len(matrix[0])
        
        # Build prefix sum matrix
        prefix = [[0] * (N + 1) for _ in range(M + 1)]
        for i in range(1, M + 1):
            for j in range(1, N + 1):
                prefix[i][j] = matrix[i-1][j-1] + prefix[i-1][j] + prefix[i][j-1] - prefix[i-1][j-1]
        
        maxSum = float('-inf')
        for r1 in range(1, M + 1):
            for r2 in range(r1, M + 1):
                for c1 in range(1, N + 1):
                    for c2 in range(c1, N + 1):
                        currentSum = prefix[r2][c2] - prefix[r1-1][c2] - prefix[r2][c1-1] + prefix[r1-1][c1-1]
                        maxSum = max(maxSum, currentSum)
        
        return maxSum
    
    # ==================== SOLUTION 3: KADANE'S ALGORITHM EXTENSION - OPTIMAL ====================
    # Time: O(M^2 * N) | Space: O(N)
    def maxSumSubmatrix(self, matrix):
        if not matrix or not matrix[0]:
            return 0
        
        M, N = len(matrix), len(matrix[0])
        maxSum = float('-inf')
        
        for top in range(M):
            temp = [0] * N
            for bottom in range(top, M):
                # Add current row to temp (column compression)
                for j in range(N):
                    temp[j] += matrix[bottom][j]
                
                # Apply Kadane's algorithm on temp array
                currentSum = 0
                for val in temp:
                    currentSum = max(val, currentSum + val)
                    maxSum = max(maxSum, currentSum)
        
        return maxSum
