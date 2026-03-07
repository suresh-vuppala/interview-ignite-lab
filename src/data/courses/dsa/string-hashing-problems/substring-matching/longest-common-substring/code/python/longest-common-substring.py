# Time: O(N*M) DP, O(N log N) hash | Space: O(N*M) DP, O(N) hash

def longest_common_substring_dp(s1, s2):
    n, m = len(s1), len(s2)
    dp = [[0] * (m+1) for _ in range(n+1)]
    max_len = 0
    end_pos = 0
    
    for i in range(1, n+1):
        for j in range(1, m+1):
            if s1[i-1] == s2[j-1]:
                dp[i][j] = dp[i-1][j-1] + 1
                if dp[i][j] > max_len:
                    max_len = dp[i][j]
                    end_pos = i
    
    return s1[end_pos-max_len:end_pos]

def longest_common_substring_hash(s1, s2):
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
