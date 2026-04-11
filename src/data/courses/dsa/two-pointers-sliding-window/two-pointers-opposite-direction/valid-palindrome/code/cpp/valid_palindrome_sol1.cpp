class Solution {
public:
    // Filter + Reverse: O(n) space
    bool isPalindrome(string s) {
        string clean;
        for (char c : s)
            if (isalnum(c)) clean += tolower(c);
        string rev = clean;
        reverse(rev.begin(), rev.end());
        return clean == rev;
    }
};