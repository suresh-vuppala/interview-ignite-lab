#include <string>
#include <queue>
using namespace std;
// ============================================================
// Solution 1: Sort by frequency, place alternating — O(N log N)
// ============================================================
#include <vector>
#include <algorithm>
class Solution1 {
public:
    string reorganizeString(string s) {
        int freq[26] = {};
        for (char c : s) freq[c-'a']++;
        vector<pair<int,char>> v;
        for (int i = 0; i < 26; i++) if (freq[i]) v.push_back({freq[i], 'a'+i});
        sort(v.rbegin(), v.rend());
        if (v[0].first > ((int)s.size()+1)/2) return ""; // Impossible
        string res(s.size(), ' ');
        int idx = 0;
        for (auto [cnt, ch] : v)
            for (int i = 0; i < cnt; i++) { if (idx >= (int)s.size()) idx = 1; res[idx] = ch; idx += 2; }
        return res;
    }
};

// ============================================================
// Solution 2: Max-heap — always place most frequent, cool down — O(N log 26)
// ============================================================
class Solution2 {
public:
    string reorganizeString(string s) {
        int freq[26] = {};
        for (char c : s) freq[c-'a']++;
        priority_queue<pair<int,char>> pq;
        for (int i = 0; i < 26; i++) if (freq[i]) pq.push({freq[i], 'a'+i});
        string res;
        while (!pq.empty()) {
            auto [cnt1, ch1] = pq.top(); pq.pop();
            if (!res.empty() && res.back() == ch1) {
                if (pq.empty()) return ""; // Can't place
                auto [cnt2, ch2] = pq.top(); pq.pop();
                res += ch2;
                if (cnt2 > 1) pq.push({cnt2-1, ch2});
                pq.push({cnt1, ch1}); // Put back
            } else {
                res += ch1;
                if (cnt1 > 1) pq.push({cnt1-1, ch1});
            }
        }
        return res;
    }
};
