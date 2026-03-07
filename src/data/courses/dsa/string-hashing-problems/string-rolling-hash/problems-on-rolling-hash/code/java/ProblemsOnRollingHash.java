// Applications of Rolling Hash - Complete Implementations

import java.util.*;

class Solution {
    // Application 1: Pattern Matching (Rabin-Karp)
    public int rabinKarp(String text, String pattern) {
        int n = text.length(), m = pattern.length();
        long p = 31, mod = (long)1e9+7;
        
        long patHash = 0, txtHash = 0, powVal = 1;
        for (int i = 0; i < m; i++) {
            patHash = (patHash + (pattern.charAt(i)-'a'+1) * powVal) % mod;
            txtHash = (txtHash + (text.charAt(i)-'a'+1) * powVal) % mod;
            if (i < m-1) powVal = (powVal * p) % mod;
        }
        
        for (int i = 0; i <= n-m; i++) {
            if (patHash == txtHash && text.substring(i, i+m).equals(pattern))
                return i;
            if (i < n-m) {
                txtHash = (txtHash - (text.charAt(i)-'a'+1) + mod) % mod;
                txtHash = (txtHash / p) % mod;
                txtHash = (txtHash + (text.charAt(i+m)-'a'+1) * powVal) % mod;
            }
        }
        return -1;
    }
    
    // Application 2: Duplicate Substring Detection
    public List<Integer> findDuplicates(String s, int k) {
        int n = s.length();
        Map<Long, List<Integer>> hashMap = new HashMap<>();
        long p = 31, mod = (long)1e9+7;
        
        long hash = 0, powVal = 1;
        for (int i = 0; i < k; i++) {
            hash = (hash + (s.charAt(i)-'a'+1) * powVal) % mod;
            if (i < k-1) powVal = (powVal * p) % mod;
        }
        hashMap.computeIfAbsent(hash, x -> new ArrayList<>()).add(0);
        
        for (int i = k; i < n; i++) {
            hash = (hash - (s.charAt(i-k)-'a'+1) + mod) % mod;
            hash = (hash / p) % mod;
            hash = (hash + (s.charAt(i)-'a'+1) * powVal) % mod;
            hashMap.computeIfAbsent(hash, x -> new ArrayList<>()).add(i-k+1);
        }
        
        List<Integer> result = new ArrayList<>();
        for (List<Integer> indices : hashMap.values()) {
            if (indices.size() > 1) {
                result.addAll(indices);
            }
        }
        return result;
    }
    
    // Application 3: Longest Common Substring
    public int longestCommonSubstring(String s1, String s2) {
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
        Set<Long> hashes = new HashSet<>();
        long p = 31, mod = (long)1e9+7;
        
        long hash = 0, powVal = 1;
        for (int i = 0; i < len; i++) {
            hash = (hash * p + (s1.charAt(i)-'a'+1)) % mod;
            if (i < len-1) powVal = (powVal * p) % mod;
        }
        hashes.add(hash);
        
        for (int i = len; i < s1.length(); i++) {
            hash = (hash - (s1.charAt(i-len)-'a'+1) * powVal % mod + mod) % mod;
            hash = (hash * p + (s1.charAt(i)-'a'+1)) % mod;
            hashes.add(hash);
        }
        
        hash = 0;
        for (int i = 0; i < len; i++) {
            hash = (hash * p + (s2.charAt(i)-'a'+1)) % mod;
        }
        if (hashes.contains(hash)) return true;
        
        for (int i = len; i < s2.length(); i++) {
            hash = (hash - (s2.charAt(i-len)-'a'+1) * powVal % mod + mod) % mod;
            hash = (hash * p + (s2.charAt(i)-'a'+1)) % mod;
            if (hashes.contains(hash)) return true;
        }
        return false;
    }
    
    // Application 4: Longest Repeated Substring
    public int longestRepeatedSubstring(String s) {
        int left = 1, right = s.length();
        int result = 0;
        
        while (left <= right) {
            int mid = (left + right) / 2;
            if (hasRepeated(s, mid)) {
                result = mid;
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }
        return result;
    }
    
    private boolean hasRepeated(String s, int length) {
        Map<Long, Integer> seen = new HashMap<>();
        long p = 31, mod = (long)1e9+7;
        
        long hash = 0, powVal = 1;
        for (int i = 0; i < length; i++) {
            hash = (hash * p + (s.charAt(i)-'a'+1)) % mod;
            if (i < length-1) powVal = (powVal * p) % mod;
        }
        seen.put(hash, 0);
        
        for (int i = length; i < s.length(); i++) {
            hash = (hash - (s.charAt(i-length)-'a'+1) * powVal % mod + mod) % mod;
            hash = (hash * p + (s.charAt(i)-'a'+1)) % mod;
            if (seen.containsKey(hash)) return true;
            seen.put(hash, i - length + 1);
        }
        return false;
    }
}
