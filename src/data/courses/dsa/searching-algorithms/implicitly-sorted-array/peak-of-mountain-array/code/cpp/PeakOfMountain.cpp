#include <iostream>
#include <vector>
using namespace std;

/**
 * Find peak index in a mountain array
 * Time: O(log n), Space: O(1)
 */
int findPeak(vector<int>& nums) {
    int left = 0, right = nums.size() - 1;
    
    while (left < right) {
        int mid = left + (right - left) / 2;
        
        // If we're on uphill side, peak is to the right
        if (nums[mid] < nums[mid + 1]) {
            left = mid + 1;
        } else {
            // We're on downhill side or at peak
            right = mid;
        }
    }
    
    return left;
}

int main() {
    vector<int> nums1 = {1, 3, 5, 4, 2};
    cout << "Peak index: " << findPeak(nums1) << endl;  // Output: 2
    cout << "Peak value: " << nums1[findPeak(nums1)] << endl;  // Output: 5
    
    vector<int> nums2 = {0, 10, 5, 2};
    cout << "Peak index: " << findPeak(nums2) << endl;  // Output: 1
    cout << "Peak value: " << nums2[findPeak(nums2)] << endl;  // Output: 10
    
    return 0;
}
