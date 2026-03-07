# Applications of Rolling Hash - Complete Implementations

# Application 1: Pattern Matching (Rabin-Karp)
def rabin_karp(text, pattern):
    n, m = len(text), len(pattern)
    p, mod = 31, 10**9+7
    
    pat_hash = txt_hash = pow_val = 0
    for i in range(m):
        pat_hash = (pat_hash + (ord(pattern[i])-ord('a')+1) * (p**i)) % mod
        txt_hash = (txt_hash + (ord(text[i])-ord('a')+1) * (p**i)) % mod
    pow_val = p**(m-1)
    
    for i in range(n-m+1):
        if pat_hash == txt_hash and text[i:i+m] == pattern:
            return i
        if i < n-m:
            txt_hash = (txt_hash - (ord(text[i])-ord('a')+1)) // p
            txt_hash = (txt_hash + (ord(text[i+m])-ord('a')+1) * pow_val) % mod
    return -1

# Application 2: Duplicate Substring Detection
def find_duplicates(s, k):
    n = len(s)
    hash_map = {}
    p, mod = 31, 10**9+7
    
    hash_val = pow_val = 0
    for i in range(k):
        hash_val = (hash_val + (ord(s[i])-ord('a')+1) * (p**i)) % mod
    pow_val = p**(k-1)
    hash_map[hash_val] = [0]
    
    for i in range(k, n):
        hash_val = (hash_val - (ord(s[i-k])-ord('a')+1)) // p
        hash_val = (hash_val + (ord(s[i])-ord('a')+1) * pow_val) % mod
        hash_map.setdefault(hash_val, []).append(i-k+1)
    
    result = []
    for indices in hash_map.values():
        if len(indices) > 1:
            result.extend(indices)
    return result

# Application 3: Longest Common Substring
def longest_common_substring(s1, s2):
    def has_common(length):
        hashes = set()
        p, mod = 31, 10**9+7
        
        hash_val = 0
        for i in range(length):
            hash_val = (hash_val * p + ord(s1[i])-ord('a')+1) % mod
        hashes.add(hash_val)
        
        for i in range(length, len(s1)):
            hash_val = (hash_val * p + ord(s1[i])-ord('a')+1) % mod
            hash_val = (hash_val - (ord(s1[i-length])-ord('a')+1) * pow(p, length, mod)) % mod
            hashes.add(hash_val)
        
        hash_val = 0
        for i in range(length):
            hash_val = (hash_val * p + ord(s2[i])-ord('a')+1) % mod
        if hash_val in hashes:
            return True
        
        for i in range(length, len(s2)):
            hash_val = (hash_val * p + ord(s2[i])-ord('a')+1) % mod
            hash_val = (hash_val - (ord(s2[i-length])-ord('a')+1) * pow(p, length, mod)) % mod
            if hash_val in hashes:
                return True
        return False
    
    left, right = 0, min(len(s1), len(s2))
    result = 0
    
    while left <= right:
        mid = (left + right) // 2
        if has_common(mid):
            result = mid
            left = mid + 1
        else:
            right = mid - 1
    return result

# Application 4: Longest Repeated Substring
def longest_repeated_substring(s):
    def has_repeated(length):
        seen = {}
        p, mod = 31, 10**9+7
        
        hash_val = 0
        for i in range(length):
            hash_val = (hash_val * p + ord(s[i])-ord('a')+1) % mod
        seen[hash_val] = 0
        
        for i in range(length, len(s)):
            hash_val = (hash_val * p + ord(s[i])-ord('a')+1) % mod
            hash_val = (hash_val - (ord(s[i-length])-ord('a')+1) * pow(p, length, mod)) % mod
            if hash_val in seen:
                return True
            seen[hash_val] = i - length + 1
        return False
    
    left, right = 1, len(s)
    result = 0
    
    while left <= right:
        mid = (left + right) // 2
        if has_repeated(mid):
            result = mid
            left = mid + 1
        else:
            right = mid - 1
    return result
