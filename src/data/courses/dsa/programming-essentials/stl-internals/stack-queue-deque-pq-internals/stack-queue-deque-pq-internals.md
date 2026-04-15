## Container Adapters & Priority Queue — Know What's Under the Hood

These are built on top of other containers. Knowing the underlying structure helps you choose the right one.

<br>

## Stack

| | C++ `stack` | Java `Stack` / `Deque` |
|---|---|---|
| Underlying | `deque` (default) | `ArrayDeque` (recommended) |
| Push/Pop | O(1) | O(1) |
| Top/Peek | O(1) | O(1) |
| Note | Can use `stack<int, vector<int>>` for vector-based | Don't use `Stack` class — use `Deque` interface |

<br>

## Queue

| | C++ `queue` | Java `Queue` |
|---|---|---|
| Underlying | `deque` (default) | `LinkedList` or `ArrayDeque` |
| Enqueue | O(1) | O(1) |
| Dequeue | O(1) | O(1) |
| Note | `queue<int, list<int>>` for list-based | `ArrayDeque` is faster than `LinkedList` |

<br>

## Deque (Double-Ended Queue)

| | C++ `deque` | Java `ArrayDeque` |
|---|---|---|
| Structure | Array of fixed-size blocks | Circular resizable array |
| Push front/back | O(1) amortized | O(1) amortized |
| Pop front/back | O(1) | O(1) |
| Random access `[i]` | O(1) | Not supported |
| Use case | Sliding window, BFS | Sliding window, BFS |

<br>

## Priority Queue (Binary Heap)

| | C++ `priority_queue` | Java `PriorityQueue` |
|---|---|---|
| Default | **Max-heap** | **Min-heap** |
| Insert (`push`/`offer`) | O(log n) | O(log n) |
| Extract top (`pop`/`poll`) | O(log n) | O(log n) |
| Peek (`top`/`peek`) | O(1) | O(1) |
| Build from array | O(n) | O(n) |
| Find arbitrary element | O(n) ❌ | O(n) ❌ |

```cpp
// C++ min-heap:
priority_queue<int, vector<int>, greater<int>> minHeap;

// C++ max-heap (default):
priority_queue<int> maxHeap;

// Custom comparator:
auto cmp = [](pair<int,int>& a, pair<int,int>& b) { return a.second > b.second; };
priority_queue<pair<int,int>, vector<pair<int,int>>, decltype(cmp)> pq(cmp);
```

```java
// Java min-heap (default):
PriorityQueue<Integer> minHeap = new PriorityQueue<>();

// Java max-heap:
PriorityQueue<Integer> maxHeap = new PriorityQueue<>(Collections.reverseOrder());

// Custom comparator:
PriorityQueue<int[]> pq = new PriorityQueue<>((a, b) -> a[1] - b[1]);
```

<br>


## All Possible Edge Cases
1. **N/A — conceptual reference**
