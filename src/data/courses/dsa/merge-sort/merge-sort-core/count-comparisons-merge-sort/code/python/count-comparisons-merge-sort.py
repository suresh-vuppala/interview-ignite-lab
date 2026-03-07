# Time: O(N log N), Space: O(N)

def merge_sort_count(arr):
    if len(arr) <= 1:
        return arr, 0
    
    mid = len(arr) // 2
    left, left_count = merge_sort_count(arr[:mid])
    right, right_count = merge_sort_count(arr[mid:])
    merged, merge_count = merge_count(left, right)
    
    return merged, left_count + right_count + merge_count

def merge_count(left, right):
    result = []
    count = 0
    i = j = 0
    
    while i < len(left) and j < len(right):
        count += 1
        if left[i] <= right[j]:
            result.append(left[i])
            i += 1
        else:
            result.append(right[j])
            j += 1
    
    result.extend(left[i:])
    result.extend(right[j:])
    return result, count

arr = [38, 27, 43, 3, 9, 82, 10]
sorted_arr, comparisons = merge_sort_count(arr)
print(f"Comparisons: {comparisons}")
