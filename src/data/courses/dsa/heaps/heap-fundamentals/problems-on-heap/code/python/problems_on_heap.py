import heapq
from collections import Counter

class ProblemsOnHeap:
    def topKFrequent(self, nums, k):
        count = Counter(nums)
        
        heap = []
        for num, freq in count.items():
            heapq.heappush(heap, (freq, num))
            if len(heap) > k:
                heapq.heappop(heap)
        
        return [num for freq, num in heap]
