#include <vector>
#include <string>
#include <algorithm>
using namespace std;
// ============================================================
// Solution 1: Sort each window, compare — O(N * K log K)
// ============================================================
class Solution1 {
public:
    vector<int> findAnagrams(string s, string p) {
        int n = s.size(), k = p.size();
        string sorted_p = p; sort(sorted_p.begin(), sorted_p.end());
        vector<int> result;
        for (int i = 0; i <= n - k; i++) {
            string window = s.substr(i, k);
            sort(window.begin(), window.end());
            if (window == sorted_p) result.push_back(i);
        }
        return result;
    }
};

// ============================================================
// Solution 2: Sliding Window with frequency array — O(N) Time
// ============================================================
class Solution2 {
public:
    vector<int> findAnagrams(string s, string p) {
        int n = s.size(), k = p.size();
        if (n < k) return {};
        vector<int> result;
        int pFreq[26] = {}, wFreq[26] = {};
        for (char c : p) pFreq[c - 'a']++;
        for (int i = 0; i < n; i++) {
            wFreq[s[i] - 'a']++;
            if (i >= k) wFreq[s[i - k] - 'a']--; // Slide left out
            if (i >= k - 1) {
                bool match = true;
                for (int j = 0; j < 26; j++) if (pFreq[j] != wFreq[j]) { match = false; break; }
                if (match) result.push_back(i - k + 1);
            }
        }
        return result;
    }
};
