#include <string>
#include <vector>
using namespace std;
// ============================================================
// Solution 1: Brute Force — O(N*M)
// ============================================================
class Solution1 {
public:
    int strStr(string haystack, string needle) {
        int n = haystack.size(), m = needle.size();
        for (int i = 0; i <= n - m; i++) {
            bool match = true;
            for (int j = 0; j < m; j++)
                if (haystack[i+j] != needle[j]) { match = false; break; }
            if (match) return i;
        }
        return -1;
    }
};

// ============================================================
// Solution 2: KMP (Knuth-Morris-Pratt) — O(N+M) Time
// ============================================================
class Solution2 {
public:
    int strStr(string haystack, string needle) {
        int n = haystack.size(), m = needle.size();
        if (m == 0) return 0;
        // Build failure function (LPS array)
        vector<int> lps(m, 0);
        int len = 0, i = 1;
        while (i < m) {
            if (needle[i] == needle[len]) { lps[i++] = ++len; }
            else if (len) { len = lps[len-1]; }
            else { lps[i++] = 0; }
        }
        // Search
        i = 0; int j = 0;
        while (i < n) {
            if (haystack[i] == needle[j]) { i++; j++; }
            if (j == m) return i - j; // Found!
            if (i < n && haystack[i] != needle[j]) {
                if (j) j = lps[j-1]; // Skip using LPS
                else i++;
            }
        }
        return -1; // O(N+M) — no backtracking!
    }
};
