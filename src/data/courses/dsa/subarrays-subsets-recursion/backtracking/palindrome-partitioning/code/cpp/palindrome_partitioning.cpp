// Time: O(N × 2^N), Space: O(N)

#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    vector<vector<string>> partition(string s) {
        vector<vector<string>> result;
        vector<string> current;
        backtrack(s, 0, current, result);
        return result;
    }
    
private:
    void backtrack(string& s, int index, vector<string>& current, vector<vector<string>>& result) {
        if (index == s.size()) {
            result.push_back(current);
            return;
        }
        
        for (int end = index; end < s.size(); end++) {
            if (isPalindrome(s, index, end)) {
                current.push_back(s.substr(index, end - index + 1));
                backtrack(s, end + 1, current, result);
                current.pop_back();
            }
        }
    }
    
    bool isPalindrome(string& s, int left, int right) {
        while (left < right) {
            if (s[left++] != s[right--]) return false;
        }
        return true;
    }
};

int main() {
    Solution sol;
    vector<vector<string>> result = sol.partition("aab");
    for (auto& partition : result) {
        for (string s : partition) cout << s << " ";
        cout << endl;
    }
    return 0;
}
