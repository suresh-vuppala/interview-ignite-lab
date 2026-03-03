import heapq

class KClosestPoints:
    def kClosest(self, points, k):
        max_heap = []
        
        for x, y in points:
            dist = -(x*x + y*y)
            heapq.heappush(max_heap, (dist, [x, y]))
            if len(max_heap) > k:
                heapq.heappop(max_heap)
        
        return [point for _, point in max_heap]
