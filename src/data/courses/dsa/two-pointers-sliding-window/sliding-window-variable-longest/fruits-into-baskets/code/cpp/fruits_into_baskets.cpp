// ============================================================
// Fruits Into Baskets (Longest with 2 Distinct)
// ============================================================

#include <vector>
#include <unordered_map>
using namespace std;

// ============================================================
// Solution 1: Brute Force
// Time: O(N²) | Space: O(N)
// ============================================================
class Solution1 {
public:
    int totalFruit(vector<int>& fruits) {
        int maxLen = 0;
        for (int i = 0; i < fruits.size(); i++) {
            unordered_map<int,int> freq;
            for (int j = i; j < fruits.size(); j++) {
                freq[fruits[j]]++;
                if (freq.size() > 2) break;
                maxLen = max(maxLen, j - i + 1);
            }
        }
        return maxLen;
    }
};

// ============================================================
// Solution 2: Sliding Window + Frequency Map (Optimal)
// Time: O(N) | Space: O(1)
// ============================================================
class Solution2 {
public:
    int totalFruit(vector<int>& fruits) {
        unordered_map<int, int> freq;
        int left = 0, maxLen = 0;

        for (int right = 0; right < fruits.size(); right++) {
            freq[fruits[right]]++;

            // Shrink while more than 2 distinct types
            while (freq.size() > 2) {
                freq[fruits[left]]--;
                if (freq[fruits[left]] == 0) freq.erase(fruits[left]);
                left++;
            }

            maxLen = max(maxLen, right - left + 1);
        }

        return maxLen;
    }
};
