import heapq

class KthSmallestElementInSortedMatrix:
    def kthSmallest(self, matrix, k):
        n = len(matrix)
        min_heap = []
        
        for i in range(min(n, k)):
            heapq.heappush(min_heap, (matrix[i][0], i, 0))
        
        result = 0
        for _ in range(k):
            result, row, col = heapq.heappop(min_heap)
            
            if col + 1 < n:
                heapq.heappush(min_heap, (matrix[row][col + 1], row, col + 1))
        
        return result