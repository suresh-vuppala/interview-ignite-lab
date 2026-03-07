class Solution:
    # ==================== SOLUTION 1: BRUTE FORCE ====================
    # Time: O(M×N) | Space: O(1)
    def maxOnesRowBruteForce(self, matrix):
        max_count = 0
        max_row = 0
        
        for i in range(len(matrix)):
            count = sum(matrix[i])
            if count > max_count:
                max_count = count
                max_row = i
        
        return max_row
    
    # ==================== SOLUTION 2: BRUTE FORCE WITH EARLY TERMINATION ====================
    # Time: O(M×N) | Space: O(1)
    def maxOnesRowEarlyStop(self, matrix):
        max_count = 0
        max_row = 0
        n = len(matrix[0])
        
        for i in range(len(matrix)):
            count = 0
            for j in range(n):
                if matrix[i][j] == 1:
                    count += 1
            if count > max_count:
                max_count = count
                max_row = i
            if max_count == n:
                break
        
        return max_row
    
    # ==================== SOLUTION 3: BINARY SEARCH ON EACH ROW ====================
    # Time: O(M×log N) | Space: O(1)
    def maxOnesRowBinarySearch(self, matrix):
        max_count = 0
        max_row = 0
        n = len(matrix[0])
        
        for i in range(len(matrix)):
            first_one = self._findFirstOne(matrix[i])
            count = n - first_one if first_one != -1 else 0
            
            if count > max_count:
                max_count = count
                max_row = i
        
        return max_row
    
    def _findFirstOne(self, arr):
        left, right = 0, len(arr) - 1
        result = -1
        
        while left <= right:
            mid = left + (right - left) // 2
            if arr[mid] == 1:
                result = mid
                right = mid - 1
            else:
                left = mid + 1
        
        return result
    
    # ==================== SOLUTION 4: STAIRCASE FROM TOP-RIGHT ====================
    # Time: O(M+N) | Space: O(1)
    def maxOnesRowStaircaseTopRight(self, matrix):
        if not matrix or not matrix[0]:
            return 0
        
        row, col = 0, len(matrix[0]) - 1
        max_row = 0
        
        while row < len(matrix) and col >= 0:
            if matrix[row][col] == 1:
                max_row = row
                col -= 1
            else:
                row += 1
        
        return max_row
    
    # ==================== SOLUTION 5: STAIRCASE WITH COUNT TRACKING - OPTIMAL ====================
    # Time: O(M+N) | Space: O(1)
    def maxOnesRow(self, matrix):
        if not matrix or not matrix[0]:
            return 0
        
        m, n = len(matrix), len(matrix[0])
        row, col = 0, n - 1
        max_row = 0
        max_count = 0
        
        while row < m:
            while col >= 0 and matrix[row][col] == 1:
                col -= 1
            
            count = n - col - 1
            if count > max_count:
                max_count = count
                max_row = row
            
            row += 1
        
        return max_row
