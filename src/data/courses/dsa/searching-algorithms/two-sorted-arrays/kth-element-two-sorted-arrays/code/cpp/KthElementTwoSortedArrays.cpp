// Time: O(log(min(m, n)))
// Space: O(1)

#include <vector>
#include <algorithm>
#include <climits>
#include <iostream>
using namespace std;

class KthElementTwoSortedArrays {
public:
    /**
     * Find kth element of two sorted arrays
     */
    static int kthElement(vector<int>& nums1, vector<int>& nums2, int k) {
        int m = nums1.size(), n = nums2.size();
        
        if (m > n) {
            return kthElement(nums2, nums1, k);
        }
        
        int low = max(0, k - n);
        int high = min(k, m);
        
        while (low <= high) {
            int cut1 = (low + high) / 2;
            int cut2 = k - cut1;
            
            int left1 = (cut1 == 0) ? INT_MIN : nums1[cut1 - 1];
            int right1 = (cut1 == m) ? INT_MAX : nums1[cut1];
            int left2 = (cut2 == 0) ? INT_MIN : nums2[cut2 - 1];
            int right2 = (cut2 == n) ? INT_MAX : nums2[cut2];
            
            if (left1 <= right2 && left2 <= right1) {
                return max(left1, left2);
            } else if (left1 > right2) {
                high = cut1 - 1;
            } else {
                low = cut1 + 1;
            }
        }
        
        return -1;
    }
};

int main() {
    vector<int> nums1 = {2, 3, 6, 7, 9};
    vector<int> nums2 = {1, 4, 8, 10};
    int k = 5;
    
    int result = KthElementTwoSortedArrays::kthElement(nums1, nums2, k);
    cout << "Kth element: " << result << endl; // Output: 6
    
    return 0;
}
