# Time: O(N+M) | Space: O(M)

from collections import Counter

def min_window(s, t):
    if not s or not t:
        return ""
    
    target = Counter(t)
    required = len(target)
    formed = 0
    window = {}
    
    left = 0
    min_len = float('inf')
    min_left = 0
    
    for right in range(len(s)):
        char = s[right]
        window[char] = window.get(char, 0) + 1
        
        if char in target and window[char] == target[char]:
            formed += 1
        
        while formed == required and left <= right:
            if right - left + 1 < min_len:
                min_len = right - left + 1
                min_left = left
            
            char = s[left]
            window[char] -= 1
            if char in target and window[char] < target[char]:
                formed -= 1
            left += 1
    
    return "" if min_len == float('inf') else s[min_left:min_left+min_len]
