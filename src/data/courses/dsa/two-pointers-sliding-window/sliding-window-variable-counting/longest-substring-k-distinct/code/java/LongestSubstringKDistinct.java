class Solution {
    public int lengthOfLongestSubstringKDistinct(String s, int k) {
        Map<Character,Integer> freq = new HashMap<>();
        int left=0, max=0;
        for (int r=0; r<s.length(); r++) {
            freq.merge(s.charAt(r),1,Integer::sum);
            while (freq.size()>k) { char c=s.charAt(left); if(freq.merge(c,-1,Integer::sum)==0) freq.remove(c); left++; }
            max = Math.max(max, r-left+1);
        }
        return max;
    }
}