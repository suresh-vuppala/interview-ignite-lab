class Solution:
    # ==================== SOLUTION 1: BRUTE FORCE ====================
    # Time: O(M×N) | Space: O(1)
    def searchMatrixBruteForce(self, matrix, target):
        for row in matrix:
            for val in row:
                if val == target:
                    return True
        return False
    
    # ==================== SOLUTION 2: BINARY SEARCH ON EACH ROW ====================
    # Time: O(M×log N) | Space: O(1)
    def searchMatrixBinaryEachRow(self, matrix, target):
        for row in matrix:
            if self._binarySearch(row, target):
                return True
        return False
    
    def _binarySearch(self, arr, target):
        left, right = 0, len(arr) - 1
        while left <= right:
            mid = left + (right - left) // 2
            if arr[mid] == target:
                return True
            elif arr[mid] < target:
                left = mid + 1
            else:
                right = mid - 1
        return False
    
    # ==================== SOLUTION 3: ROW ELIMINATION + BINARY SEARCH ====================
    # Time: O(M + log N) | Space: O(1)
    def searchMatrixRowElimination(self, matrix, target):
        if not matrix or not matrix[0]:
            return False
        
        for row in matrix:
            if row[0] <= target <= row[-1]:
                return self._binarySearch(row, target)
        return False
    
    # ==================== SOLUTION 4: BINARY SEARCH ON ROWS + COLUMNS ====================
    # Time: O(log M + log N) | Space: O(1)
    def searchMatrixTwoBinarySearch(self, matrix, target):
        if not matrix or not matrix[0]:
            return False
        
        m, n = len(matrix), len(matrix[0])
        
        # Binary search to find the row
        top, bottom = 0, m - 1
        while top <= bottom:
            mid = top + (bottom - top) // 2
            if matrix[mid][0] <= target <= matrix[mid][-1]:
                return self._binarySearch(matrix[mid], target)
            elif matrix[mid][0] > target:
                bottom = mid - 1
            else:
                top = mid + 1
        
        return False
    
    # ==================== SOLUTION 5: TREAT AS 1D ARRAY - OPTIMAL ====================
    # Time: O(log(M×N)) | Space: O(1)
    def searchMatrix(self, matrix, target):
        if not matrix or not matrix[0]:
            return False
        
        m, n = len(matrix), len(matrix[0])
        left, right = 0, m * n - 1
        
        while left <= right:
            mid = left + (right - left) // 2
            row, col = mid // n, mid % n
            
            if matrix[row][col] == target:
                return True
            elif matrix[row][col] < target:
                left = mid + 1
            else:
                right = mid - 1
        
        return False
