class Solution {
    public String longestPalindrome(String s) {
        int start=0,maxLen=1,n=s.length();
        for(int i=0;i<n;i++){
            int[] r1=expand(s,i,i),r2=expand(s,i,i+1);
            if(r1[1]>maxLen){start=r1[0];maxLen=r1[1];}
            if(r2[1]>maxLen){start=r2[0];maxLen=r2[1];}
        }
        return s.substring(start,start+maxLen);
    }
    int[] expand(String s,int l,int r){
        while(l>=0&&r<s.length()&&s.charAt(l)==s.charAt(r)){l--;r++;}
        return new int[]{l+1,r-l-1};
    }
}