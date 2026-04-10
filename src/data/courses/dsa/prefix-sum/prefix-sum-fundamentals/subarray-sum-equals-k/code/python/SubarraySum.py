from typing import List

def subarraySum(nums: List[int], k: int) -> int:
    n = len(nums)
    PS = [0] * (n + 1)
    PS[0] = 0
    for i in range(1, n + 1):
        PS[i] = PS[i - 1] + nums[i - 1]

    freq = {0: 1}  # prefix sum 0 appears once
    count = 0

    for end in range(1, n + 1):
        target = PS[end] - k
        count += freq.get(target, 0)
        freq[PS[end]] = freq.get(PS[end], 0) + 1

    return count