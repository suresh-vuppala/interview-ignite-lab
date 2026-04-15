#include <vector>
#include <algorithm>
#include <numeric>
using namespace std;
// ============================================================
// Solution 1: Brute Force — iterate until stable — O(N²)
// ============================================================
class Solution1 {
public:
    int candy(vector<int>& ratings) {
        int n = ratings.size();
        vector<int> candies(n, 1);
        bool changed = true;
        while (changed) {
            changed = false;
            for (int i = 0; i < n; i++) {
                if (i > 0 && ratings[i] > ratings[i-1] && candies[i] <= candies[i-1])
                    { candies[i] = candies[i-1] + 1; changed = true; }
                if (i < n-1 && ratings[i] > ratings[i+1] && candies[i] <= candies[i+1])
                    { candies[i] = candies[i+1] + 1; changed = true; }
            }
        }
        return accumulate(candies.begin(), candies.end(), 0);
    }
};

// ============================================================
// Solution 2: Two-pass greedy — left-to-right then right-to-left — O(N)
// ============================================================
class Solution2 {
public:
    int candy(vector<int>& ratings) {
        int n = ratings.size();
        vector<int> candies(n, 1);
        for (int i = 1; i < n; i++) // Left to right
            if (ratings[i] > ratings[i-1]) candies[i] = candies[i-1] + 1;
        for (int i = n-2; i >= 0; i--) // Right to left
            if (ratings[i] > ratings[i+1]) candies[i] = max(candies[i], candies[i+1] + 1);
        return accumulate(candies.begin(), candies.end(), 0);
    }
};
