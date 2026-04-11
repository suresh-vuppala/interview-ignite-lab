// ============================================================
// Two Sum II — Input Array Is Sorted
// ============================================================

#include <vector>
using namespace std;

// ============================================================
// Solution 1: Brute Force — All Pairs
// Time: O(N²) | Space: O(1)
// ============================================================
class Solution1 {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        for (int i = 0; i < numbers.size() - 1; i++) {
            for (int j = i + 1; j < numbers.size(); j++) {
                if (numbers[i] + numbers[j] == target) {
                    return {i + 1, j + 1}; // 1-indexed
                }
            }
        }
        return {};
    }
};

// ============================================================
// Solution 2: Two Pointers — Converge from Ends (Optimal)
// Time: O(N) | Space: O(1)
// ============================================================
class Solution2 {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int left = 0, right = numbers.size() - 1;

        while (left < right) {
            int sum = numbers[left] + numbers[right];

            if (sum == target) {
                return {left + 1, right + 1}; // Found — 1-indexed
            } else if (sum < target) {
                left++;   // Need larger sum — advance left
            } else {
                right--;  // Need smaller sum — retreat right
            }
        }

        return {};
    }
};
