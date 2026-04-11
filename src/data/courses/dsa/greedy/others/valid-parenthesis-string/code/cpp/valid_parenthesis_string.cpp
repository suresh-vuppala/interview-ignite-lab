class Solution {
public:
    // O(n) time, O(1) space — Track min/max possible open count
    bool checkValidString(string s) {
        int minOpen = 0, maxOpen = 0;
        for (char c : s) {
            if (c == '(')      { minOpen++; maxOpen++; }
            else if (c == ')') { minOpen--; maxOpen--; }
            else /* '*' */     { minOpen--; maxOpen++; } // * can be (, ), or empty
            
            if (maxOpen < 0) return false; // Too many closing
            minOpen = max(minOpen, 0);     // Can't have negative open
        }
        return minOpen == 0; // All opened are closed
    }
};