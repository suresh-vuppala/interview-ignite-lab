from collections import defaultdict
def distinct_in_window(nums, k):
    freq, result = defaultdict(int), []
    for i in range(len(nums)):
        freq[nums[i]] += 1
        if i >= k:
            freq[nums[i-k]] -= 1
            if freq[nums[i-k]] == 0: del freq[nums[i-k]]
        if i >= k-1: result.append(len(freq))
    return result