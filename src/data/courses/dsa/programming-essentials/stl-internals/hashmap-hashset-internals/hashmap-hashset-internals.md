## HashMap & HashSet — Hash Table Internals

The hash map is arguably the **most important data structure for interviews**. Understanding how it works internally helps you reason about when O(1) breaks down and why.

<br>

## How a Hash Table Works

1. **Hash function** maps key → integer (hash code)
2. **Bucket index** = hash code % number_of_buckets
3. Store key-value pair in that bucket
4. **Collision** = two keys map to the same bucket

<br>

## Collision Resolution

| Method | How | Used By |
|--------|-----|---------|
| **Separate Chaining** | Each bucket is a linked list (or tree for long chains) | Java HashMap, C++ unordered_map |
| **Open Addressing** | Probe to next empty slot (linear/quadratic/double hashing) | Python dict, some custom implementations |

<br>

## Operation Complexities

| Operation | Average | Worst Case | Notes |
|-----------|---------|------------|-------|
| `insert` / `put` | **O(1)** | O(n) | Worst when all keys hash to same bucket |
| `find` / `get` | **O(1)** | O(n) | Same worst case |
| `erase` / `remove` | **O(1)** | O(n) | Same worst case |
| `size` | O(1) | O(1) | Stored |

<br>

## Load Factor & Rehashing

- **Load factor** = size / number_of_buckets
- When load factor exceeds threshold (default **0.75** in Java, **1.0** in C++):
  - Allocate **2× buckets**
  - **Rehash all elements** → O(n) one-time cost
- This keeps the average chain length short → O(1) average

<br>

## C++ `unordered_map` / `unordered_set`

```cpp
unordered_map<string, int> mp;
mp["hello"] = 1;               // Insert/update
mp.count("hello");             // 0 or 1 (existence check)
mp.find("hello") != mp.end(); // Existence check
mp.erase("hello");            // Remove

// Custom hash for pair<int,int>:
struct PairHash {
    size_t operator()(const pair<int,int>& p) const {
        return hash<int>()(p.first) ^ (hash<int>()(p.second) << 32);
    }
};
unordered_set<pair<int,int>, PairHash> visited;
```

<br>

## Java `HashMap` / `HashSet`

```java
HashMap<String, Integer> map = new HashMap<>();
map.put("hello", 1);
map.getOrDefault("world", 0);  // Returns 0 if absent
map.containsKey("hello");

// Java 8+: HashMap converts long chains to Red-Black Trees
// When a bucket has > 8 entries → tree (O(log n) worst case)
```

<br>

## When NOT to Use Hash Maps

- Need **ordered iteration** → Use TreeMap / map (BST-based)
- Need **min/max** efficiently → Use heap or BST
- Keys are **small integers** → Use array (faster, less overhead)
- **Worst case matters** → Hash map O(n) worst vs BST O(log n) guaranteed

<br>

---

```code```
