import java.util.*;

class Solution {
    public String longestDupSubstring(String s) {
        int n = s.length();
        int left = 1, right = n;
        String res = "";
        
        while (left <= right) {
            int mid = (left + right) / 2;
            String dup = search(s, mid);
            if (dup != null) {
                res = dup;
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }
        return res;
    }
    
    String search(String s, int len) {
        long p = 31, mod = (long)1e9+7;
        long hash = 0, pow = 1;
        Map<Long, List<Integer>> map = new HashMap<>();
        
        for (int i = 0; i < len; i++) {
            hash = (hash + (s.charAt(i)-'a'+1)*pow) % mod;
            pow = (pow*p) % mod;
        }
        map.computeIfAbsent(hash, k -> new ArrayList<>()).add(0);
        
        for (int i = len; i < s.length(); i++) {
            hash = (hash - (s.charAt(i-len)-'a'+1) + mod) % mod;
            hash = (hash + (s.charAt(i)-'a'+1)*pow) % mod;
            
            if (map.containsKey(hash)) {
                for (int idx : map.get(hash)) {
                    if (s.substring(idx, idx+len).equals(s.substring(i-len+1, i+1)))
                        return s.substring(idx, idx+len);
                }
            }
            map.computeIfAbsent(hash, k -> new ArrayList<>()).add(i-len+1);
        }
        return null;
    }
}