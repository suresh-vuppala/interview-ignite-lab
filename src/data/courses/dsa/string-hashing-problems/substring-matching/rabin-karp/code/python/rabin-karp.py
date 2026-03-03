def rabin_karp(text, pattern):
    n, m = len(text), len(pattern)
    p, mod = 31, 10**9+7
    pat_hash = txt_hash = pow_val = 0
    
    for i in range(m):
        pat_hash = (pat_hash + (ord(pattern[i])-ord('a')+1)*(p**i)) % mod
        txt_hash = (txt_hash + (ord(text[i])-ord('a')+1)*(p**i)) % mod
    pow_val = p**(m-1)
    
    for i in range(n-m+1):
        if pat_hash == txt_hash and text[i:i+m] == pattern:
            return i
        if i < n-m:
            txt_hash = (txt_hash - (ord(text[i])-ord('a')+1)) // p
            txt_hash = (txt_hash + (ord(text[i+m])-ord('a')+1)*pow_val) % mod
    return -1