class Solution {
    public int numDecodings(String s) {
        if (s.charAt(0) == '0') return 0;
        int a = 1, b = 1;
        for (int i = 1; i < s.length(); i++) {
            int c = 0;
            if (s.charAt(i) != '0') c += b;
            int two = Integer.parseInt(s.substring(i-1, i+1));
            if (two >= 10 && two <= 26) c += a;
            a = b; b = c;
        }
        return b;
    }
}