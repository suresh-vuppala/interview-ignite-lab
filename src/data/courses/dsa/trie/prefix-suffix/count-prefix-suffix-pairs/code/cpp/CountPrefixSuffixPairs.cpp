// ============================================================
// Solution 1: Brute Force
// ============================================================
#include <vector>
#include <string>
#include <unordered_set>
using namespace std;

class Solution1 {
public:
    // Brute force: use hash set / nested loops / direct comparison
    // See Solution 2 below for the optimal Trie-based approach
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
