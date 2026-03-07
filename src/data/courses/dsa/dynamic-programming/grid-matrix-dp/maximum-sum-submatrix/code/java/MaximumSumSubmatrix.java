class MaximumSumSubmatrix {
    // ==================== SOLUTION 1: BRUTE FORCE ====================
    // Time: O(M^3 * N^3) | Space: O(1)
    public int maxSumSubmatrixBrute(int[][] matrix) {
        if (matrix == null || matrix.length == 0) return 0;
        
        int M = matrix.length, N = matrix[0].length;
        int maxSum = Integer.MIN_VALUE;
        
        for (int r1 = 0; r1 < M; r1++) {
            for (int r2 = r1; r2 < M; r2++) {
                for (int c1 = 0; c1 < N; c1++) {
                    for (int c2 = c1; c2 < N; c2++) {
                        int currentSum = 0;
                        for (int i = r1; i <= r2; i++) {
                            for (int j = c1; j <= c2; j++) {
                                currentSum += matrix[i][j];
                            }
                        }
                        maxSum = Math.max(maxSum, currentSum);
                    }
                }
            }
        }
        
        return maxSum;
    }
    
    // ==================== SOLUTION 2: PREFIX SUM OPTIMIZATION ====================
    // Time: O(M^2 * N^2) | Space: O(M * N)
    public int maxSumSubmatrixPrefix(int[][] matrix) {
        if (matrix == null || matrix.length == 0) return 0;
        
        int M = matrix.length, N = matrix[0].length;
        
        // Build prefix sum matrix
        int[][] prefix = new int[M + 1][N + 1];
        for (int i = 1; i <= M; i++) {
            for (int j = 1; j <= N; j++) {
                prefix[i][j] = matrix[i-1][j-1] + prefix[i-1][j] + prefix[i][j-1] - prefix[i-1][j-1];
            }
        }
        
        int maxSum = Integer.MIN_VALUE;
        for (int r1 = 1; r1 <= M; r1++) {
            for (int r2 = r1; r2 <= M; r2++) {
                for (int c1 = 1; c1 <= N; c1++) {
                    for (int c2 = c1; c2 <= N; c2++) {
                        int currentSum = prefix[r2][c2] - prefix[r1-1][c2] - prefix[r2][c1-1] + prefix[r1-1][c1-1];
                        maxSum = Math.max(maxSum, currentSum);
                    }
                }
            }
        }
        
        return maxSum;
    }
    
    // ==================== SOLUTION 3: KADANE'S ALGORITHM EXTENSION - OPTIMAL ====================
    // Time: O(M^2 * N) | Space: O(N)
    public int maxSumSubmatrix(int[][] matrix) {
        if (matrix == null || matrix.length == 0) return 0;
        
        int M = matrix.length, N = matrix[0].length;
        int maxSum = Integer.MIN_VALUE;
        
        for (int top = 0; top < M; top++) {
            int[] temp = new int[N];
            for (int bottom = top; bottom < M; bottom++) {
                // Add current row to temp (column compression)
                for (int j = 0; j < N; j++) {
                    temp[j] += matrix[bottom][j];
                }
                
                // Apply Kadane's algorithm on temp array
                int currentSum = 0;
                for (int val : temp) {
                    currentSum = Math.max(val, currentSum + val);
                    maxSum = Math.max(maxSum, currentSum);
                }
            }
        }
        
        return maxSum;
    }
}
