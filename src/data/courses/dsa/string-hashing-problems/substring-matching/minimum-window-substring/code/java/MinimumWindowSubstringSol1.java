class Solution {
    public String minWindow(String s, String t) {
        String res = ""; int minLen = Integer.MAX_VALUE;
        for (int i=0;i<s.length();i++) {
            Map<Character,Integer> need = new HashMap<>();
            for (char c:t.toCharArray()) need.merge(c,1,Integer::sum);
            for (int j=i;j<s.length();j++) {
                if (need.containsKey(s.charAt(j))) need.merge(s.charAt(j),-1,Integer::sum);
                boolean valid = need.values().stream().allMatch(v->v<=0);
                if (valid && j-i+1<minLen) { minLen=j-i+1; res=s.substring(i,j+1); break; }
            }
        } return res;
    }
}