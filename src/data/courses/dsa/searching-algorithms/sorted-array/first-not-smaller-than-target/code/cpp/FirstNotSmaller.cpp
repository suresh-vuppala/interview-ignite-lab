#include <iostream>
#include <vector>
using namespace std;

/**
 * Find first element >= target in sorted array
 * Time: O(log n), Space: O(1)
 */
int firstNotSmaller(vector<int>& nums, int target) {
    int left = 0, right = nums.size();
    
    while (left < right) {
        int mid = left + (right - left) / 2;
        
        if (nums[mid] < target) {
            left = mid + 1;   // Answer is in right half
        } else {
            right = mid;      // Answer might be here or left
        }
    }
    
    return left < nums.size() ? nums[left] : -1;
}

int main() {
    vector<int> nums = {1, 3, 5, 7, 9, 11, 13};
    int target = 6;
    
    int result = firstNotSmaller(nums, target);
    cout << "First element >= " << target << ": " << result << endl; // Output: 7
    
    return 0;
}
