def total_fruit(fruits):
    mp = {}
    left = max_len = 0
    for right in range(len(fruits)):
        mp[fruits[right]] = mp.get(fruits[right], 0) + 1
        while len(mp) > 2:
            mp[fruits[left]] -= 1
            if mp[fruits[left]] == 0:
                del mp[fruits[left]]
            left += 1
        max_len = max(max_len, right - left + 1)
    return max_len