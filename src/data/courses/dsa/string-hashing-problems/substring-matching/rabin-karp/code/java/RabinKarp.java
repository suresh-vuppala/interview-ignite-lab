class RabinKarp {
    public int search(String text, String pattern) {
        int n = text.length(), m = pattern.length();
        long p = 31, mod = (long)1e9+7;
        long patHash = 0, txtHash = 0, pow = 1;
        
        for (int i = 0; i < m; i++) {
            patHash = (patHash + (pattern.charAt(i)-'a'+1)*pow) % mod;
            txtHash = (txtHash + (text.charAt(i)-'a'+1)*pow) % mod;
            if (i < m-1) pow = (pow*p) % mod;
        }
        
        for (int i = 0; i <= n-m; i++) {
            if (patHash == txtHash && text.substring(i, i+m).equals(pattern))
                return i;
            if (i < n-m) {
                txtHash = (txtHash - (text.charAt(i)-'a'+1) + mod) % mod;
                txtHash = txtHash / p;
                txtHash = (txtHash + (text.charAt(i+m)-'a'+1)*pow) % mod;
            }
        }
        return -1;
    }
}