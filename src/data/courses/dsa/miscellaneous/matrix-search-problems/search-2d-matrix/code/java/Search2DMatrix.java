public class Search2DMatrix {
    // ==================== SOLUTION 1: BRUTE FORCE ====================
    // Time: O(M×N) | Space: O(1)
    public boolean searchMatrixBruteForce(int[][] matrix, int target) {
        for (int[] row : matrix) {
            for (int val : row) {
                if (val == target) return true;
            }
        }
        return false;
    }
    
    // ==================== SOLUTION 2: BINARY SEARCH ON EACH ROW ====================
    // Time: O(M×log N) | Space: O(1)
    public boolean searchMatrixBinaryEachRow(int[][] matrix, int target) {
        for (int[] row : matrix) {
            if (binarySearch(row, target)) return true;
        }
        return false;
    }
    
    private boolean binarySearch(int[] arr, int target) {
        int left = 0, right = arr.length - 1;
        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (arr[mid] == target) return true;
            else if (arr[mid] < target) left = mid + 1;
            else right = mid - 1;
        }
        return false;
    }
    
    // ==================== SOLUTION 3: ROW ELIMINATION + BINARY SEARCH ====================
    // Time: O(M + log N) | Space: O(1)
    public boolean searchMatrixRowElimination(int[][] matrix, int target) {
        if (matrix == null || matrix.length == 0 || matrix[0].length == 0) {
            return false;
        }
        
        for (int[] row : matrix) {
            if (row[0] <= target && target <= row[row.length - 1]) {
                return binarySearch(row, target);
            }
        }
        return false;
    }
    
    // ==================== SOLUTION 4: BINARY SEARCH ON ROWS + COLUMNS ====================
    // Time: O(log M + log N) | Space: O(1)
    public boolean searchMatrixTwoBinarySearch(int[][] matrix, int target) {
        if (matrix == null || matrix.length == 0 || matrix[0].length == 0) {
            return false;
        }
        
        int m = matrix.length, n = matrix[0].length;
        
        // Binary search to find the row
        int top = 0, bottom = m - 1;
        while (top <= bottom) {
            int mid = top + (bottom - top) / 2;
            if (matrix[mid][0] <= target && target <= matrix[mid][n - 1]) {
                return binarySearch(matrix[mid], target);
            } else if (matrix[mid][0] > target) {
                bottom = mid - 1;
            } else {
                top = mid + 1;
            }
        }
        
        return false;
    }
    
    // ==================== SOLUTION 5: TREAT AS 1D ARRAY - OPTIMAL ====================
    // Time: O(log(M×N)) | Space: O(1)
    public boolean searchMatrix(int[][] matrix, int target) {
        if (matrix == null || matrix.length == 0 || matrix[0].length == 0) {
            return false;
        }
        
        int m = matrix.length;
        int n = matrix[0].length;
        int left = 0, right = m * n - 1;
        
        while (left <= right) {
            int mid = left + (right - left) / 2;
            int row = mid / n;
            int col = mid % n;
            
            if (matrix[row][col] == target) {
                return true;
            } else if (matrix[row][col] < target) {
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }
        
        return false;
    }
}
