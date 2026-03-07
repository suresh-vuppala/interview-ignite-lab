# Time: O(N*M) naive, O(N+M) KMP, O(N+M) avg Rabin-Karp
# Space: O(1) naive/RK, O(M) KMP

# Solution 1: Naive
def naive_search(text, pattern):
    n, m = len(text), len(pattern)
    for i in range(n - m + 1):
        if text[i:i+m] == pattern:
            return i
    return -1

# Solution 2: KMP
def kmp_search(text, pattern):
    def build_lps(pattern):
        m = len(pattern)
        lps = [0] * m
        length = 0
        i = 1
        while i < m:
            if pattern[i] == pattern[length]:
                length += 1
                lps[i] = length
                i += 1
            elif length > 0:
                length = lps[length - 1]
            else:
                lps[i] = 0
                i += 1
        return lps
    
    n, m = len(text), len(pattern)
    lps = build_lps(pattern)
    i = j = 0
    while i < n:
        if text[i] == pattern[j]:
            i += 1
            j += 1
        if j == m:
            return i - m
        elif i < n and text[i] != pattern[j]:
            if j > 0:
                j = lps[j - 1]
            else:
                i += 1
    return -1

# Solution 3: Rabin-Karp
def rabin_karp_search(text, pattern):
    n, m = len(text), len(pattern)
    d, MOD = 256, 10**9 + 7
    
    h = pow(d, m - 1, MOD)
    p_hash = t_hash = 0
    
    for i in range(m):
        p_hash = (p_hash * d + ord(pattern[i])) % MOD
        t_hash = (t_hash * d + ord(text[i])) % MOD
    
    for i in range(n - m + 1):
        if p_hash == t_hash and text[i:i+m] == pattern:
            return i
        if i < n - m:
            t_hash = (d * (t_hash - ord(text[i]) * h) + ord(text[i + m])) % MOD
            if t_hash < 0:
                t_hash += MOD
    return -1
