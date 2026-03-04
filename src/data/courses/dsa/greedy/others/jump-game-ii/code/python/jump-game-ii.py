def jump(nums):
    jumps, current_end, farthest = 0, 0, 0
    for i in range(len(nums) - 1):
        farthest = max(farthest, i + nums[i])  # Track farthest reachable
        if i == current_end:  # Reached end of current jump
            jumps += 1  # Make next jump
            current_end = farthest  # Update jump boundary
    return jumps