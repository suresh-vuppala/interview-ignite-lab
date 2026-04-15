#include <string>
#include <vector>
using namespace std;
// ============================================================
// Solution 1: Naive string comparison — O(L) per comparison
// ============================================================
class Solution1 {
public:
    bool isEqual(string& a, string& b) {
        if (a.size() != b.size()) return false;
        for (int i = 0; i < (int)a.size(); i++)
            if (a[i] != b[i]) return false;
        return true; // O(L) per comparison, O(N*L) for N comparisons
    }
};

// ============================================================
// Solution 2: Polynomial rolling hash — O(L) precompute, O(1) compare
// ============================================================
class Solution2 {
    static const long long MOD = 1e9 + 7, BASE = 31;
public:
    long long computeHash(string& s) {
        long long hash = 0, power = 1;
        for (char c : s) {
            hash = (hash + (c - 'a' + 1) * power) % MOD;
            power = power * BASE % MOD;
        }
        return hash; // O(L) compute, O(1) compare (with collision check)
    }
    // Prefix hash array for substring hashing in O(1)
    vector<long long> prefixHash(string& s) {
        int n = s.size();
        vector<long long> h(n + 1, 0), pw(n + 1, 1);
        for (int i = 0; i < n; i++) {
            h[i+1] = (h[i] + (s[i]-'a'+1) * pw[i]) % MOD;
            pw[i+1] = pw[i] * BASE % MOD;
        }
        return h;
    }
};
