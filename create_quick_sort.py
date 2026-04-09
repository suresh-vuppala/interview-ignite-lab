import os
import json

base_path = "src/data/courses/dsa/sorting"
lesson_path = os.path.join(base_path, "quick-sort")
code_path = os.path.join(lesson_path, "code")

os.makedirs(os.path.join(code_path, "java"), exist_ok=True)
os.makedirs(os.path.join(code_path, "cpp"), exist_ok=True)
os.makedirs(os.path.join(code_path, "python"), exist_ok=True)

# Markdown
md_content = """## Problem Statement

Implement Quick Sort algorithm to sort an array in ascending order.

## Approach

Quick Sort uses divide-and-conquer:
1. Choose a pivot element
2. Partition array: elements < pivot on left, > pivot on right
3. Recursively sort left and right subarrays

## Complexity

- Time: O(n log n) average, O(n²) worst
- Space: O(log n) recursion stack

## Code

```code```"""

with open(os.path.join(lesson_path, "quick-sort.md"), "w", encoding="utf-8") as f:
    f.write(md_content)

# JSON
json_content = {
    "title": "Quick Sort",
    "description": "Implement Quick Sort algorithm",
    "difficulty": "medium",
    "isPremium": False,
    "isPosted": True
}

with open(os.path.join(lesson_path, "quick-sort.json"), "w", encoding="utf-8") as f:
    json.dump(json_content, f, indent=4)

# Java
java_code = """class QuickSort {
    public void quickSort(int[] arr, int low, int high) {
        if (low < high) {
            int pi = partition(arr, low, high);
            quickSort(arr, low, pi - 1);
            quickSort(arr, pi + 1, high);
        }
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

with open(os.path.join(code_path, "java", "QuickSort.java"), "w") as f:
    f.write(java_code)

# C++
cpp_code = """class QuickSort {
public:
    void quickSort(vector<int>& arr, int low, int high) {
        if (low < high) {
            int pi = partition(arr, low, high);
            quickSort(arr, low, pi - 1);
            quickSort(arr, pi + 1, high);
        }
    }
    
private:
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

with open(os.path.join(code_path, "cpp", "QuickSort.cpp"), "w") as f:
    f.write(cpp_code)

# Python
python_code = """def quick_sort(arr, low, high):
    if low < high:
        pi = partition(arr, low, high)
        quick_sort(arr, low, pi - 1)
        quick_sort(arr, pi + 1, high)

def partition(arr, low, high):
    pivot = arr[high]
    i = low - 1
    for j in range(low, high):
        if arr[j] < pivot:
            i += 1
            arr[i], arr[j] = arr[j], arr[i]
    arr[i + 1], arr[high] = arr[high], arr[i + 1]
    return i + 1"""

with open(os.path.join(code_path, "python", "quick-sort.py"), "w") as f:
    f.write(python_code)

print("Quick Sort lesson created")
