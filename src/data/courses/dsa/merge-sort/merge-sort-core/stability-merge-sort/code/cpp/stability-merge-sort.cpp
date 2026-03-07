// Time: O(N log N), Space: O(N)

#include <iostream>
#include <vector>
using namespace std;

struct Pair {
    int key;
    char value;
    Pair(int k, char v) : key(k), value(v) {}
};

void merge(vector<Pair>& arr, int left, int mid, int right) {
    int n1 = mid - left + 1;
    int n2 = right - mid;
    vector<Pair> L, R;
    
    for (int i = 0; i < n1; i++) L.push_back(arr[left + i]);
    for (int j = 0; j < n2; j++) R.push_back(arr[mid + 1 + j]);
    
    int i = 0, j = 0, k = left;
    while (i < n1 && j < n2) {
        if (L[i].key <= R[j].key) arr[k++] = L[i++];
        else arr[k++] = R[j++];
    }
    
    while (i < n1) arr[k++] = L[i++];
    while (j < n2) arr[k++] = R[j++];
}

void mergeSort(vector<Pair>& arr, int left, int right) {
    if (left < right) {
        int mid = left + (right - left) / 2;
        mergeSort(arr, left, mid);
        mergeSort(arr, mid + 1, right);
        merge(arr, left, mid, right);
    }
}

int main() {
    vector<Pair> arr = {{3, 'a'}, {1, 'b'}, {3, 'c'}, {2, 'd'}};
    mergeSort(arr, 0, arr.size() - 1);
    for (auto& p : arr) cout << "(" << p.key << "," << p.value << ") ";
    return 0;
}
