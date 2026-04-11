class Solution:
    def topKFrequent(self, nums: List[int], k: int) -> List[int]:
        from collections import Counter
        freq = Counter(nums)
        # Bucket sort: O(n)
        buckets = [[] for _ in range(len(nums) + 1)]
        for num, f in freq.items(): buckets[f].append(num)
        result = []
        for i in range(len(buckets)-1, -1, -1):
            result.extend(buckets[i])
            if len(result) >= k: return result[:k]
        return result