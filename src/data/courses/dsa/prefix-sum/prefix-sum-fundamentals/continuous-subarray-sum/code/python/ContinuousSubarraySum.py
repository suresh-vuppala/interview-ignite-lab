from collections import defaultdict

class Solution:
    def checkSubarraySum(self, nums: list[int], k: int) -> bool:
        mod_map = defaultdict(lambda: -1)
        mod_map[0] = -1  # Initialize with 0 modulo at index -1
        
        prefix_sum = 0
        
        for i in range(len(nums)):
            prefix_sum += nums[i]
            mod = prefix_sum % k
            
            # Check if we've seen this modulo before
            if mod in mod_map:
                # Check if the subarray length is at least 2
                if i - mod_map[mod] >= 2:
                    return True
            else:
                # Store first occurrence of this modulo
                mod_map[mod] = i
        
        return False
