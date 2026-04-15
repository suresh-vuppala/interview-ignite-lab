#include <string>
#include <vector>
#include <sstream>
using namespace std;
// ============================================================
// Solution 1: Delimiter-based — fails if delimiter appears in string
// ============================================================
class Solution1 {
public:
    string encode(vector<string>& strs) {
        string res;
        for (auto& s : strs) res += s + "\n"; // Newline delimiter
        return res;
        // Problem: breaks if strings contain \n!
    }
    vector<string> decode(string s) {
        vector<string> res;
        stringstream ss(s); string token;
        while (getline(ss, token)) res.push_back(token);
        if (!res.empty()) res.pop_back(); // Remove trailing empty
        return res;
    }
};

// ============================================================
// Solution 2: Length-prefix encoding — handles all characters — O(N)
// ============================================================
class Solution2 {
public:
    string encode(vector<string>& strs) {
        string res;
        for (auto& s : strs) res += to_string(s.size()) + "#" + s;
        return res;  // "4#code5#hello" — length tells where string ends
    }
    vector<string> decode(string s) {
        vector<string> res;
        int i = 0;
        while (i < (int)s.size()) {
            int j = i;
            while (s[j] != '#') j++; // Find delimiter
            int len = stoi(s.substr(i, j - i));
            res.push_back(s.substr(j + 1, len));
            i = j + 1 + len;
        }
        return res;
    }
};
