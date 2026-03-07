// Time: O(N²), Space: O(1)

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    void selectionSort(vector<int>& arr) {
        int n = arr.size();
        for (int i = 0; i < n; i++) {
            int minIdx = i;
            for (int j = i + 1; j < n; j++) {
                if (arr[j] < arr[minIdx]) {
                    minIdx = j;
                }
            }
            swap(arr[i], arr[minIdx]);
        }
    }
};

int main() {
    Solution sol;
    vector<int> arr = {64, 34, 25, 12, 22, 11, 90};
    sol.selectionSort(arr);
    for (int num : arr) cout << num << " ";
    cout << endl;
    return 0;
}
