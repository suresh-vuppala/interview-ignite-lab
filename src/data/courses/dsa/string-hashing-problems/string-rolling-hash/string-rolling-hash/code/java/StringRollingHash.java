class RollingHash {
    long[] hash, pow;
    int p = 31, mod = (int)1e9+7;
    
    RollingHash(String s) {
        int n = s.length();
        hash = new long[n+1];
        pow = new long[n+1];
        pow[0] = 1;
        for (int i = 0; i < n; i++) {
            hash[i+1] = (hash[i] + (s.charAt(i)-'a'+1)*pow[i]) % mod;
            pow[i+1] = (pow[i]*p) % mod;
        }
    }
    
    long getHash(int l, int r) {
        return (hash[r+1] - hash[l] + mod) % mod;
    }
}