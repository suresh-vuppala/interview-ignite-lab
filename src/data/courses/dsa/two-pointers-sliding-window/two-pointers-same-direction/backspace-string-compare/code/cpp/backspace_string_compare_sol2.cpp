class Solution {
public:
    // Optimal: O(1) space — Process from right
    bool backspaceCompare(string s, string t) {
        int i = s.size()-1, j = t.size()-1;
        while (i >= 0 || j >= 0) {
            i = getNext(s, i);
            j = getNext(t, j);
            if (i >= 0 && j >= 0 && s[i] != t[j]) return false;
            if ((i >= 0) != (j >= 0)) return false; // One ended early
            i--; j--;
        }
        return true;
    }
    int getNext(string& s, int i) {
        int skip = 0;
        while (i >= 0) {
            if (s[i] == '#') { skip++; i--; }
            else if (skip > 0) { skip--; i--; }
            else break;
        }
        return i;
    }
};