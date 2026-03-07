// Time: O(N^2*M) brute, O(N*M*log(min(N,M))) binary+brute, O((N+M)*log(min(N,M))) binary+hash
// Space: O(N) brute, O(L) binary+brute, O(N) binary+hash

import java.util.*;

class LongestCommonSubstring {
    // Solution 1: Brute Force
    public int bruteForce(String s1, String s2) {
        int n = s1.length(), m = s2.length();
        int maxLen = 0;
        for (int i = 0; i < n; i++) {
            for (int j = i; j < n; j++) {
                String substr = s1.substring(i, j + 1);
                if (s2.contains(substr)) {
                    maxLen = Math.max(maxLen, substr.length());
                }
            }
        }
        return maxLen;
    }
    
    // Solution 2: Binary Search + Brute Force
    public int binarySearchBrute(String s1, String s2) {
        int left = 0, right = Math.min(s1.length(), s2.length());
        int result = 0;
        while (left <= right) {
            int mid = (left + right) / 2;
            if (hasCommonSubstring(s1, s2, mid)) {
                result = mid;
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }
        return result;
    }
    
    private boolean hasCommonSubstring(String s1, String s2, int len) {
        for (int i = 0; i <= s1.length() - len; i++) {
            if (s2.contains(s1.substring(i, i + len))) {
                return true;
            }
        }
        return false;
    }
    
    // Solution 3: Binary Search + Rolling Hash
    public int binarySearchHash(String s1, String s2) {
        int left = 0, right = Math.min(s1.length(), s2.length());
        int result = 0;
        while (left <= right) {
            int mid = (left + right) / 2;
            if (hasCommon(s1, s2, mid)) {
                result = mid;
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }
        return result;
    }
    
    private boolean hasCommon(String s1, String s2, int len) {
        Set<Long> hashes1 = getHashes(s1, len);
        Set<Long> hashes2 = getHashes(s2, len);
        hashes1.retainAll(hashes2);
        return !hashes1.isEmpty();
    }
    
    private Set<Long> getHashes(String s, int len) {
        if (len == 0) return new HashSet<>();
        long d = 256, MOD = 1000000007;
        long h = 1;
        for (int i = 0; i < len - 1; i++) h = (h * d) % MOD;
        
        long hash = 0;
        for (int i = 0; i < len; i++) {
            hash = (hash * d + s.charAt(i)) % MOD;
        }
        Set<Long> hashes = new HashSet<>();
        hashes.add(hash);
        
        for (int i = len; i < s.length(); i++) {
            hash = (d * (hash - s.charAt(i - len) * h) + s.charAt(i)) % MOD;
            if (hash < 0) hash += MOD;
            hashes.add(hash);
        }
        return hashes;
    }
}
