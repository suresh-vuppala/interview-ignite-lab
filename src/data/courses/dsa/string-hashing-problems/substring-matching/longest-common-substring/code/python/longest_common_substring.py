# Time: O(N^2*M) brute, O(N*M*log(min(N,M))) binary+brute, O((N+M)*log(min(N,M))) binary+hash
# Space: O(N) brute, O(L) binary+brute, O(N) binary+hash

# Solution 1: Brute Force
def brute_force(s1, s2):
    n, m = len(s1), len(s2)
    max_len = 0
    for i in range(n):
        for j in range(i, n):
            substr = s1[i:j+1]
            if substr in s2:
                max_len = max(max_len, len(substr))
    return max_len

# Solution 2: Binary Search + Brute Force
def binary_search_brute(s1, s2):
    def has_common_substring(length):
        for i in range(len(s1) - length + 1):
            if s1[i:i+length] in s2:
                return True
        return False
    
    left, right = 0, min(len(s1), len(s2))
    result = 0
    while left <= right:
        mid = (left + right) // 2
        if has_common_substring(mid):
            result = mid
            left = mid + 1
        else:
            right = mid - 1
    return result

# Solution 3: Binary Search + Rolling Hash
def binary_search_hash(s1, s2):
    def get_hashes(s, length):
        if length == 0:
            return set()
        d, MOD = 256, 10**9 + 7
        h = pow(d, length - 1, MOD)
        hash_val = 0
        for i in range(length):
            hash_val = (hash_val * d + ord(s[i])) % MOD
        hashes = {hash_val}
        for i in range(length, len(s)):
            hash_val = (d * (hash_val - ord(s[i - length]) * h) + ord(s[i])) % MOD
            hashes.add(hash_val)
        return hashes
    
    def has_common(length):
        hashes1 = get_hashes(s1, length)
        hashes2 = get_hashes(s2, length)
        return bool(hashes1 & hashes2)
    
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
