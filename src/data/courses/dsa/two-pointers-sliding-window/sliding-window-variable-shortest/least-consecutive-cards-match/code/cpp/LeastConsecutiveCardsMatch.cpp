#include <vector>
#include <unordered_map>
#include <algorithm>
#include <climits>
using namespace std;
// ============================================================
// Solution 1: Brute Force — check all subarrays for matching pair — O(N²)
// ============================================================
class Solution1 {
public:
    int minimumCardPickup(vector<int>& cards) {
        int n = cards.size(), minLen = INT_MAX;
        for (int i = 0; i < n; i++)
            for (int j = i + 1; j < n; j++)
                if (cards[i] == cards[j]) { minLen = min(minLen, j - i + 1); break; }
        return minLen == INT_MAX ? -1 : minLen;
    }
};

// ============================================================
// Solution 2: HashMap — track last seen index — O(N)
// ============================================================
class Solution2 {
public:
    int minimumCardPickup(vector<int>& cards) {
        unordered_map<int, int> lastSeen;
        int minLen = INT_MAX;
        for (int i = 0; i < (int)cards.size(); i++) {
            if (lastSeen.count(cards[i]))
                minLen = min(minLen, i - lastSeen[cards[i]] + 1);
            lastSeen[cards[i]] = i;
        }
        return minLen == INT_MAX ? -1 : minLen;
    }
};
