// Time: O(N*M) naive, O(N+M) KMP, O(N+M) avg Rabin-Karp
// Space: O(1) naive/RK, O(M) KMP

class SubstringMatching {
    // Solution 1: Naive
    public int naiveSearch(String text, String pattern) {
        int n = text.length(), m = pattern.length();
        for (int i = 0; i <= n - m; i++) {
            if (text.substring(i, i + m).equals(pattern)) return i;
        }
        return -1;
    }
    
    // Solution 2: KMP
    private int[] buildLPS(String pattern) {
        int m = pattern.length();
        int[] lps = new int[m];
        int len = 0, i = 1;
        while (i < m) {
            if (pattern.charAt(i) == pattern.charAt(len)) {
                lps[i++] = ++len;
            } else if (len > 0) {
                len = lps[len - 1];
            } else {
                lps[i++] = 0;
            }
        }
        return lps;
    }
    
    public int kmpSearch(String text, String pattern) {
        int n = text.length(), m = pattern.length();
        int[] lps = buildLPS(pattern);
        int i = 0, j = 0;
        while (i < n) {
            if (text.charAt(i) == pattern.charAt(j)) {
                i++; j++;
            }
            if (j == m) return i - m;
            else if (i < n && text.charAt(i) != pattern.charAt(j)) {
                if (j > 0) j = lps[j - 1];
                else i++;
            }
        }
        return -1;
    }
    
    // Solution 3: Rabin-Karp
    public int rabinKarpSearch(String text, String pattern) {
        int n = text.length(), m = pattern.length();
        long d = 256, MOD = 1000000007;
        long h = 1;
        
        for (int i = 0; i < m - 1; i++) h = (h * d) % MOD;
        
        long pHash = 0, tHash = 0;
        for (int i = 0; i < m; i++) {
            pHash = (pHash * d + pattern.charAt(i)) % MOD;
            tHash = (tHash * d + text.charAt(i)) % MOD;
        }
        
        for (int i = 0; i <= n - m; i++) {
            if (pHash == tHash && text.substring(i, i + m).equals(pattern)) return i;
            if (i < n - m) {
                tHash = (d * (tHash - text.charAt(i) * h) + text.charAt(i + m)) % MOD;
                if (tHash < 0) tHash += MOD;
            }
        }
        return -1;
    }
}
