#include <vector>
#include <unordered_map>
#include <algorithm>
using namespace std;
// ============================================================
// Solution 1: Brute Force — check all intervals — O(N²)
// ============================================================
class Solution1 {
public:
    int longestWPI(vector<int>& hours) {
        int n = hours.size(), maxLen = 0;
        for (int i = 0; i < n; i++) {
            int tiring = 0;
            for (int j = i; j < n; j++) {
                if (hours[j] > 8) tiring++; else tiring--;
                if (tiring > 0) maxLen = max(maxLen, j - i + 1);
            }
        }
        return maxLen;
    }
};

// ============================================================
// Solution 2: Prefix Sum + HashMap (first occurrence of each sum) — O(N)
// ============================================================
class Solution2 {
public:
    int longestWPI(vector<int>& hours) {
        unordered_map<int,int> first;
        int sum = 0, maxLen = 0;
        for (int i = 0; i < (int)hours.size(); i++) {
            sum += (hours[i] > 8) ? 1 : -1;
            if (sum > 0) maxLen = i + 1;
            else {
                if (first.count(sum - 1)) maxLen = max(maxLen, i - first[sum - 1]);
                if (!first.count(sum)) first[sum] = i;
            }
        }
        return maxLen;
    }
};
