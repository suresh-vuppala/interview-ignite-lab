#include <vector>
#include <deque>
using namespace std;
// ============================================================
// Solution 1: Brute Force — scan each window for first negative — O(N*K)
// ============================================================
class Solution1 {
public:
    vector<int> firstNegative(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> result;
        for (int i = 0; i <= n - k; i++) {
            int found = 0;
            for (int j = i; j < i + k; j++)
                if (nums[j] < 0) { found = nums[j]; break; }
            result.push_back(found);
        }
        return result;
    }
};

// ============================================================
// Solution 2: Deque of negative indices — O(N) Time
// ============================================================
class Solution2 {
public:
    vector<int> firstNegative(vector<int>& nums, int k) {
        int n = nums.size();
        deque<int> negIdx; // Indices of negatives in current window
        vector<int> result;
        for (int i = 0; i < n; i++) {
            if (nums[i] < 0) negIdx.push_back(i);
            if (i >= k - 1) {
                while (!negIdx.empty() && negIdx.front() < i - k + 1) negIdx.pop_front();
                result.push_back(negIdx.empty() ? 0 : nums[negIdx.front()]);
            }
        }
        return result;
    }
};
