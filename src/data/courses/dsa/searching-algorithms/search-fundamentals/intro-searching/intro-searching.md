
Searching is the process of finding a specific value (key) in a collection of data. Efficient searching is fundamental to computer science and forms the basis for many advanced algorithms.

## Types of Searching

### 1. Linear Search
- Scans elements sequentially from start to end
- Works on any array (sorted or unsorted)
- Time Complexity: **O(n)**

### 2. Binary Search
- Works only on sorted arrays
- Divides the search space in half each iteration
- Time Complexity: **O(log n)**

## Key Concepts

**When to Use Linear Search:**
- Array is unsorted
- Array is very small
- Need to find all occurrences

**When to Use Binary Search:**
- Array is sorted
- Large dataset
- Need to find a single element or boundary

## Terminology

- **Target**: The value we are searching for
- **Key**: An attribute used to compare elements
- **Search Space**: The range of indices we're examining

## Real-World Applications

- Finding a name in a phonebook (sorted, binary search)
- Looking up a student ID in a database
- Auto-complete suggestions
- Search engines indexing
