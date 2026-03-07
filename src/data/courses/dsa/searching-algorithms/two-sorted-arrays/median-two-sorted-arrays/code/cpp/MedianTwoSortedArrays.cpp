// Time: O(log(min(m, n)))
// Space: O(1)

#include <vector>
#include <algorithm>
#include <climits>
#include <iostream>
using namespace std;

class MedianTwoSortedArrays {
public:
    /**
     * Find median of two sorted arrays
     */
    static double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        if (nums1.size() > nums2.size()) {
            return findMedianSortedArrays(nums2, nums1);
        }
        
        int m = nums1.size(), n = nums2.size();
        int low = 0, high = m;
        
        while (low <= high) {
            int cut1 = (low + high) / 2;
            int cut2 = (m + n + 1) / 2 - cut1;
            
            int left1 = (cut1 == 0) ? INT_MIN : nums1[cut1 - 1];
            int right1 = (cut1 == m) ? INT_MAX : nums1[cut1];
            int left2 = (cut2 == 0) ? INT_MIN : nums2[cut2 - 1];
            int right2 = (cut2 == n) ? INT_MAX : nums2[cut2];
            
            if (left1 <= right2 && left2 <= right1) {
                if ((m + n) % 2 == 1) {
                    return max(left1, left2);
                }
                return (max(left1, left2) + min(right1, right2)) / 2.0;
            } else if (left1 > right2) {
                high = cut1 - 1;
            } else {
                low = cut1 + 1;
            }
        }
        
        return 0.0;
    }
};

int main() {
    vector<int> nums1 = {1, 3};
    vector<int> nums2 = {2};
    
    double result = MedianTwoSortedArrays::findMedianSortedArrays(nums1, nums2);
    cout << "Median: " << result << endl; // Output: 2.0
    
    return 0;
}
