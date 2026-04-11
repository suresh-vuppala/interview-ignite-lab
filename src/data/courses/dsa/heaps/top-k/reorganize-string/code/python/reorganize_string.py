class Solution:
    def reorganizeString(self, s: str) -> str:
        import heapq
        from collections import Counter
        freq = Counter(s)
        heap = [(-f, c) for c, f in freq.items()]
        heapq.heapify(heap)
        result = []
        while len(heap) > 1:
            f1, c1 = heapq.heappop(heap)
            f2, c2 = heapq.heappop(heap)
            result.extend([c1, c2])
            if f1 + 1 < 0: heapq.heappush(heap, (f1+1, c1))
            if f2 + 1 < 0: heapq.heappush(heap, (f2+1, c2))
        if heap:
            if -heap[0][0] > 1: return ""
            result.append(heap[0][1])
        return ''.join(result)