// ============================================================
// Group Anagrams
// ============================================================

#include <vector>
#include <string>
#include <unordered_map>
#include <algorithm>
using namespace std;

// ============================================================
// Solution 1: Sort Each String as Key
// Time: O(N × K log K) | Space: O(N × K)
// ============================================================
class Solution1 {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> groups;

        for (const string& s : strs) {
            // Sort the string to get canonical form
            string key = s;
            sort(key.begin(), key.end());

            // Group by sorted key
            groups[key].push_back(s);
        }

        // Collect all groups
        vector<vector<string>> result;
        for (auto& [key, group] : groups) {
            result.push_back(group);
        }
        return result;
    }
};

// ============================================================
// Solution 2: Character Frequency Count as Key (Optimal)
// Time: O(N × K) | Space: O(N × K)
// ============================================================
class Solution2 {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> groups;

        for (const string& s : strs) {
            // Count character frequencies
            int freq[26] = {};
            for (char c : s) freq[c - 'a']++;

            // Build key from frequency counts: "1#0#0#..."
            string key;
            for (int i = 0; i < 26; i++) {
                key += to_string(freq[i]) + "#";
            }

            groups[key].push_back(s);
        }

        vector<vector<string>> result;
        for (auto& [key, group] : groups) {
            result.push_back(group);
        }
        return result;
    }
};
