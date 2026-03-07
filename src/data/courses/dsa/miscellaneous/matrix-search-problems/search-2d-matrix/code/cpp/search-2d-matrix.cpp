class Search2DMatrix {
public:
    // ==================== SOLUTION 1: BRUTE FORCE ====================
    // Time: O(M×N) | Space: O(1)
    bool searchMatrixBruteForce(vector<vector<int>>& matrix, int target) {
        for (const auto& row : matrix) {
            for (int val : row) {
                if (val == target) return true;
            }
        }
        return false;
    }
    
    // ==================== SOLUTION 2: BINARY SEARCH ON EACH ROW ====================
    // Time: O(M×log N) | Space: O(1)
    bool searchMatrixBinaryEachRow(vector<vector<int>>& matrix, int target) {
        for (const auto& row : matrix) {
            if (binarySearch(row, target)) return true;
        }
        return false;
    }
    
private:
    bool binarySearch(const vector<int>& arr, int target) {
        int left = 0, right = arr.size() - 1;
        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (arr[mid] == target) return true;
            else if (arr[mid] < target) left = mid + 1;
            else right = mid - 1;
        }
        return false;
    }
    
public:
    // ==================== SOLUTION 3: ROW ELIMINATION + BINARY SEARCH ====================
    // Time: O(M + log N) | Space: O(1)
    bool searchMatrixRowElimination(vector<vector<int>>& matrix, int target) {
        if (matrix.empty() || matrix[0].empty()) {
            return false;
        }
        
        for (const auto& row : matrix) {
            if (row[0] <= target && target <= row.back()) {
                return binarySearch(row, target);
            }
        }
        return false;
    }
    
    // ==================== SOLUTION 4: BINARY SEARCH ON ROWS + COLUMNS ====================
    // Time: O(log M + log N) | Space: O(1)
    bool searchMatrixTwoBinarySearch(vector<vector<int>>& matrix, int target) {
        if (matrix.empty() || matrix[0].empty()) {
            return false;
        }
        
        int m = matrix.size(), n = matrix[0].size();
        
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
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        if (matrix.empty() || matrix[0].empty()) {
            return false;
        }
        
        int m = matrix.size();
        int n = matrix[0].size();
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
};
