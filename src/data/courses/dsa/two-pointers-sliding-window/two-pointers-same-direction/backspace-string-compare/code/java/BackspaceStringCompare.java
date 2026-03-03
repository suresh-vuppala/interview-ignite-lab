class BackspaceCompare {
    public boolean backspaceCompare(String s, String t) {
        int i = s.length() - 1, j = t.length() - 1;
        while (i >= 0 || j >= 0) {
            i = getNextValid(s, i);
            j = getNextValid(t, j);
            if (i >= 0 && j >= 0 && s.charAt(i) != t.charAt(j)) return false;
            if ((i >= 0) != (j >= 0)) return false;
            i--; j--;
        }
        return true;
    }
    
    private int getNextValid(String s, int idx) {
        int skip = 0;
        while (idx >= 0) {
            if (s.charAt(idx) == '#') {
                skip++;
                idx--;
            } else if (skip > 0) {
                skip--;
                idx--;
            } else break;
        }
        return idx;
    }
}