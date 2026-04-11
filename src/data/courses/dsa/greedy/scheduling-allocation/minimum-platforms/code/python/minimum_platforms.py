def min_platforms(arr, dep):
    arr.sort(); dep.sort()
    plat = max_plat = i = j = 0
    while i < len(arr):
        if arr[i] <= dep[j]: plat += 1; i += 1
        else: plat -= 1; j += 1
        max_plat = max(max_plat, plat)
    return max_plat