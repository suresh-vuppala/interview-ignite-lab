class Solution {
    public boolean backspaceCompare(String s, String t) {
        int i=s.length()-1, j=t.length()-1;
        while (i>=0 || j>=0) {
            i=next(s,i); j=next(t,j);
            if (i>=0 && j>=0 && s.charAt(i)!=t.charAt(j)) return false;
            if ((i>=0) != (j>=0)) return false;
            i--; j--;
        }
        return true;
    }
    int next(String s, int i) {
        int skip=0;
        while(i>=0) { if(s.charAt(i)=='#'){skip++;i--;} else if(skip>0){skip--;i--;} else break; }
        return i;
    }
}