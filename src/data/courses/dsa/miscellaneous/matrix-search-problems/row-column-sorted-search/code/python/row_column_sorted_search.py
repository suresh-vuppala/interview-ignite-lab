class Solution:
    # ==================== SOLUTION 1: BRUTE FORCE ====================
    # Time: O(M×N) | Space: O(1)
    def searchBruteForce(self, matrix, target):
        for row in matrix:
            for val in row:
                if val == target:
                    return True
        return False
    
    # ==================== SOLUTION 2: BINARY SEARCH ON EACH ROW ====================
    # Time: O(M×log N) | Space: O(1)
    def searchBinaryEachRow(self, matrix, target):
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
    def searchRowElimination(self, matrix, target):
        if not matrix or not matrix[0]:
            return False
        
        # Find potential row using column comparison
        for row in matrix:
            if row[0] <= target <= row[-1]:
                return self._binarySearch(row, target)
        return False
    
    # ==================== SOLUTION 4: STAIRCASE FROM TOP-RIGHT ====================
    # Time: O(M+N) | Space: O(1)
    def searchStaircaseTopRight(self, matrix, target):
        if not matrix or not matrix[0]:
            return False
        
        row, col = 0, len(matrix[0]) - 1
        
        while row < len(matrix) and col >= 0:
            if matrix[row][col] == target:
                return True
            elif matrix[row][col] > target:
                col -= 1
            else:
                row += 1
        
        return False
    
    # ==================== SOLUTION 5: STAIRCASE FROM BOTTOM-LEFT - OPTIMAL ====================
    # Time: O(M+N) | Space: O(1)
    def searchMatrix(self, matrix, target):
        if not matrix or not matrix[0]:
            return False
        
        row, col = len(matrix) - 1, 0
        
        while row >= 0 and col < len(matrix[0]):
            if matrix[row][col] == target:
                return True
            elif matrix[row][col] > target:
                row -= 1
            else:
                col += 1
        
        return False
