#include <string>
#include <algorithm>
using namespace std;
// ============================================================
// Solution 1: Brute Force — Check all substrings — O(N³) Time
// ============================================================
class Solution1 {
    bool isPalin(string& s, int l, int r) { while(l<r) if(s[l++]!=s[r--]) return false; return true; }
public:
    string longestPalindrome(string s) {
        int n=s.size(), maxLen=1, start=0;
        for (int i=0;i<n;i++)
            for (int j=i;j<n;j++)
                if (isPalin(s,i,j) && j-i+1>maxLen) { maxLen=j-i+1; start=i; }
        return s.substr(start, maxLen);
    }
};

// ============================================================
// Solution 2: Expand Around Center — O(N²) Time, O(1) Space
// ============================================================
class Solution2 {
    int expand(string& s, int l, int r) { while(l>=0 && r<(int)s.size() && s[l]==s[r]){l--;r++;} return r-l-1; }
public:
    string longestPalindrome(string s) {
        int start=0, maxLen=0;
        for (int i=0; i<(int)s.size(); i++) {
            int len1 = expand(s, i, i), len2 = expand(s, i, i+1);
            int len = max(len1, len2);
            if (len > maxLen) { maxLen = len; start = i - (len-1)/2; }
        }
        return s.substr(start, maxLen);
    }
};
