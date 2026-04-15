#include <vector>
#include <string>
#include <algorithm>
using namespace std;
// ============================================================
// Solution 1: Brute Force — try all partition points — O(N * 26)
// ============================================================
class Solution1 {
public:
    vector<int> partitionLabels(string s) {
        vector<int> result;
        int start = 0;
        while (start < (int)s.size()) {
            // Find smallest partition starting at 'start'
            int end = start;
            for (int i = start; i <= end; i++) {
                // Find last occurrence of s[i]
                for (int j = s.size()-1; j > end; j--)
                    if (s[j] == s[i]) { end = j; break; }
            }
            result.push_back(end - start + 1);
            start = end + 1;
        }
        return result;
    }
};

// ============================================================
// Solution 2: Precompute last occurrence + greedy — O(N)
// ============================================================
class Solution2 {
public:
    vector<int> partitionLabels(string s) {
        int last[26] = {};
        for (int i = 0; i < (int)s.size(); i++) last[s[i]-'a'] = i;
        vector<int> result;
        int start = 0, end = 0;
        for (int i = 0; i < (int)s.size(); i++) {
            end = max(end, last[s[i]-'a']);
            if (i == end) { result.push_back(end - start + 1); start = end + 1; }
        }
        return result;
    }
};
