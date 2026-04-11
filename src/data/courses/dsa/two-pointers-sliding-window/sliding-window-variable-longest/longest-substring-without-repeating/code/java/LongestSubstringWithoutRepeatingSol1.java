class Solution {
    public int lengthOfLongestSubstring(String s) {
        int max = 0;
        for (int i=0;i<s.length();i++) {
            Set<Character> seen = new HashSet<>();
            for (int j=i;j<s.length();j++) {
                if (!seen.add(s.charAt(j))) break;
                max = Math.max(max, j-i+1);
            }
        } return max;
    }
}