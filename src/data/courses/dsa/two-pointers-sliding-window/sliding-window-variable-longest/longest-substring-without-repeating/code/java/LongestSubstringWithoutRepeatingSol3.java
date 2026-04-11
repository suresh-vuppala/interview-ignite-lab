class Solution {
    public int lengthOfLongestSubstring(String s) {
        Map<Character,Integer> last = new HashMap<>(); int l=0, max=0;
        for (int r=0;r<s.length();r++) {
            if (last.containsKey(s.charAt(r)) && last.get(s.charAt(r))>=l)
                l = last.get(s.charAt(r))+1;
            last.put(s.charAt(r),r); max=Math.max(max,r-l+1);
        } return max;
    }
}