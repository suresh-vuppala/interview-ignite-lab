import os
import json

lessons = [
    {
        "slug": "kth-smallest-element",
        "title": "Kth Smallest Element",
        "md": """## Problem Statement

Find the kth smallest element in an unsorted array using QuickSelect algorithm.

## Approach

Use QuickSelect (partition-based selection):
1. Partition array around pivot
2. If pivot index == k-1, return pivot
3. Recurse on left or right based on k

## Complexity

- Time: O(n) average, O(n²) worst
- Space: O(1)

## Code

```code```""",
        "java": """class KthSmallestElement {
    public int findKthSmallest(int[] arr, int k) {
        return quickSelect(arr, 0, arr.length - 1, k - 1);
    }
    
    private int quickSelect(int[] arr, int low, int high, int k) {
        int pi = partition(arr, low, high);
        if (pi == k) return arr[pi];
        if (pi > k) return quickSelect(arr, low, pi - 1, k);
        return quickSelect(arr, pi + 1, high, k);
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
}""",
        "cpp": """class KthSmallestElement {
public:
    int findKthSmallest(vector<int>& arr, int k) {
        return quickSelect(arr, 0, arr.size() - 1, k - 1);
    }
    
private:
    int quickSelect(vector<int>& arr, int low, int high, int k) {
        int pi = partition(arr, low, high);
        if (pi == k) return arr[pi];
        if (pi > k) return quickSelect(arr, low, pi - 1, k);
        return quickSelect(arr, pi + 1, high, k);
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
};""",
        "python": """def find_kth_smallest(arr, k):
    return quick_select(arr, 0, len(arr) - 1, k - 1)

def quick_select(arr, low, high, k):
    pi = partition(arr, low, high)
    if pi == k:
        return arr[pi]
    if pi > k:
        return quick_select(arr, low, pi - 1, k)
    return quick_select(arr, pi + 1, high, k)

def partition(arr, low, high):
    pivot = arr[high]
    i = low - 1
    for j in range(low, high):
        if arr[j] < pivot:
            i += 1
            arr[i], arr[j] = arr[j], arr[i]
    arr[i + 1], arr[high] = arr[high], arr[i + 1]
    return i + 1"""
    },
    {
        "slug": "kth-largest-element",
        "title": "Kth Largest Element",
        "md": """## Problem Statement

Find the kth largest element in an unsorted array using QuickSelect algorithm.

## Approach

Use QuickSelect with modified partition:
1. Partition array around pivot
2. If pivot index == n-k, return pivot
3. Recurse on left or right based on position

## Complexity

- Time: O(n) average, O(n²) worst
- Space: O(1)

## Code

```code```""",
        "java": """class KthLargestElement {
    public int findKthLargest(int[] arr, int k) {
        return quickSelect(arr, 0, arr.length - 1, arr.length - k);
    }
    
    private int quickSelect(int[] arr, int low, int high, int k) {
        int pi = partition(arr, low, high);
        if (pi == k) return arr[pi];
        if (pi > k) return quickSelect(arr, low, pi - 1, k);
        return quickSelect(arr, pi + 1, high, k);
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
}""",
        "cpp": """class KthLargestElement {
public:
    int findKthLargest(vector<int>& arr, int k) {
        return quickSelect(arr, 0, arr.size() - 1, arr.size() - k);
    }
    
private:
    int quickSelect(vector<int>& arr, int low, int high, int k) {
        int pi = partition(arr, low, high);
        if (pi == k) return arr[pi];
        if (pi > k) return quickSelect(arr, low, pi - 1, k);
        return quickSelect(arr, pi + 1, high, k);
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
};""",
        "python": """def find_kth_largest(arr, k):
    return quick_select(arr, 0, len(arr) - 1, len(arr) - k)

def quick_select(arr, low, high, k):
    pi = partition(arr, low, high)
    if pi == k:
        return arr[pi]
    if pi > k:
        return quick_select(arr, low, pi - 1, k)
    return quick_select(arr, pi + 1, high, k)

def partition(arr, low, high):
    pivot = arr[high]
    i = low - 1
    for j in range(low, high):
        if arr[j] < pivot:
            i += 1
            arr[i], arr[j] = arr[j], arr[i]
    arr[i + 1], arr[high] = arr[high], arr[i + 1]
    return i + 1"""
    }
]

base_path = "src/data/courses/dsa/sorting/quick-sort"

for lesson in lessons:
    lesson_path = os.path.join(base_path, lesson["slug"])
    code_path = os.path.join(lesson_path, "code")
    
    os.makedirs(os.path.join(code_path, "java"), exist_ok=True)
    os.makedirs(os.path.join(code_path, "cpp"), exist_ok=True)
    os.makedirs(os.path.join(code_path, "python"), exist_ok=True)
    
    with open(os.path.join(lesson_path, f"{lesson['slug']}.md"), "w", encoding="utf-8") as f:
        f.write(lesson["md"])
    
    json_content = {
        "title": lesson["title"],
        "description": lesson["title"],
        "difficulty": "medium",
        "isPremium": False,
        "isPosted": True
    }
    with open(os.path.join(lesson_path, f"{lesson['slug']}.json"), "w", encoding="utf-8") as f:
        json.dump(json_content, f, indent=4)
    
    class_name = ''.join(word.capitalize() for word in lesson['slug'].split('-'))
    
    with open(os.path.join(code_path, "java", f"{class_name}.java"), "w") as f:
        f.write(lesson["java"])
    
    with open(os.path.join(code_path, "cpp", f"{class_name}.cpp"), "w") as f:
        f.write(lesson["cpp"])
    
    with open(os.path.join(code_path, "python", f"{lesson['slug']}.py"), "w") as f:
        f.write(lesson["python"])
    
    print(f"Created: {lesson['title']}")

print("\nAll Kth element lessons created successfully!")
