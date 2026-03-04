def can_jump(nums):
    max_reach = 0  # Maximum index we can reach
    for i in range(len(nums)):
        if i > max_reach:
            return False  # Can't reach this index
        max_reach = max(max_reach, i + nums[i])  # Update max reach
    return True