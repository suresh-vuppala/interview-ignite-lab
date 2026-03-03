class Solution {
public:
    bool backspaceCompare(string s, string t) {
        int i = s.size() - 1, j = t.size() - 1;
        while (i >= 0 || j >= 0) {
            i = getNextValid(s, i);
            j = getNextValid(t, j);
            if (i >= 0 && j >= 0 && s[i] != t[j]) return false;
            if ((i >= 0) != (j >= 0)) return false;
            i--; j--;
        }
        return true;
    }
    
    int getNextValid(string& s, int idx) {
        int skip = 0;
        while (idx >= 0) {
            if (s[idx] == '#') {
                skip++;
                idx--;
            } else if (skip > 0) {
                skip--;
                idx--;
            } else break;
        }
        return idx;
    }
};