import os

base = "src/data/courses/dsa/sorting-algorithms/quick-sort"

# Quick Sort
quick_sort_java = """class QuickSort {
    public void quickSort(int[] arr, int low, int high) {
        if (low < high) {
            int pi = partition(arr, low, high); // Get partition index
            quickSort(arr, low, pi - 1); // Sort left half
            quickSort(arr, pi + 1, high); // Sort right half
        }
    }
    
    private int partition(int[] arr, int low, int high) {
        int pivot = arr[high]; // Choose last element as pivot
        int i = low - 1; // Index of smaller element
        for (int j = low; j < high; j++) {
            if (arr[j] < pivot) { // If current element is smaller than pivot
                i++;
                int temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
        // Place pivot in correct position
        int temp = arr[i + 1];
        arr[i + 1] = arr[high];
        arr[high] = temp;
        return i + 1;
    }
}"""

quick_sort_cpp = """class QuickSort {
public:
    void quickSort(vector<int>& arr, int low, int high) {
        if (low < high) {
            int pi = partition(arr, low, high); // Get partition index
            quickSort(arr, low, pi - 1); // Sort left half
            quickSort(arr, pi + 1, high); // Sort right half
        }
    }
    
private:
    int partition(vector<int>& arr, int low, int high) {
        int pivot = arr[high]; // Choose last element as pivot
        int i = low - 1; // Index of smaller element
        for (int j = low; j < high; j++) {
            if (arr[j] < pivot) { // If current element is smaller than pivot
                i++;
                swap(arr[i], arr[j]);
            }
        }
        swap(arr[i + 1], arr[high]); // Place pivot in correct position
        return i + 1;
    }
};"""

quick_sort_python = """def quick_sort(arr, low, high):
    if low < high:
        pi = partition(arr, low, high)  # Get partition index
        quick_sort(arr, low, pi - 1)  # Sort left half
        quick_sort(arr, pi + 1, high)  # Sort right half

def partition(arr, low, high):
    pivot = arr[high]  # Choose last element as pivot
    i = low - 1  # Index of smaller element
    for j in range(low, high):
        if arr[j] < pivot:  # If current element is smaller than pivot
            i += 1
            arr[i], arr[j] = arr[j], arr[i]
    arr[i + 1], arr[high] = arr[high], arr[i + 1]  # Place pivot in correct position
    return i + 1"""

# Kth Smallest
kth_smallest_java = """class KthSmallestElement {
    public int findKthSmallest(int[] arr, int k) {
        return quickSelect(arr, 0, arr.length - 1, k - 1); // k-1 because 0-indexed
    }
    
    private int quickSelect(int[] arr, int low, int high, int k) {
        int pi = partition(arr, low, high); // Partition array
        if (pi == k) return arr[pi]; // Found kth smallest
        if (pi > k) return quickSelect(arr, low, pi - 1, k); // Search left
        return quickSelect(arr, pi + 1, high, k); // Search right
    }
    
    private int partition(int[] arr, int low, int high) {
        int pivot = arr[high];
        int i = low - 1;
        for (int j = low; j < high; j++) {
            if (arr[j] < pivot) {
                i++;
                int temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
        int temp = arr[i + 1];
        arr[i + 1] = arr[high];
        arr[high] = temp;
        return i + 1;
    }
}"""

kth_smallest_cpp = """class KthSmallestElement {
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
};"""

kth_smallest_python = """def find_kth_smallest(arr, k):
    return quick_select(arr, 0, len(arr) - 1, k - 1)  # k-1 because 0-indexed

def quick_select(arr, low, high, k):
    pi = partition(arr, low, high)  # Partition array
    if pi == k:
        return arr[pi]  # Found kth smallest
    if pi > k:
        return quick_select(arr, low, pi - 1, k)  # Search left
    return quick_select(arr, pi + 1, high, k)  # Search right

def partition(arr, low, high):
    pivot = arr[high]
    i = low - 1
    for j in range(low, high):
        if arr[j] < pivot:
            i += 1
            arr[i], arr[j] = arr[j], arr[i]
    arr[i + 1], arr[high] = arr[high], arr[i + 1]
    return i + 1"""

# Kth Largest
kth_largest_java = """class KthLargestElement {
    public int findKthLargest(int[] arr, int k) {
        return quickSelect(arr, 0, arr.length - 1, arr.length - k); // Convert to 0-indexed position
    }
    
    private int quickSelect(int[] arr, int low, int high, int k) {
        int pi = partition(arr, low, high); // Partition array
        if (pi == k) return arr[pi]; // Found kth largest
        if (pi > k) return quickSelect(arr, low, pi - 1, k); // Search left
        return quickSelect(arr, pi + 1, high, k); // Search right
    }
    
    private int partition(int[] arr, int low, int high) {
        int pivot = arr[high];
        int i = low - 1;
        for (int j = low; j < high; j++) {
            if (arr[j] < pivot) {
                i++;
                int temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
        int temp = arr[i + 1];
        arr[i + 1] = arr[high];
        arr[high] = temp;
        return i + 1;
    }
}"""

kth_largest_cpp = """class KthLargestElement {
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
};"""

kth_largest_python = """def find_kth_largest(arr, k):
    return quick_select(arr, 0, len(arr) - 1, len(arr) - k)  # Convert to 0-indexed position

def quick_select(arr, low, high, k):
    pi = partition(arr, low, high)  # Partition array
    if pi == k:
        return arr[pi]  # Found kth largest
    if pi > k:
        return quick_select(arr, low, pi - 1, k)  # Search left
    return quick_select(arr, pi + 1, high, k)  # Search right

def partition(arr, low, high):
    pivot = arr[high]
    i = low - 1
    for j in range(low, high):
        if arr[j] < pivot:
            i += 1
            arr[i], arr[j] = arr[j], arr[i]
    arr[i + 1], arr[high] = arr[high], arr[i + 1]
    return i + 1"""

# Write files
with open(f"{base}/code/java/QuickSort.java", "w") as f:
    f.write(quick_sort_java)
with open(f"{base}/code/cpp/QuickSort.cpp", "w") as f:
    f.write(quick_sort_cpp)
with open(f"{base}/code/python/quick-sort.py", "w") as f:
    f.write(quick_sort_python)

with open(f"{base}/kth-smallest-element/code/java/KthSmallestElement.java", "w") as f:
    f.write(kth_smallest_java)
with open(f"{base}/kth-smallest-element/code/cpp/KthSmallestElement.cpp", "w") as f:
    f.write(kth_smallest_cpp)
with open(f"{base}/kth-smallest-element/code/python/kth-smallest-element.py", "w") as f:
    f.write(kth_smallest_python)

with open(f"{base}/kth-largest-element/code/java/KthLargestElement.java", "w") as f:
    f.write(kth_largest_java)
with open(f"{base}/kth-largest-element/code/cpp/KthLargestElement.cpp", "w") as f:
    f.write(kth_largest_cpp)
with open(f"{base}/kth-largest-element/code/python/kth-largest-element.py", "w") as f:
    f.write(kth_largest_python)

print("Quick Sort lessons updated with comments")
