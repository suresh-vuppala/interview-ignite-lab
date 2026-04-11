class Solution {
    public int lengthOfLongestSubstring(String s) {
        Set<Character> win = new HashSet<>(); int l=0, max=0;
        for (int r=0;r<s.length();r++) {
            while(win.contains(s.charAt(r))) win.remove(s.charAt(l++));
            win.add(s.charAt(r)); max=Math.max(max,r-l+1);
        } return max;
    }
}