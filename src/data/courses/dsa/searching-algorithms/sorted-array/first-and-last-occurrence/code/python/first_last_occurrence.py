from typing import List

def find_first(arr: List[int], target: int) -> int:
    low, high = 0, len(arr) - 1
    boundary = -1
    while low <= high:
        mid = (low + high) // 2
        if arr[mid] == target:
            boundary = mid
            high = mid - 1
        elif arr[mid] < target:
            low = mid + 1
        else:
            high = mid - 1
    return boundary


def find_last(arr: List[int], target: int) -> int:
    low, high = 0, len(arr) - 1
    boundary = -1
    while low <= high:
        mid = (low + high) // 2
        if arr[mid] == target:
            boundary = mid
            low = mid + 1
        elif arr[mid] < target:
            low = mid + 1
        else:
            high = mid - 1
    return boundary


def search_range(nums: List[int], target: int) -> List[int]:
    return [find_first(nums, target), find_last(nums, target)]