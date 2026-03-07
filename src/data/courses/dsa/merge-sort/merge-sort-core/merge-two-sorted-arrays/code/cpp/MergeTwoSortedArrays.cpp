// Time: O(N+M) | Space: O(N+M) extra space, O(1) in-place

#include <vector>
using namespace std;

class Solution {
public:
    vector<int> mergeWithExtraSpace(vector<int>& arr1, vector<int>& arr2) {
        vector<int> result;
        int i = 0, j = 0;
        while (i < arr1.size() && j < arr2.size()) {
            if (arr1[i] <= arr2[j]) {
                result.push_back(arr1[i++]);
            } else {
                result.push_back(arr2[j++]);
            }
        }
        while (i < arr1.size()) result.push_back(arr1[i++]);
        while (j < arr2.size()) result.push_back(arr2[j++]);
        return result;
    }
    
    void mergeInPlace(vector<int>& arr1, int m, vector<int>& arr2, int n) {
        int i = m - 1, j = n - 1, k = m + n - 1;
        while (j >= 0) {
            if (i >= 0 && arr1[i] > arr2[j]) {
                arr1[k--] = arr1[i--];
            } else {
                arr1[k--] = arr2[j--];
            }
        }
    }
};
