class Solution {
    public int longestCommonSubstring(String s1, String s2) {
        int m=s1.length(),n=s2.length(),max=0; int[] dp=new int[n+1];
        for(int i=1;i<=m;i++){int[] nd=new int[n+1];
            for(int j=1;j<=n;j++){nd[j]=s1.charAt(i-1)==s2.charAt(j-1)?dp[j-1]+1:0;max=Math.max(max,nd[j]);}dp=nd;}
        return max;
    }
}