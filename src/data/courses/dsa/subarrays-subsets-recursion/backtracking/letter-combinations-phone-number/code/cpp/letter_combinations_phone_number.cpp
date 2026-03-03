#include <vector>
#include <string>
using namespace std;

vector<string> map = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};

void backtrack(string& digits, int i, string& curr, vector<string>& result) {
    if (i == digits.size()) {
        result.push_back(curr);
        return;
    }
    string letters = map[digits[i] - '0'];
    for (char c : letters) {
        curr.push_back(c);
        backtrack(digits, i+1, curr, result);
        curr.pop_back();
    }
}

vector<string> letterCombinations(string digits) {
    vector<string> result;
    if (digits.empty()) return result;
    string curr;
    backtrack(digits, 0, curr, result);
    return result;
}