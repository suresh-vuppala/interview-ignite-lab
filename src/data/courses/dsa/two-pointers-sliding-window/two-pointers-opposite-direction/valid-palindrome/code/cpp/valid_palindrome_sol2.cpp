class Solution {
public:
    // Optimal: O(1) space — Two pointers, skip non-alphanumeric
    bool isPalindrome(string s) {
        int left = 0, right = s.size() - 1;
        while (left < right) {
            while (left < right && !isalnum(s[left])) left++;   // Skip junk
            while (left < right && !isalnum(s[right])) right--; // Skip junk
            if (tolower(s[left]) != tolower(s[right])) return false;
            left++; right--;
        }
        return true;
    }
};