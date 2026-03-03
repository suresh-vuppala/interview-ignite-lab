#include <string>
using namespace std;

int rabinKarp(string text, string pattern) {
    int n = text.size(), m = pattern.size();
    long long p = 31, mod = 1e9+7;
    long long patHash = 0, txtHash = 0, pow = 1;
    
    for (int i = 0; i < m; i++) {
        patHash = (patHash + (pattern[i]-'a'+1)*pow) % mod;
        txtHash = (txtHash + (text[i]-'a'+1)*pow) % mod;
        if (i < m-1) pow = (pow*p) % mod;
    }
    
    for (int i = 0; i <= n-m; i++) {
        if (patHash == txtHash && text.substr(i, m) == pattern)
            return i;
        if (i < n-m) {
            txtHash = (txtHash - (text[i]-'a'+1) + mod) % mod;
            txtHash = txtHash / p;
            txtHash = (txtHash + (text[i+m]-'a'+1)*pow) % mod;
        }
    }
    return -1;
}