public class MaxOnesInRow {
    // ==================== SOLUTION 1: BRUTE FORCE ====================
    // Time: O(M×N) | Space: O(1)
    public int maxOnesRowBruteForce(int[][] matrix) {
        int maxCount = 0;
        int maxRow = 0;
        
        for (int i = 0; i < matrix.length; i++) {
            int count = 0;
            for (int val : matrix[i]) {
                count += val;
            }
            if (count > maxCount) {
                maxCount = count;
                maxRow = i;
            }
        }
        
        return maxRow;
    }
    
    // ==================== SOLUTION 2: BRUTE FORCE WITH EARLY TERMINATION ====================
    // Time: O(M×N) | Space: O(1)
    public int maxOnesRowEarlyStop(int[][] matrix) {
        int maxCount = 0;
        int maxRow = 0;
        int n = matrix[0].length;
        
        for (int i = 0; i < matrix.length; i++) {
            int count = 0;
            for (int j = 0; j < n; j++) {
                if (matrix[i][j] == 1) {
                    count++;
                }
            }
            if (count > maxCount) {
                maxCount = count;
                maxRow = i;
            }
            if (maxCount == n) {
                break;
            }
        }
        
        return maxRow;
    }
    
    // ==================== SOLUTION 3: BINARY SEARCH ON EACH ROW ====================
    // Time: O(M×log N) | Space: O(1)
    public int maxOnesRowBinarySearch(int[][] matrix) {
        int maxCount = 0;
        int maxRow = 0;
        int n = matrix[0].length;
        
        for (int i = 0; i < matrix.length; i++) {
            int firstOne = findFirstOne(matrix[i]);
            int count = (firstOne != -1) ? n - firstOne : 0;
            
            if (count > maxCount) {
                maxCount = count;
                maxRow = i;
            }
        }
        
        return maxRow;
    }
    
    private int findFirstOne(int[] arr) {
        int left = 0, right = arr.length - 1;
        int result = -1;
        
        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (arr[mid] == 1) {
                result = mid;
                right = mid - 1;
            } else {
                left = mid + 1;
            }
        }
        
        return result;
    }
    
    // ==================== SOLUTION 4: STAIRCASE FROM TOP-RIGHT ====================
    // Time: O(M+N) | Space: O(1)
    public int maxOnesRowStaircaseTopRight(int[][] matrix) {
        if (matrix == null || matrix.length == 0 || matrix[0].length == 0) {
            return 0;
        }
        
        int row = 0, col = matrix[0].length - 1;
        int maxRow = 0;
        
        while (row < matrix.length && col >= 0) {
            if (matrix[row][col] == 1) {
                maxRow = row;
                col--;
            } else {
                row++;
            }
        }
        
        return maxRow;
    }
    
    // ==================== SOLUTION 5: STAIRCASE WITH COUNT TRACKING - OPTIMAL ====================
    // Time: O(M+N) | Space: O(1)
    public int maxOnesRow(int[][] matrix) {
        if (matrix == null || matrix.length == 0 || matrix[0].length == 0) {
            return 0;
        }
        
        int m = matrix.length, n = matrix[0].length;
        int row = 0, col = n - 1;
        int maxRow = 0;
        int maxCount = 0;
        
        while (row < m) {
            while (col >= 0 && matrix[row][col] == 1) {
                col--;
            }
            
            int count = n - col - 1;
            if (count > maxCount) {
                maxCount = count;
                maxRow = row;
            }
            
            row++;
        }
        
        return maxRow;
    }
}
