## Ordered Containers — Balanced BST Internals

C++ `set`/`map` and Java `TreeSet`/`TreeMap` are implemented using **self-balancing Binary Search Trees** (Red-Black Trees). They maintain elements in **sorted order** and support O(log n) operations.

<br>

## When to Use Ordered vs Unordered

| Need | Use | Time |
|------|-----|------|
| Just lookup/insert/delete | `unordered_map` / `HashMap` | O(1) avg |
| **Sorted order** iteration | `map` / `TreeMap` | O(log n) |
| **Lower bound / upper bound** | `set` / `TreeSet` | O(log n) |
| **Floor / ceiling** queries | `set` / `TreeSet` | O(log n) |
| **Range queries** [lo, hi] | `set` / `TreeSet` | O(log n + k) |
| **Min / max** element | `set` / `TreeSet` | O(log n) or O(1) |

<br>

## Operation Complexities (Red-Black Tree)

| Operation | Time | Notes |
|-----------|------|-------|
| `insert` | O(log n) | Rebalances after insert |
| `find` / `contains` | O(log n) | BST search |
| `erase` / `remove` | O(log n) | Rebalances after delete |
| `lower_bound(x)` | O(log n) | First element ≥ x |
| `upper_bound(x)` | O(log n) | First element > x |
| `begin()` / `first()` | O(1)* | Minimum element |
| `rbegin()` / `last()` | O(1)* | Maximum element |
| Iterate in order | O(n) | Inorder traversal |

<br>

## C++ `set` and `map`

```cpp
set<int> s;
s.insert(5);
s.erase(5);
auto it = s.lower_bound(3);  // Iterator to first element ≥ 3
auto it2 = s.upper_bound(3); // Iterator to first element > 3

map<string, int> m;
m["key"] = 10;
// Iterate in sorted key order:
for (auto& [key, val] : m) { /* sorted by key */ }

// multiset allows duplicates:
multiset<int> ms;
ms.insert(5); ms.insert(5); // Both stored
ms.count(5);  // Returns 2
ms.erase(ms.find(5)); // Removes ONE occurrence
```

<br>

## Java `TreeSet` and `TreeMap`

```java
TreeSet<Integer> set = new TreeSet<>();
set.add(5);
set.floor(3);    // Greatest element ≤ 3 (or null)
set.ceiling(3);  // Smallest element ≥ 3 (or null)
set.first();     // Minimum
set.last();      // Maximum
set.subSet(2, 8); // Elements in [2, 8)

TreeMap<String, Integer> map = new TreeMap<>();
map.floorKey("c");   // Greatest key ≤ "c"
map.ceilingKey("c"); // Smallest key ≥ "c"
```

<br>

## Interview Use Cases

- **Sliding window with ordered access** — Use multiset to track window elements, find median
- **Calendar / interval problems** — TreeMap for event counting (sweep line)
- **Finding next/previous element** — lower_bound / upper_bound
- **Count elements in range** — subSet or distance between iterators

<br>


## All Possible Edge Cases
1. **N/A — conceptual reference**
