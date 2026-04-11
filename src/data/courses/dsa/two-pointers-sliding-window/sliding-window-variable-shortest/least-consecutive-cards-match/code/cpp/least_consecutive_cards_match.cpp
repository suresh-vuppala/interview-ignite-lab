// ============================================================
// Least Consecutive Cards to Match
// ============================================================

#include <vector>
#include <unordered_map>
#include <climits>
using namespace std;

// ============================================================
// Solution 1: Brute Force
// Time: O(N²) | Space: O(1)
// ============================================================
class Solution1 {
public:
    int minimumCardPickup(vector<int>& cards) {
        int minLen = INT_MAX;
        for (int i = 0; i < cards.size(); i++) {
            for (int j = i + 1; j < cards.size(); j++) {
                if (cards[i] == cards[j]) {
                    minLen = min(minLen, j - i + 1);
                    break; // First match from i gives shortest
                }
            }
        }
        return minLen == INT_MAX ? -1 : minLen;
    }
};

// ============================================================
// Solution 2: Hash Map — Track Last Seen (Optimal)
// Time: O(N) | Space: O(N)
// ============================================================
class Solution2 {
public:
    int minimumCardPickup(vector<int>& cards) {
        unordered_map<int, int> lastSeen;
        int minLen = INT_MAX;

        for (int i = 0; i < cards.size(); i++) {
            // If this value was seen before → compute window size
            if (lastSeen.count(cards[i])) {
                minLen = min(minLen, i - lastSeen[cards[i]] + 1);
            }

            // Update last seen position
            lastSeen[cards[i]] = i;
        }

        return minLen == INT_MAX ? -1 : minLen;
    }
};
