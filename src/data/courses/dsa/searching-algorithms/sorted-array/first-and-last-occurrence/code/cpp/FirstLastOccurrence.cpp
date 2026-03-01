#include <vector>
using namespace std;

int findFirst(const vector<int>& arr, int target) {
    int low = 0, high = arr.size() - 1;
    int boundary = -1;
    while (low <= high) {
        int mid = low + (high - low) / 2;
        if (arr[mid] == target) {
            boundary = mid;
            high = mid - 1;
        } else if (arr[mid] < target) {
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }
    return boundary;
}

int findLast(const vector<int>& arr, int target) {
    int low = 0, high = arr.size() - 1;
    int boundary = -1;
    while (low <= high) {
        int mid = low + (high - low) / 2;
        if (arr[mid] == target) {
            boundary = mid;
            low = mid + 1;
        } else if (arr[mid] < target) {
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }
    return boundary;
}

vector<int> searchRange(vector<int>& nums, int target) {
    return {findFirst(nums, target), findLast(nums, target)};
}