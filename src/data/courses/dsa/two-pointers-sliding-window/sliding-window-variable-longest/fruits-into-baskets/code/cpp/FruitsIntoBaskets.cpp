#include <vector>
#include <unordered_map>
#include <algorithm>
using namespace std;
// ============================================================
// Solution 1: Brute Force — try all subarrays with ≤2 types — O(N²)
// ============================================================
class Solution1 {
public:
    int totalFruit(vector<int>& fruits) {
        int n = fruits.size(), maxLen = 0;
        for (int i = 0; i < n; i++) {
            unordered_map<int, int> basket;
            for (int j = i; j < n; j++) {
                basket[fruits[j]]++;
                if (basket.size() > 2) break;
                maxLen = max(maxLen, j - i + 1);
            }
        }
        return maxLen;
    }
};

// ============================================================
// Solution 2: Sliding Window — at most 2 distinct types — O(N)
// ============================================================
class Solution2 {
public:
    int totalFruit(vector<int>& fruits) {
        unordered_map<int, int> basket;
        int left = 0, maxLen = 0;
        for (int right = 0; right < (int)fruits.size(); right++) {
            basket[fruits[right]]++;
            while (basket.size() > 2) {
                basket[fruits[left]]--;
                if (basket[fruits[left]] == 0) basket.erase(fruits[left]);
                left++;
            }
            maxLen = max(maxLen, right - left + 1);
        }
        return maxLen;
    }
};
