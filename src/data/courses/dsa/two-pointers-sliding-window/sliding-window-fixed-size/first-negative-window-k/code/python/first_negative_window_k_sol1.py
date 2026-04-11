def first_negative(nums, k):
    result = []
    for i in range(len(nums)-k+1):
        found = 0
        for j in range(i, i+k):
            if nums[j] < 0: found = nums[j]; break
        result.append(found)
    return result