class Solution {
    public String minWindow(String s, String t) {
        Map<Character,Integer> need=new HashMap<>(), win=new HashMap<>();
        for (char c:t.toCharArray()) need.merge(c,1,Integer::sum);
        int l=0,formed=0,req=need.size(),minL=Integer.MAX_VALUE,start=0;
        for (int r=0;r<s.length();r++) {
            char c=s.charAt(r); win.merge(c,1,Integer::sum);
            if(need.containsKey(c)&&win.get(c).equals(need.get(c))) formed++;
            while(formed==req) {
                if(r-l+1<minL){minL=r-l+1;start=l;}
                char d=s.charAt(l++);win.merge(d,-1,Integer::sum);
                if(need.containsKey(d)&&win.get(d)<need.get(d)) formed--;
            }
        } return minL==Integer.MAX_VALUE?"":s.substring(start,start+minL);
    }
}