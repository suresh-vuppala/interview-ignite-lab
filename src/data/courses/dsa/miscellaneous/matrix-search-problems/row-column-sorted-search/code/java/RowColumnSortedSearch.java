public class RowColumnSortedSearch {
    // ==================== SOLUTION 1: BRUTE FORCE ====================
    // Time: O(M×N) | Space: O(1)
    public boolean searchBruteForce(int[][] matrix, int target) {
        for (int[] row : matrix) {
            for (int val : row) {
                if (val == target) return true;
            }
        }
        return false;
    }
    
    // ==================== SOLUTION 2: BINARY SEARCH ON EACH ROW ====================
    // Time: O(M×log N) | Space: O(1)
    public boolean searchBinaryEachRow(int[][] matrix, int target) {
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
    public boolean searchRowElimination(int[][] matrix, int target) {
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
    
    // ==================== SOLUTION 4: STAIRCASE FROM TOP-RIGHT ====================
    // Time: O(M+N) | Space: O(1)
    public boolean searchStaircaseTopRight(int[][] matrix, int target) {
        if (matrix == null || matrix.length == 0 || matrix[0].length == 0) {
            return false;
        }
        
        int row = 0, col = matrix[0].length - 1;
        
        while (row < matrix.length && col >= 0) {
            if (matrix[row][col] == target) {
                return true;
            } else if (matrix[row][col] > target) {
                col--;
            } else {
                row++;
            }
        }
        
        return false;
    }
    
    // ==================== SOLUTION 5: STAIRCASE FROM BOTTOM-LEFT - OPTIMAL ====================
    // Time: O(M+N) | Space: O(1)
    public boolean searchMatrix(int[][] matrix, int target) {
        if (matrix == null || matrix.length == 0 || matrix[0].length == 0) {
            return false;
        }
        
        int row = matrix.length - 1, col = 0;
        
        while (row >= 0 && col < matrix[0].length) {
            if (matrix[row][col] == target) {
                return true;
            } else if (matrix[row][col] > target) {
                row--;
            } else {
                col++;
            }
        }
        
        return false;
    }
}
