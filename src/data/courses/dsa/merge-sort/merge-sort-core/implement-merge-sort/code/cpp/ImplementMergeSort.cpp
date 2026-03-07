#include <vector>
using namespace std;

class Solution {
public:
    void mergeSort(vector<int>& arr) {
        if (arr.size() <= 1) return;
        mergeSortHelper(arr, 0, arr.size() - 1);
    }
    
private:
    void mergeSortHelper(vector<int>& arr, int left, int right) {
        if (left >= right) return;
        
        int mid = left + (right - left) / 2;
        mergeSortHelper(arr, left, mid);
        mergeSortHelper(arr, mid + 1, right);
        merge(arr, left, mid, right);
    }
    
    void merge(vector<int>& arr, int left, int mid, int right) {
        vector<int> L(arr.begin() + left, arr.begin() + mid + 1);
        vector<int> R(arr.begin() + mid + 1, arr.begin() + right + 1);
        
        int i = 0, j = 0, k = left;
        
        while (i < L.size() && j < R.size()) {
            if (L[i] <= R[j]) {
                arr[k++] = L[i++];
            } else {
                arr[k++] = R[j++];
            }
        }
        
        while (i < L.size()) arr[k++] = L[i++];
        while (j < R.size()) arr[k++] = R[j++];
    }
};
