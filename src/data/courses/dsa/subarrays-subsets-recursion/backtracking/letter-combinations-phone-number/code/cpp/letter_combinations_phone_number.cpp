#include <vector>
#include <string>
using namespace std;
// ============================================================
// Solution 1: Iterative — build combinations level by level — O(4^N)
// ============================================================
class Solution1 {
    string mapping[10] = {"","","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
public:
    vector<string> letterCombinations(string digits) {
        if (digits.empty()) return {};
        vector<string> result = {""};
        for (char d : digits) {
            vector<string> next;
            for (auto& s : result)
                for (char c : mapping[d - '0'])
                    next.push_back(s + c);
            result = next;
        }
        return result;
    }
};

// ============================================================
// Solution 2: Backtracking — O(4^N) Time, O(N) Space
// ============================================================
class Solution2 {
    string mapping[10] = {"","","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
    void bt(string& digits, int idx, string& cur, vector<string>& res) {
        if (idx == (int)digits.size()) { res.push_back(cur); return; }
        for (char c : mapping[digits[idx] - '0']) {
            cur.push_back(c);
            bt(digits, idx + 1, cur, res);
            cur.pop_back();
        }
    }
public:
    vector<string> letterCombinations(string digits) {
        if (digits.empty()) return {};
        vector<string> res; string cur;
        bt(digits, 0, cur, res); return res;
    }
};
