class RowColumnSortedSearch {
public:
    // ==================== SOLUTION 1: BRUTE FORCE ====================
    // Time: O(M×N) | Space: O(1)
    bool searchBruteForce(vector<vector<int>>& matrix, int target) {
        for (const auto& row : matrix) {
            for (int val : row) {
                if (val == target) return true;
            }
        }
        return false;
    }
    
    // ==================== SOLUTION 2: BINARY SEARCH ON EACH ROW ====================
    // Time: O(M×log N) | Space: O(1)
    bool searchBinaryEachRow(vector<vector<int>>& matrix, int target) {
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
    bool searchRowElimination(vector<vector<int>>& matrix, int target) {
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
    
    // ==================== SOLUTION 4: STAIRCASE FROM TOP-RIGHT ====================
    // Time: O(M+N) | Space: O(1)
    bool searchStaircaseTopRight(vector<vector<int>>& matrix, int target) {
        if (matrix.empty() || matrix[0].empty()) {
            return false;
        }
        
        int row = 0, col = matrix[0].size() - 1;
        
        while (row < matrix.size() && col >= 0) {
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
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        if (matrix.empty() || matrix[0].empty()) {
            return false;
        }
        
        int row = matrix.size() - 1, col = 0;
        
        while (row >= 0 && col < matrix[0].size()) {
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
};
