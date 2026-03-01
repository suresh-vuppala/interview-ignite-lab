#include <iostream>
#include <vector>
using namespace std;

/**
 * Binary search - divide and conquer on sorted array
 * Time: O(log n), Space: O(1)
 */
int binarySearch(vector<int>& nums, int target) {
    int left = 0, right = nums.size() - 1;
    
    while (left <= right) {
        int mid = left + (right - left) / 2;
        
        if (nums[mid] == target) {
            return mid;
        } else if (nums[mid] < target) {
            left = mid + 1;  // Search right half
        } else {
            right = mid - 1; // Search left half
        }
    }
    
    return -1;
}

int main() {
    vector<int> nums = {1, 3, 5, 7, 9, 11, 13};
    int target = 7;
    
    int result = binarySearch(nums, target);
    cout << "Index: " << result << endl; // Output: 3
    
    return 0;
}
