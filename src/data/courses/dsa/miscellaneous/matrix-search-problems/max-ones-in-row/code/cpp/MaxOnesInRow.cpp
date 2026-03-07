class MaxOnesInRow {
public:
    // ==================== SOLUTION 1: BRUTE FORCE ====================
    // Time: O(M×N) | Space: O(1)
    int maxOnesRowBruteForce(vector<vector<int>>& matrix) {
        int maxCount = 0;
        int maxRow = 0;
        
        for (int i = 0; i < matrix.size(); i++) {
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
    int maxOnesRowEarlyStop(vector<vector<int>>& matrix) {
        int maxCount = 0;
        int maxRow = 0;
        int n = matrix[0].size();
        
        for (int i = 0; i < matrix.size(); i++) {
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
    int maxOnesRowBinarySearch(vector<vector<int>>& matrix) {
        int maxCount = 0;
        int maxRow = 0;
        int n = matrix[0].size();
        
        for (int i = 0; i < matrix.size(); i++) {
            int firstOne = findFirstOne(matrix[i]);
            int count = (firstOne != -1) ? n - firstOne : 0;
            
            if (count > maxCount) {
                maxCount = count;
                maxRow = i;
            }
        }
        
        return maxRow;
    }
    
private:
    int findFirstOne(const vector<int>& arr) {
        int left = 0, right = arr.size() - 1;
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
    
public:
    // ==================== SOLUTION 4: STAIRCASE FROM TOP-RIGHT ====================
    // Time: O(M+N) | Space: O(1)
    int maxOnesRowStaircaseTopRight(vector<vector<int>>& matrix) {
        if (matrix.empty() || matrix[0].empty()) {
            return 0;
        }
        
        int row = 0, col = matrix[0].size() - 1;
        int maxRow = 0;
        
        while (row < matrix.size() && col >= 0) {
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
    int maxOnesRow(vector<vector<int>>& matrix) {
        if (matrix.empty() || matrix[0].empty()) {
            return 0;
        }
        
        int m = matrix.size(), n = matrix[0].size();
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
};
