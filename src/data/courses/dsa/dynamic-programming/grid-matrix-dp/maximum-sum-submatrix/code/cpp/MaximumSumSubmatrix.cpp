class MaximumSumSubmatrix {
public:
    // ==================== SOLUTION 1: BRUTE FORCE ====================
    // Time: O(M^3 * N^3) | Space: O(1)
    int maxSumSubmatrixBrute(vector<vector<int>>& matrix) {
        if (matrix.empty() || matrix[0].empty()) return 0;
        
        int M = matrix.size(), N = matrix[0].size();
        int maxSum = INT_MIN;
        
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
                        maxSum = max(maxSum, currentSum);
                    }
                }
            }
        }
        
        return maxSum;
    }
    
    // ==================== SOLUTION 2: PREFIX SUM OPTIMIZATION ====================
    // Time: O(M^2 * N^2) | Space: O(M * N)
    int maxSumSubmatrixPrefix(vector<vector<int>>& matrix) {
        if (matrix.empty() || matrix[0].empty()) return 0;
        
        int M = matrix.size(), N = matrix[0].size();
        
        // Build prefix sum matrix
        vector<vector<int>> prefix(M + 1, vector<int>(N + 1, 0));
        for (int i = 1; i <= M; i++) {
            for (int j = 1; j <= N; j++) {
                prefix[i][j] = matrix[i-1][j-1] + prefix[i-1][j] + prefix[i][j-1] - prefix[i-1][j-1];
            }
        }
        
        int maxSum = INT_MIN;
        for (int r1 = 1; r1 <= M; r1++) {
            for (int r2 = r1; r2 <= M; r2++) {
                for (int c1 = 1; c1 <= N; c1++) {
                    for (int c2 = c1; c2 <= N; c2++) {
                        int currentSum = prefix[r2][c2] - prefix[r1-1][c2] - prefix[r2][c1-1] + prefix[r1-1][c1-1];
                        maxSum = max(maxSum, currentSum);
                    }
                }
            }
        }
        
        return maxSum;
    }
    
    // ==================== SOLUTION 3: KADANE'S ALGORITHM EXTENSION - OPTIMAL ====================
    // Time: O(M^2 * N) | Space: O(N)
    int maxSumSubmatrix(vector<vector<int>>& matrix) {
        if (matrix.empty() || matrix[0].empty()) return 0;
        
        int M = matrix.size(), N = matrix[0].size();
        int maxSum = INT_MIN;
        
        for (int top = 0; top < M; top++) {
            vector<int> temp(N, 0);
            for (int bottom = top; bottom < M; bottom++) {
                // Add current row to temp (column compression)
                for (int j = 0; j < N; j++) {
                    temp[j] += matrix[bottom][j];
                }
                
                // Apply Kadane's algorithm on temp array
                int currentSum = 0;
                for (int val : temp) {
                    currentSum = max(val, currentSum + val);
                    maxSum = max(maxSum, currentSum);
                }
            }
        }
        
        return maxSum;
    }
};
