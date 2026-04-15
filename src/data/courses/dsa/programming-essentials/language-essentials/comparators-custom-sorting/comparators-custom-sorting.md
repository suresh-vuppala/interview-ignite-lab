## Custom Sorting & Comparators — Essential for 30%+ of Interview Problems

Many interview problems require sorting by custom criteria: sort by frequency, sort by end time, sort by distance, multi-key sorting. Know how to write comparators fluently.

<br>

## C++ Custom Sorting

```cpp
// Lambda comparator (most common in interviews):
vector<pair<int,int>> intervals;
sort(intervals.begin(), intervals.end(), [](auto& a, auto& b) {
    return a.second < b.second;  // Sort by end time ascending
});

// Sort by multiple keys:
sort(v.begin(), v.end(), [](auto& a, auto& b) {
    if (a.first != b.first) return a.first < b.first;  // Primary: ascending
    return a.second > b.second;                          // Secondary: descending
});

// For priority_queue (reversed logic — greater = min-heap):
auto cmp = [](pair<int,int>& a, pair<int,int>& b) {
    return a.second > b.second;  // Min-heap by second element
};
priority_queue<pair<int,int>, vector<pair<int,int>>, decltype(cmp)> pq(cmp);
```

<br>

## Java Custom Sorting

```java
// Lambda comparator:
int[][] intervals = ...;
Arrays.sort(intervals, (a, b) -> a[1] - b[1]);  // Sort by end time

// Multi-key:
Arrays.sort(arr, (a, b) -> {
    if (a[0] != b[0]) return a[0] - b[0];   // Primary ascending
    return b[1] - a[1];                       // Secondary descending
});

// ⚠️ WARNING: (a - b) can overflow for large values!
// Safe alternative:
Arrays.sort(arr, (a, b) -> Integer.compare(a[0], b[0]));

// For PriorityQueue:
PriorityQueue<int[]> pq = new PriorityQueue<>((a, b) -> a[1] - b[1]);
```

<br>

## Python Custom Sorting

```python
# Key function (preferred):
intervals.sort(key=lambda x: x[1])     # Sort by end time
intervals.sort(key=lambda x: (-x[0], x[1]))  # Primary desc, secondary asc

# functools.cmp_to_key for complex comparisons:
from functools import cmp_to_key
nums.sort(key=cmp_to_key(lambda a, b: int(b+a) - int(a+b)))  # Largest number
```

<br>

## Common Interview Sorting Patterns

| Problem | Sort By |
|---------|---------|
| Merge Intervals | Start time ascending |
| Meeting Rooms II | Start time, then process events |
| Non-overlapping Intervals | End time ascending |
| Task Scheduler | Frequency descending |
| Custom order | Map to priority, sort by mapped value |
| Largest Number | Custom string comparison |

<br>


## All Possible Edge Cases
1. **N/A — conceptual reference**
