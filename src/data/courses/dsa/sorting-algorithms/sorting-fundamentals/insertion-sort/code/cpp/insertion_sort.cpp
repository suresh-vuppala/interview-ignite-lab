// Time: O(N²), Space: O(1)

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    void insertionSort(vector<int>& arr) {
        int n = arr.size();
        for (int i = 1; i < n; i++) {
            int key = arr[i];
            int j = i - 1;
            while (j >= 0 && arr[j] > key) {
                arr[j + 1] = arr[j];
                j--;
            }
            arr[j + 1] = key;
        }
    }
};

int main() {
    Solution sol;
    vector<int> arr = {64, 34, 25, 12, 22, 11, 90};
    sol.insertionSort(arr);
    for (int num : arr) cout << num << " ";
    cout << endl;
    return 0;
}
