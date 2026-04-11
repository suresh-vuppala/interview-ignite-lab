// ============================================================
// Valid Palindrome
// ============================================================

#include <string>
#include <algorithm>
using namespace std;

// ============================================================
// Solution 1: Filter + Reverse
// Time: O(N) | Space: O(N)
// ============================================================
class Solution1 {
public:
    bool isPalindrome(string s) {
        // Build cleaned string
        string clean;
        for (char c : s) {
            if (isalnum(c)) clean += tolower(c);
        }

        // Compare with reverse
        string rev = clean;
        reverse(rev.begin(), rev.end());
        return clean == rev;
    }
};

// ============================================================
// Solution 2: Two Pointers In-Place (Optimal)
// Time: O(N) | Space: O(1)
// ============================================================
class Solution2 {
public:
    bool isPalindrome(string s) {
        int left = 0, right = s.size() - 1;

        while (left < right) {
            // Skip non-alphanumeric from left
            while (left < right && !isalnum(s[left])) left++;

            // Skip non-alphanumeric from right
            while (left < right && !isalnum(s[right])) right--;

            // Compare lowercase characters
            if (tolower(s[left]) != tolower(s[right])) {
                return false;
            }

            left++;
            right--;
        }

        return true; // All pairs matched
    }
};
