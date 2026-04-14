// ============================================================
// Solution 1: Check all pairs naively
// Time: O(N² * L) | Space: O(1)
// ============================================================
#include <vector>
#include <string>
using namespace std;

class Solution1 {
public:
    int countPrefixSuffixPairs(vector<string>& words) {
        int count = 0, n = words.size();
        for (int i = 0; i < n; i++)
            for (int j = i + 1; j < n; j++) {
                string& a = words[i], & b = words[j];
                if (a.size() <= b.size() &&
                    b.substr(0, a.size()) == a &&        // is prefix
                    b.substr(b.size() - a.size()) == a)  // is suffix
                    count++;
            }
        return count;  // O(N²*L) — check every pair
    }
};

// ============================================================
// Solution 2: Optimal (Trie-based)
// ============================================================
#include <vector>
#include <string>
using namespace std;

// Time: O(N²*L) | Space: O(1)

class Solution {
    bool isPrefixAndSuffix(const string& str1, const string& str2) {
        int len1 = str1.size(), len2 = str2.size();
        if (len1 > len2) return false;
        return str2.substr(0, len1) == str1 && str2.substr(len2 - len1) == str1;
    }
    
public:
    int countPrefixSuffixPairs(vector<string>& words) {
        int count = 0;
        for (int i = 0; i < words.size(); i++) {
            for (int j = i + 1; j < words.size(); j++) {
                if (isPrefixAndSuffix(words[i], words[j])) {
                    count++;
                }
            }
        }
        return count;
    }
};
