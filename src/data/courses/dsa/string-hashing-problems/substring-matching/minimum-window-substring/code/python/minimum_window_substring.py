# Time: O(N^3+N^2*M) brute, O(N+M) sliding window, O(N*M*log(N)) binary search
# Space: O(M)

from collections import Counter

# Solution 1: Brute Force
def brute_force(s, t):
    if not s or not t or len(t) > len(s):
        return ""
    
    target = Counter(t)
    min_len = float('inf')
    result = ""
    
    for i in range(len(s)):
        for j in range(i, len(s)):
            window = Counter(s[i:j+1])
            valid = all(window[c] >= target[c] for c in target)
            if valid and j - i + 1 < min_len:
                min_len = j - i + 1
                result = s[i:j+1]
    
    return result

# Solution 2: Sliding Window (Optimal)
def sliding_window(s, t):
    if not s or not t or len(t) > len(s):
        return ""
    
    target = Counter(t)
    window = {}
    required = len(target)
    formed = 0
    
    left = 0
    min_len = float('inf')
    result = ""
    
    for right in range(len(s)):
        char = s[right]
        window[char] = window.get(char, 0) + 1
        
        if char in target and window[char] == target[char]:
            formed += 1
        
        while formed == required and left <= right:
            if right - left + 1 < min_len:
                min_len = right - left + 1
                result = s[left:right+1]
            
            char = s[left]
            window[char] -= 1
            if char in target and window[char] < target[char]:
                formed -= 1
            left += 1
    
    return result

# Solution 3: Binary Search on Length
def binary_search(s, t):
    if not s or not t or len(t) > len(s):
        return ""
    
    target = Counter(t)
    
    def has_valid_window(length):
        for i in range(len(s) - length + 1):
            window = Counter(s[i:i+length])
            if all(window[c] >= target[c] for c in target):
                return s[i:i+length]
        return None
    
    left, right = len(t), len(s)
    result = ""
    
    while left <= right:
        mid = (left + right) // 2
        window = has_valid_window(mid)
        if window:
            result = window
            right = mid - 1
        else:
            left = mid + 1
    
    return result
