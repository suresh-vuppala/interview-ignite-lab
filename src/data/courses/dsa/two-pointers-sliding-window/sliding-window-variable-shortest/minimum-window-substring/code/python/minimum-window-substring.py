def min_window(s, t):
    if len(s) < len(t):
        return ""
    mp = {}
    for c in t:
        mp[c] = mp.get(c, 0) + 1
    left = min_start = 0
    min_len = float('inf')
    count = len(t)
    for right in range(len(s)):
        if s[right] in mp:
            if mp[s[right]] > 0:
                count -= 1
            mp[s[right]] -= 1
        while count == 0:
            if right - left + 1 < min_len:
                min_len = right - left + 1
                min_start = left
            if s[left] in mp:
                mp[s[left]] += 1
                if mp[s[left]] > 0:
                    count += 1
            left += 1
    return "" if min_len == float('inf') else s[min_start:min_start + min_len]