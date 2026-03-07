// Time: O(N log N), Space: O(N)

#include <iostream>
#include <vector>
using namespace std;

int merge(vector<int>& arr, int left, int mid, int right) {
    vector<int> temp(right - left + 1);
    int i = left, j = mid + 1, k = 0, inversions = 0;
    
    while (i <= mid && j <= right) {
        if (arr[i] <= arr[j]) {
            temp[k++] = arr[i++];
        } else {
            temp[k++] = arr[j++];
            inversions += (mid - i + 1);
        }
    }
    
    while (i <= mid) temp[k++] = arr[i++];
    while (j <= right) temp[k++] = arr[j++];
    for (int i = 0; i < k; i++) arr[left + i] = temp[i];
    
    return inversions;
}

int mergeSort(vector<int>& arr, int left, int right) {
    int count = 0;
    if (left < right) {
        int mid = left + (right - left) / 2;
        count += mergeSort(arr, left, mid);
        count += mergeSort(arr, mid + 1, right);
        count += merge(arr, left, mid, right);
    }
    return count;
}

int main() {
    vector<int> arr = {8, 4, 2, 1};
    cout << "Inversions: " << mergeSort(arr, 0, arr.size() - 1) << endl;
    return 0;
}
