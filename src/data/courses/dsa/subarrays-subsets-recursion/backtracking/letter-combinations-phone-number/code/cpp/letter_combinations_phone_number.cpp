// Time: O(4^N × N), Space: O(N)

#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    vector<string> letterCombinations(string digits) {
        vector<string> result;
        if (digits.empty()) return result;
        
        vector<string> mapping = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
        string current;
        backtrack(digits, 0, current, mapping, result);
        return result;
    }
    
private:
    void backtrack(string& digits, int index, string& current, vector<string>& mapping, vector<string>& result) {
        if (index == digits.size()) {
            result.push_back(current);
            return;
        }
        
        string letters = mapping[digits[index] - '0'];
        for (char letter : letters) {
            current.push_back(letter);
            backtrack(digits, index + 1, current, mapping, result);
            current.pop_back();
        }
    }
};

int main() {
    Solution sol;
    vector<string> result = sol.letterCombinations("23");
    for (string s : result) cout << s << " ";
    cout << endl;
    return 0;
}
