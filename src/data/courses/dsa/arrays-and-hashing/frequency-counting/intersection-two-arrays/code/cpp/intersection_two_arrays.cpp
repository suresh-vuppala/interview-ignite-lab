// ============================================================
// Intersection of Two Arrays II
// ============================================================

#include <vector>
#include <unordered_map>
#include <algorithm>
using namespace std;

// ============================================================
// Solution 1: Sort + Two Pointers
// Time: O(N log N + M log M) | Space: O(1) extra
// ============================================================
class Solution1 {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        sort(nums1.begin(), nums1.end());
        sort(nums2.begin(), nums2.end());

        vector<int> result;
        int i = 0, j = 0;

        while (i < nums1.size() && j < nums2.size()) {
            if (nums1[i] == nums2[j]) {
                result.push_back(nums1[i]);
                i++; j++;                    // Both match — advance both
            } else if (nums1[i] < nums2[j]) {
                i++;                          // nums1 smaller — advance
            } else {
                j++;                          // nums2 smaller — advance
            }
        }

        return result;
    }
};

// ============================================================
// Solution 2: Hash Map Frequency (Optimal)
// Time: O(N + M) | Space: O(min(N,M))
// ============================================================
class Solution2 {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        // Build frequency map from smaller array
        if (nums1.size() > nums2.size()) return intersect(nums2, nums1);

        unordered_map<int, int> freq;
        for (int num : nums1) freq[num]++;

        // Consume matches from larger array
        vector<int> result;
        for (int num : nums2) {
            if (freq[num] > 0) {
                result.push_back(num);
                freq[num]--;          // Consume one occurrence
            }
        }

        return result;
    }
};
