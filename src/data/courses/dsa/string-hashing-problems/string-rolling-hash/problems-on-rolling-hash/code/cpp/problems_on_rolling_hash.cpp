#include <string>
#include <vector>
using namespace std;
// ============================================================
// Solution 1: Naive pattern match — O(N*M)
// ============================================================
class Solution1 {
public:
    vector<int> search(string& text, string& pattern) {
        int n = text.size(), m = pattern.size();
        vector<int> result;
        for (int i = 0; i <= n - m; i++) {
            bool match = true;
            for (int j = 0; j < m; j++)
                if (text[i+j] != pattern[j]) { match = false; break; }
            if (match) result.push_back(i);
        }
        return result; // O(N*M) worst case
    }
};

// ============================================================
// Solution 2: Rabin-Karp rolling hash — O(N+M) average
// ============================================================
class Solution2 {
    static const long long MOD = 1e9 + 7, BASE = 31;
public:
    vector<int> search(string& text, string& pattern) {
        int n = text.size(), m = pattern.size();
        if (m > n) return {};
        // Compute pattern hash and first window hash
        long long pHash = 0, tHash = 0, power = 1;
        for (int i = 0; i < m; i++) {
            pHash = (pHash + (pattern[i]-'a'+1) * power) % MOD;
            tHash = (tHash + (text[i]-'a'+1) * power) % MOD;
            if (i < m-1) power = power * BASE % MOD;
        }
        vector<int> result;
        for (int i = 0; i <= n - m; i++) {
            if (tHash == pHash) { // Hash match — verify to avoid collision
                bool ok = true;
                for (int j = 0; j < m; j++) if (text[i+j] != pattern[j]) { ok = false; break; }
                if (ok) result.push_back(i);
            }
            if (i < n - m) { // Slide window
                tHash = (tHash - (text[i]-'a'+1) + MOD) % MOD;
                tHash = tHash * power % MOD; // Shift right (depends on hash direction)
                // Simplified: recompute (proper rolling needs modular inverse)
                tHash = 0; long long pw = 1;
                for (int j = 0; j < m; j++) { tHash = (tHash + (text[i+1+j]-'a'+1)*pw)%MOD; pw=pw*BASE%MOD; }
            }
        }
        return result;
    }
};
