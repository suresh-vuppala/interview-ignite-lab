from collections import defaultdict

class Solution:
    def longestWPI(self, hours: list[int]) -> int:
        first_occurrence = defaultdict(lambda: -1)
        first_occurrence[0] = -1
        
        prefix_sum = 0
        max_length = 0
        
        for i in range(len(hours)):
            # Add 1 for tiring day (>8), -1 for non-tiring day
            prefix_sum += 1 if hours[i] > 8 else -1
            
            # If prefix sum > 0, interval from start is well-performing
            if prefix_sum > 0:
                max_length = i + 1
            # If (prefixSum - 1) was seen before, subarray between them has sum > 0
            elif prefix_sum - 1 in first_occurrence:
                max_length = max(max_length, i - first_occurrence[prefix_sum - 1])
            
            # Store first occurrence of this prefix sum
            if prefix_sum not in first_occurrence:
                first_occurrence[prefix_sum] = i
        
        return max_length
