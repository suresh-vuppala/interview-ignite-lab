## STL Algorithms & Built-ins — Don't Reinvent the Wheel

Knowing these saves you 5-10 minutes per interview problem. Interviewers expect fluency with standard library functions.

<br>

## C++ STL Algorithms (must-know)

```cpp
#include <algorithm>
#include <numeric>

// Sorting
sort(v.begin(), v.end());                    // Ascending
sort(v.begin(), v.end(), greater<int>());    // Descending
stable_sort(v.begin(), v.end());             // Preserves relative order

// Searching (on sorted data)
binary_search(v.begin(), v.end(), target);   // Returns bool
lower_bound(v.begin(), v.end(), target);     // Iterator to first ≥ target
upper_bound(v.begin(), v.end(), target);     // Iterator to first > target

// Min/Max
*min_element(v.begin(), v.end());
*max_element(v.begin(), v.end());
auto [mn, mx] = minmax_element(v.begin(), v.end()); // C++17

// Accumulate
int sum = accumulate(v.begin(), v.end(), 0);
long long sum = accumulate(v.begin(), v.end(), 0LL); // Avoid overflow!

// Reverse, Rotate, Unique
reverse(v.begin(), v.end());
rotate(v.begin(), v.begin() + k, v.end());  // Left rotate by k
auto it = unique(v.begin(), v.end());        // Remove consecutive dupes
v.erase(it, v.end());                        // Shrink to actual size

// Fill, Iota
fill(v.begin(), v.end(), 0);                 // Set all to 0
iota(v.begin(), v.end(), 1);                 // Fill with 1, 2, 3, ...

// Next Permutation
next_permutation(v.begin(), v.end());        // Modifies in-place, returns bool

// Count
int cnt = count(v.begin(), v.end(), target);
```

<br>

## Java Equivalents

```java
Arrays.sort(arr);                                    // Sort array
Collections.sort(list);                              // Sort list
Collections.reverse(list);                           // Reverse
Arrays.fill(arr, 0);                                 // Fill
Arrays.binarySearch(arr, target);                    // Binary search (sorted)
Collections.frequency(list, element);                // Count occurrences
Arrays.stream(arr).sum();                            // Sum
Arrays.stream(arr).max().getAsInt();                 // Max
```

<br>

## Python Equivalents

```python
sorted(arr)                          # Returns new sorted list
arr.sort()                           # In-place sort
arr.sort(reverse=True)               # Descending
bisect_left(arr, target)             # Lower bound (import bisect)
bisect_right(arr, target)            # Upper bound
sum(arr)                             # Sum
min(arr), max(arr)                   # Min, Max
arr.count(target)                    # Count occurrences
list(set(arr))                       # Remove duplicates (unordered)
collections.Counter(arr)             # Frequency map
```

<br>

## Complexity Cheat Sheet

| Function | Time |
|----------|------|
| `sort` | O(n log n) |
| `binary_search` / `lower_bound` | O(log n) |
| `min_element` / `max_element` | O(n) |
| `accumulate` / `sum` | O(n) |
| `reverse` | O(n) |
| `unique` | O(n) |
| `next_permutation` | O(n) |
| `count` | O(n) |

<br>
