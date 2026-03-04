class KthLargestElement {
public:
    int findKthLargest(vector<int>& arr, int k) {
        return quickSelect(arr, 0, arr.size() - 1, arr.size() - k); // Convert to 0-indexed position
    }
    
private:
    int quickSelect(vector<int>& arr, int low, int high, int k) {
        int pi = partition(arr, low, high); // Partition array
        if (pi == k) return arr[pi]; // Found kth largest
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