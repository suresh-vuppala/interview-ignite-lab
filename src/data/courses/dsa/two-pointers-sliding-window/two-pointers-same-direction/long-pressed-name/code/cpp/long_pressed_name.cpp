// ============================================================
// Long Pressed Name
// ============================================================

#include <string>
using namespace std;

// ============================================================
// Solution: Two Pointers
// Time: O(N+M) | Space: O(1)
// ============================================================
class Solution {
public:
    bool isLongPressedName(string name, string typed) {
        int i = 0, j = 0;

        while (j < typed.size()) {
            if (i < name.size() && name[i] == typed[j]) {
                // Normal match — advance both
                i++;
                j++;
            } else if (j > 0 && typed[j] == typed[j - 1]) {
                // Long press — skip this repeated character
                j++;
            } else {
                // Mismatch — not a valid long press
                return false;
            }
        }

        // All characters in name must be consumed
        return i == name.size();
    }
};
