def length_of_longest_substring(s):
    mp = {}
    max_len = left = 0
    for right in range(len(s)):
        if s[right] in mp:
            left = max(left, mp[s[right]] + 1)
        mp[s[right]] = right
        max_len = max(max_len, right - left + 1)
    return max_len