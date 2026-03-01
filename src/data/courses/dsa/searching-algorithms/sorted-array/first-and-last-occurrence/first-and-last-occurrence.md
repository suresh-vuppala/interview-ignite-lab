def search_range(nums: List[int], target: int) -> List[int]:

Find the first and last position of a given target value in a sorted integer array.
If the target does not exist in the array, return `[-1, -1]`.

> **Input:**
>
> nums = [5,7,7,8,8,10]
> target = 8
>



> **Output:**
> 
> [3, 4]
> 

> **Explanation:**
> The value `8` first appears at index `3` and last appears at index `4`.

<br>

---

## Approach

Because the array is already sorted, we can use **binary search** to locate the boundaries
in logarithmic time. We perform two modified binary searches:

1. **First occurrence** – when we see the target we record the index and continue
   searching the left half to look for an earlier appearance.
2. **Last occurrence** – when we see the target we record the index and continue
   searching the right half to look for a later appearance.

Both searches require _O(log n)_ time and constant extra space.

<br>

---

### C++ Code
```code```
#include <vector>
using namespace std;

int FindFirstOccurrence(const vector<int>& arr, int target) {
    int low = 0, high = arr.size() - 1;
    int boundaryIndex = -1;
    # First and Last Occurrence

    Given a **sorted array of integers** and a target value, return the
    indices of the first and last occurrence of the target in the array. If
    the target is not present, return `[-1, -1]`.

    <br>

    > **Input:**
    > ```text
    > nums = [5,7,7,8,8,10]
    > target = 8
    > ```

    > **Output:**
    > ```text
    > [3, 4]
    > ```

    > **Explanation:** the target `8` first appears at index `3` and last at
    > index `4`.

    <br>

    ---

    ## Solution #1: Binary-search boundaries

    We take advantage of the sorted order by running two binary searches. One
    locates the first occurrence (move left on match) and the other locates
    the last occurrence (move right on match). Each pass is **O(log n)**,
    so overall runtime is O(log n).

    ```code```

    ### C++
    ```cpp
    #include <vector>
    using namespace std;

    int FindFirstOccurrence(const vector<int>& arr, int target) {
        int low = 0, high = arr.size() - 1;
        int boundaryIndex = -1;
        while (low <= high) {
            int mid = low + (high - low) / 2;
            if (arr[mid] == target) {
                boundaryIndex = mid;
                high = mid - 1; // search left side
            } else if (arr[mid] < target) {
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }
        return boundaryIndex;
    }

    int FindLastOccurrence(const vector<int>& arr, int target) {
        int low = 0, high = arr.size() - 1;
        int boundaryIndex = -1;
        while (low <= high) {
            int mid = low + (high - low) / 2;
            if (arr[mid] == target) {
                boundaryIndex = mid;
                low = mid + 1; // search right side
            } else if (arr[mid] < target) {
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }
        return boundaryIndex;
    }

    vector<int> SearchRange(vector<int>& nums, int target) {
        return {FindFirstOccurrence(nums, target),
                FindLastOccurrence(nums, target)};
    }
    ```

    ### Java
    ```java
    public class Solution {
        public int findFirstOccurrence(int[] arr, int target) {
            int low = 0, high = arr.length - 1;
            int boundaryIndex = -1;
            while (low <= high) {
                int mid = low + (high - low) / 2;
                if (arr[mid] == target) {
                    boundaryIndex = mid;
                    high = mid - 1;
                } else if (arr[mid] < target) {
                    low = mid + 1;
                } else {
                    high = mid - 1;
                }
            }
            return boundaryIndex;
        }

        public int findLastOccurrence(int[] arr, int target) {
            int low = 0, high = arr.length - 1;
            int boundaryIndex = -1;
            while (low <= high) {
                int mid = low + (high - low) / 2;
                if (arr[mid] == target) {
                    boundaryIndex = mid;
                    low = mid + 1;
                } else if (arr[mid] < target) {
                    low = mid + 1;
                } else {
                    high = mid - 1;
                }
            }
            return boundaryIndex;
        }

        public int[] searchRange(int[] nums, int target) {
            return new int[] {findFirstOccurrence(nums, target),
                              findLastOccurrence(nums, target)};
        }
    }
    ```

    ### Python
    ```python
    from typing import List

    def find_first_occurrence(arr: List[int], target: int) -> int:
        low, high = 0, len(arr) - 1
        boundary_index = -1
        while low <= high:
            mid = (low + high) // 2
            if arr[mid] == target:
                boundary_index = mid
                high = mid - 1
            elif arr[mid] < target:
                low = mid + 1
            else:
                high = mid - 1
        return boundary_index


    def find_last_occurrence(arr: List[int], target: int) -> int:
        low, high = 0, len(arr) - 1
        boundary_index = -1
        while low <= high:
            mid = (low + high) // 2
            if arr[mid] == target:
                boundary_index = mid
                low = mid + 1
            elif arr[mid] < target:
                low = mid + 1
            else:
                high = mid - 1
        return boundary_index


    def search_range(nums: List[int], target: int) -> List[int]:
        return [find_first_occurrence(nums, target),
                find_last_occurrence(nums, target)]
    ```

    <br>

    ---

    **Time Complexity:** O(log n)  
    **Space Complexity:** O(1)


