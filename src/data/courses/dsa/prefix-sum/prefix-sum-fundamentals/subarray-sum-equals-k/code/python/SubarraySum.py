from collections import defaultdict

class Solution:
    def subarraySum(self, nums: list[int], k: int) -> int:
        prefix_count = defaultdict(int)
        prefix_count[0] = 1  # Base case: empty prefix with sum 0
        
        count = 0
        prefix_sum = 0
        
        for num in nums:
            prefix_sum += num
            
            # Check if (prefix_sum - k) exists in our map
            # This means we found a subarray with sum k
            if prefix_sum - k in prefix_count:
                count += prefix_count[prefix_sum - k]
            
            # Add current prefix sum to map
            prefix_count[prefix_sum] += 1
        
        return count
