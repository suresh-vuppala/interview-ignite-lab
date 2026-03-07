// Time: O(N*M) naive, O(N+M) KMP, O(N+M) avg Rabin-Karp
// Space: O(1) naive/RK, O(M) KMP

#include <vector>
#include <string>
using namespace std;

// Solution 1: Naive
int naiveSearch(string text, string pattern) {
    int n = text.size(), m = pattern.size();
    for (int i = 0; i <= n - m; i++) {
        if (text.substr(i, m) == pattern) return i;
    }
    return -1;
}

// Solution 2: KMP
vector<int> buildLPS(string pattern) {
    int m = pattern.size();
    vector<int> lps(m, 0);
    int len = 0, i = 1;
    while (i < m) {
        if (pattern[i] == pattern[len]) {
            lps[i++] = ++len;
        } else if (len > 0) {
            len = lps[len - 1];
        } else {
            lps[i++] = 0;
        }
    }
    return lps;
}

int kmpSearch(string text, string pattern) {
    int n = text.size(), m = pattern.size();
    vector<int> lps = buildLPS(pattern);
    int i = 0, j = 0;
    while (i < n) {
        if (text[i] == pattern[j]) {
            i++; j++;
        }
        if (j == m) return i - m;
        else if (i < n && text[i] != pattern[j]) {
            if (j > 0) j = lps[j - 1];
            else i++;
        }
    }
    return -1;
}

// Solution 3: Rabin-Karp
int rabinKarpSearch(string text, string pattern) {
    int n = text.size(), m = pattern.size();
    long long d = 256, MOD = 1e9 + 7;
    long long h = 1;
    
    for (int i = 0; i < m - 1; i++) h = (h * d) % MOD;
    
    long long p_hash = 0, t_hash = 0;
    for (int i = 0; i < m; i++) {
        p_hash = (p_hash * d + pattern[i]) % MOD;
        t_hash = (t_hash * d + text[i]) % MOD;
    }
    
    for (int i = 0; i <= n - m; i++) {
        if (p_hash == t_hash && text.substr(i, m) == pattern) return i;
        if (i < n - m) {
            t_hash = (d * (t_hash - text[i] * h) + text[i + m]) % MOD;
            if (t_hash < 0) t_hash += MOD;
        }
    }
    return -1;
}
