#include <vector>
using namespace std;
// ============================================================
// Solution 1: Brute Force — compute sum for each window — O(N*K)
// ============================================================
class Solution1 {
public:
    vector<int> subarraySums(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> result;
        for (int i = 0; i <= n - k; i++) {
            int sum = 0;
            for (int j = i; j < i + k; j++) sum += nums[j]; // O(K) per window
            result.push_back(sum);
        }
        return result;
    }
};

// ============================================================
// Solution 2: Sliding Window — add right, subtract left — O(N)
// ============================================================
class Solution2 {
public:
    vector<int> subarraySums(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> result;
        int sum = 0;
        for (int i = 0; i < k; i++) sum += nums[i]; // First window
        result.push_back(sum);
        for (int i = k; i < n; i++) {
            sum += nums[i] - nums[i - k]; // Slide: add right, remove left
            result.push_back(sum);
        }
        return result;
    }
};
