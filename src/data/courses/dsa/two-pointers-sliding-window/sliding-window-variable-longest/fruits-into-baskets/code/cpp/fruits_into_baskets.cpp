#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <algorithm>
using namespace std;

// Time: O(N³), Space: O(N)
class FruitsIntoBaskets {
public:
    int totalFruitBruteForce(vector<int>& fruits) {
        int n = fruits.size(), maxLen = 0;
        for (int i = 0; i < n; i++) {
            for (int j = i; j < n; j++) {
                unordered_set<int> types;
                for (int p = i; p <= j; p++) types.insert(fruits[p]);
                if (types.size() <= 2) maxLen = max(maxLen, j - i + 1);
            }
        }
        return maxLen;
    }

    // ============================================================

    // Time: O(N²), Space: O(2)
    int totalFruitBruteOptimized(vector<int>& fruits) {
        int n = fruits.size(), maxLen = 0;
        for (int i = 0; i < n; i++) {
            unordered_set<int> types;
            for (int j = i; j < n; j++) {
                types.insert(fruits[j]);
                if (types.size() <= 2) maxLen = max(maxLen, j - i + 1);
                else break;
            }
        }
        return maxLen;
    }

    // ============================================================

    // Time: O(N²), Space: O(2)
    int totalFruitTwoPointerShrink(vector<int>& fruits) {
        int n = fruits.size(), maxLen = 0;
        for (int i = 0; i < n; i++) {
            unordered_map<int, int> freq;
            int j = i;
            while (j < n) {
                freq[fruits[j]]++;
                if (freq.size() <= 2) {
                    maxLen = max(maxLen, j - i + 1);
                    j++;
                } else break;
            }
        }
        return maxLen;
    }

    // ============================================================

    // Time: O(N), Space: O(2)
    int totalFruitSlidingWindow(vector<int>& fruits) {
        int left = 0, maxLen = 0;
        unordered_map<int, int> freq;
        for (int right = 0; right < fruits.size(); right++) {
            freq[fruits[right]]++;
            while (freq.size() > 2) {
                freq[fruits[left]]--;
                if (freq[fruits[left]] == 0) freq.erase(fruits[left]);
                left++;
            }
            maxLen = max(maxLen, right - left + 1);
        }
        return maxLen;
    }

    // ============================================================

    // Time: O(N), Space: O(2)
    int totalFruitSlidingWindowOptimized(vector<int>& fruits) {
        int left = 0;
        unordered_map<int, int> freq;
        for (int right = 0; right < fruits.size(); right++) {
            freq[fruits[right]]++;
            if (freq.size() > 2) {
                freq[fruits[left]]--;
                if (freq[fruits[left]] == 0) freq.erase(fruits[left]);
                left++;
            }
        }
        return fruits.size() - left;
    }
};
