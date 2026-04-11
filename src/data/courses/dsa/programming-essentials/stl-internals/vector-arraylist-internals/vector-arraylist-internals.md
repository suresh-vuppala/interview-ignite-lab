## Vector (C++) / ArrayList (Java) — Dynamic Array Internals

The most-used data structure in interviews. Understanding its internals helps you reason about performance and choose the right container.

<br>

## How It Works

A vector is a **dynamic array** — a contiguous block of memory that grows automatically when full.

**Key internals:**
- **Size** — number of elements currently stored
- **Capacity** — total allocated memory slots
- **Growth factor** — when full, allocates a new block (typically **2× capacity**), copies all elements, frees old block

<br>

## Operation Complexities

| Operation | Time | Notes |
|-----------|------|-------|
| `push_back()` / `add()` | **O(1) amortized** | O(n) when reallocation triggers |
| `pop_back()` | O(1) | Size decreases, capacity unchanged |
| `operator[]` / `get(i)` | O(1) | Direct index access |
| `insert(pos, val)` | O(n) | Shifts all elements after pos |
| `erase(pos)` / `remove(i)` | O(n) | Shifts all elements after pos |
| `find` | O(n) | Linear scan (unsorted) |
| `size()` | O(1) | Stored as member |
| `clear()` | O(n) | Destroys elements, capacity may remain |

<br>

## Why O(1) Amortized for push_back?

When the vector is full (size == capacity):
1. Allocate new array of **2× capacity**
2. Copy all n elements → O(n)
3. Free old array

But this doubling happens **rarely**. Over n insertions, total copy cost is n + n/2 + n/4 + ... ≈ 2n. So **average cost per insertion = O(1)**.

<br>

## C++ Specifics

```cpp
vector<int> v;
v.reserve(1000);        // Pre-allocate capacity (avoids reallocations)
v.push_back(5);         // Add to end
v.emplace_back(5);      // Construct in-place (avoids copy)
v.shrink_to_fit();      // Release unused capacity
v.resize(10, 0);        // Set size to 10, fill new slots with 0

// 2D vector
vector<vector<int>> grid(m, vector<int>(n, 0));
```

<br>

## Java Specifics

```java
ArrayList<Integer> list = new ArrayList<>();
list.ensureCapacity(1000);  // Pre-allocate
list.add(5);                // O(1) amortized
list.get(0);                // O(1)
list.remove(0);             // O(n) — shifts elements
list.trimToSize();          // Release unused capacity
```

<br>

## Interview Tips

- **Always use `reserve()`** if you know the size — avoids reallocations
- **Prefer `emplace_back` over `push_back`** in C++ for complex objects
- **Contiguous memory** → cache-friendly → fast iteration
- **Don't use `vector<bool>`** in C++ — it's a bitfield, not a real vector

<br>
