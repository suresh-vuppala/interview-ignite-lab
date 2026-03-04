class KthSmallestElement {
public:
    int findKthSmallest(vector<int>& arr, int k) {
        return quickSelect(arr, 0, arr.size() - 1, k - 1); // k-1 because 0-indexed
    }
    
private:
    int quickSelect(vector<int>& arr, int low, int high, int k) {
        int pi = partition(arr, low, high); // Partition array
        if (pi == k) return arr[pi]; // Found kth smallest
        if (pi > k) return quickSelect(arr, low, pi - 1, k); // Search left
        return quickSelect(arr, pi + 1, high, k); // Search right
    }
    
    int partition(vector<int>& arr, int low, int high) {
        int pivot = arr[high];
        int i = low - 1;
        for (int j = low; j < high; j++) {
            if (arr[j] < pivot) {
                i++;
                swap(arr[i], arr[j]);
            }
        }
        swap(arr[i + 1], arr[high]);
        return i + 1;
    }
};