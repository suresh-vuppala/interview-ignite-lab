// ============================================================
// Merge Sorted Array
// ============================================================

#include <vector>
#include <algorithm>
using namespace std;

// ============================================================
// Solution 1: Copy + Sort
// Time: O((M+N) log(M+N)) | Space: O(1)
// ============================================================
class Solution1 {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        // Copy nums2 into the back of nums1
        for (int i = 0; i < n; i++) {
            nums1[m + i] = nums2[i];
        }

        // Sort the entire array
        sort(nums1.begin(), nums1.end());
    }
};

// ============================================================
// Solution 2: Three Pointers from End (Optimal)
// Time: O(M+N) | Space: O(1)
// ============================================================
class Solution2 {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int i = m - 1;       // Last real element in nums1
        int j = n - 1;       // Last element in nums2
        int k = m + n - 1;   // Last position in merged array

        // Fill from back: place larger element at position k
        while (j >= 0) {
            if (i >= 0 && nums1[i] > nums2[j]) {
                nums1[k--] = nums1[i--]; // nums1's element is larger
            } else {
                nums1[k--] = nums2[j--]; // nums2's element is larger (or equal)
            }
        }
        // If j < 0 but i >= 0, nums1 elements are already in place
    }
};
