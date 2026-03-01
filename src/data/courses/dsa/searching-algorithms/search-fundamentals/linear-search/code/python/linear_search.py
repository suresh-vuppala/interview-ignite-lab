def linear_search(nums, target):
    """
    Linear search - scan elements sequentially until target found
    Time: O(n), Space: O(1)
    """
    for i in range(len(nums)):
        if nums[i] == target:
            return i
    return -1

if __name__ == "__main__":
    nums = [3, 1, 4, 1, 5, 9, 2, 6]
    target = 5
    
    result = linear_search(nums, target)
    print(f"Index: {result}")  # Output: 4
