def aggressive_cows(stalls, k):
    stalls.sort()
    lo, hi = 1, stalls[-1] - stalls[0]
    while lo < hi:
        mid = lo + (hi - lo + 1) // 2
        count, last = 1, stalls[0]
        for s in stalls[1:]:
            if s - last >= mid: count += 1; last = s
        if count >= k: lo = mid
        else: hi = mid - 1
    return lo