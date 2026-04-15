Python provides powerful and flexible sorting capabilities with simple syntax. Understanding these is essential for interviews and competitive programming.

<br>

## Python Sort Internals

### Algorithm: TimSort

Both `sort()` and `sorted()` use **TimSort**:
- Hybrid of Merge Sort and Insertion Sort
- Stable sort (preserves order of equal elements)
- Optimized for real-world data
- Performs exceptionally well on partially sorted data

**Time Complexity:** O(n log n) guaranteed

**Space Complexity:** O(n)

**Inventor:** Tim Peters (2002)

<br>

---

## Two Main Sorting Methods

### 1. list.sort() - In-Place

Modifies the original list, returns `None`

```python
arr = [5, 2, 8, 1, 9]
arr.sort()
print(arr)  # [1, 2, 5, 8, 9]
```

**Advantages:**
- Memory efficient (in-place)
- Slightly faster

<br>

### 2. sorted() - Returns New List

Returns a new sorted list, original unchanged

```python
arr = [5, 2, 8, 1, 9]
sorted_arr = sorted(arr)
print(arr)         # [5, 2, 8, 1, 9] (unchanged)
print(sorted_arr)  # [1, 2, 5, 8, 9]
```

**Advantages:**
- Works on any iterable (list, tuple, string, dict, set)
- Preserves original data

<br>

---

## Basic Sorting

### Ascending Order (Default)

```python
arr = [5, 2, 8, 1, 9]
arr.sort()
# Result: [1, 2, 5, 8, 9]
```

<br>

### Descending Order

```python
arr = [5, 2, 8, 1, 9]
arr.sort(reverse=True)
# Result: [9, 8, 5, 2, 1]
```

<br>

### Sort Different Types

```python
# Strings (alphabetically)
words = ["banana", "apple", "cherry"]
words.sort()
# Result: ['apple', 'banana', 'cherry']

# Tuples (by first element, then second, etc.)
pairs = [(1, 5), (1, 3), (2, 4)]
pairs.sort()
# Result: [(1, 3), (1, 5), (2, 4)]
```

<br>

---

## Custom Sorting with key Parameter

### Using key Function

The `key` parameter takes a function that extracts a comparison key from each element.

**Syntax:**
```python
arr.sort(key=function)
sorted(arr, key=function)
```

<br>

### 1. Lambda Functions

**Example: Sort by absolute value**
```python
arr = [-5, 2, -8, 1, 9]
arr.sort(key=lambda x: abs(x))
# Result: [1, 2, -5, -8, 9]
```

**Example: Sort strings by length**
```python
words = ["apple", "pie", "banana", "cat"]

words.sort(key=lambda x: len(x))
# Result: ['pie', 'cat', 'apple', 'banana']
```

**With alphabetical tie-breaker:**
```python
words = ["apple", "pie", "banana", "cat", "dog"]

words.sort(key=lambda x: (len(x), x))  # Tuple: (length, word)
# Result: ['cat', 'dog', 'pie', 'apple', 'banana']
```

<br>

### 2. Built-in Functions

```python
# Sort strings case-insensitive
words = ["Apple", "banana", "Cherry"]
words.sort(key=str.lower)
# Result: ['Apple', 'banana', 'Cherry']

# Sort by absolute value
arr = [-5, 2, -8, 1, 9]
arr.sort(key=abs)
# Result: [1, 2, -5, -8, 9]
```

<br>

### 3. Operator Module

```python
from operator import itemgetter, attrgetter

# Sort list of tuples by second element
pairs = [(1, 5), (2, 3), (3, 8)]
pairs.sort(key=itemgetter(1))
# Result: [(2, 3), (1, 5), (3, 8)]

# Sort by multiple indices
pairs.sort(key=itemgetter(1, 0))  # By second, then first
```

<br>

### 4. Custom Functions

```python
def custom_key(x):
    return x % 10  # Sort by last digit

arr = [23, 45, 12, 67, 34]
arr.sort(key=custom_key)
# Result: [12, 23, 34, 45, 67]
```

<br>

---

## Problem Variations

### Variation 1: Sort by Absolute Value

```python
arr = [-5, 2, -8, 1, 9, -3]
arr.sort(key=abs)
# Result: [1, 2, -3, -5, -8, 9]
```

<br>

### Variation 2: Sort Strings by Length, Then Alphabetically

```python
words = ["apple", "pie", "banana", "cat", "dog"]
words.sort(key=lambda x: (len(x), x))
# Result: ['cat', 'dog', 'pie', 'apple', 'banana']
```

**How it works:** Returns tuple `(length, word)`, Python compares tuples element by element.

<br>

### Variation 3: Sort by Multiple Criteria

```python
students = [
    ("Alice", 85, 20),
    ("Bob", 85, 19),
    ("Charlie", 92, 20)
]

# Sort by marks (desc), then age (asc), then name (asc)
students.sort(key=lambda x: (-x[1], x[2], x[0]))
# Result: [('Charlie', 92, 20), ('Bob', 85, 19), ('Alice', 85, 20)]
```

**Trick:** Use negative for descending order in tuples.

<br>

### Variation 4: Sort Dictionary by Value

```python
scores = {"Alice": 85, "Bob": 92, "Charlie": 78}

# Sort by value
sorted_items = sorted(scores.items(), key=lambda x: x[1])
# Result: [('Charlie', 78), ('Alice', 85), ('Bob', 92)]

# Convert back to dict
sorted_dict = dict(sorted_items)
```

<br>

### Variation 5: Sort by Frequency

```python
from collections import Counter

arr = [4, 5, 6, 5, 4, 3]

# Count frequency
freq = Counter(arr)

# Sort by frequency (desc), then by value (asc)
arr.sort(key=lambda x: (-freq[x], x))
# Result: [4, 4, 5, 5, 3, 6]
```

<br>

### Variation 6: Sort 2D List by Column

```python
matrix = [
    [1, 5, 3],
    [2, 1, 4],
    [3, 8, 2]
]

# Sort by second column (index 1)
matrix.sort(key=lambda row: row[1])
# Result: [[2, 1, 4], [1, 5, 3], [3, 8, 2]]
```

<br>

### Variation 7: Sort by Distance from Origin

```python
points = [(1, 2), (3, 4), (0, 1)]

points.sort(key=lambda p: p[0]**2 + p[1]**2)
# Result: [(0, 1), (1, 2), (3, 4)]
```

<br>

### Variation 8: Sort Intervals by Start, Then by End

```python
intervals = [(1, 5), (1, 3), (2, 4)]

intervals.sort(key=lambda x: (x[0], x[1]))
# Or simply: intervals.sort() (tuples sort naturally)
# Result: [(1, 3), (1, 5), (2, 4)]
```

<br>

### Variation 9: Sort by Custom Priority

```python
# Sort: even numbers first (ascending), then odd numbers (descending)
arr = [1, 2, 3, 4, 5, 6, 7, 8]

arr.sort(key=lambda x: (x % 2, x if x % 2 == 0 else -x))
# Result: [2, 4, 6, 8, 7, 5, 3, 1]
```

**Explanation:**
- `x % 2`: 0 for even (comes first), 1 for odd
- `x if x % 2 == 0 else -x`: Even ascending, odd descending

<br>

### Variation 10: Sort Strings by Custom Order

```python
# Sort by vowel count, then alphabetically
def vowel_count(s):
    return sum(1 for c in s.lower() if c in 'aeiou')

words = ["apple", "pie", "banana", "cat"]
words.sort(key=lambda x: (vowel_count(x), x))
# Result: ['cat', 'pie', 'apple', 'banana']
```

<br>

---

## Sorting with Classes

### Using __lt__ Method

```python
class Student:
    def __init__(self, name, marks):
        self.name = name
        self.marks = marks
    
    def __lt__(self, other):
        return self.marks > other.marks  # Descending by marks
    
    def __repr__(self):
        return f"{self.name}({self.marks})"

students = [
    Student("Alice", 85),
    Student("Bob", 92),
    Student("Charlie", 78)
]

students.sort()
# Result: [Bob(92), Alice(85), Charlie(78)]
```

<br>

### Using key with attrgetter

```python
from operator import attrgetter

class Student:
    def __init__(self, name, marks):
        self.name = name
        self.marks = marks

students = [
    Student("Alice", 85),
    Student("Bob", 92),
    Student("Charlie", 78)
]

# Sort by marks
students.sort(key=attrgetter('marks'))

# Sort by multiple attributes
students.sort(key=attrgetter('marks', 'name'))
```

<br>

---

## Advanced Techniques

### 1. Stable Sort with Multiple Passes

```python
# Sort by age, then by name (stable sort preserves order)
students = [
    ("Alice", 20),
    ("Bob", 19),
    ("Charlie", 20)
]

students.sort(key=lambda x: x[0])  # First by name
students.sort(key=lambda x: x[1])  # Then by age (stable)
# Result: [('Bob', 19), ('Alice', 20), ('Charlie', 20)]
```

<br>

### 2. Reverse Individual Keys

```python
# Sort by marks (desc), then name (asc)
students = [("Alice", 85), ("Bob", 85), ("Charlie", 92)]

students.sort(key=lambda x: (-x[1], x[0]))
# Result: [('Charlie', 92), ('Alice', 85), ('Bob', 85)]
```

<br>

### 3. Custom Comparison with functools

```python
from functools import cmp_to_key

def compare(a, b):
    # Return -1 if a < b, 0 if a == b, 1 if a > b
    if a < b:
        return -1
    elif a > b:
        return 1
    return 0

arr = [5, 2, 8, 1, 9]
arr.sort(key=cmp_to_key(compare))
```

**Example: Sort by custom rule**
```python
def custom_compare(a, b):
    # Even numbers before odd, then by value
    if (a % 2 == 0) and (b % 2 != 0):
        return -1
    if (a % 2 != 0) and (b % 2 == 0):
        return 1
    return a - b

arr = [1, 2, 3, 4, 5, 6]
arr.sort(key=cmp_to_key(custom_compare))
# Result: [2, 4, 6, 1, 3, 5]
```

<br>

---

## Sorting Different Data Structures

### List

```python
arr = [5, 2, 8, 1, 9]
arr.sort()
```

<br>

### Tuple (Returns List)

```python
tup = (5, 2, 8, 1, 9)
sorted_list = sorted(tup)
# Result: [1, 2, 5, 8, 9]
```

<br>

### String (Returns List of Characters)

```python
s = "hello"
sorted_chars = sorted(s)
# Result: ['e', 'h', 'l', 'l', 'o']

# Join back to string
sorted_str = ''.join(sorted(s))
# Result: 'ehllo'
```

<br>

### Dictionary

```python
# Sort by keys
d = {3: 'c', 1: 'a', 2: 'b'}
sorted_keys = sorted(d.keys())
# Result: [1, 2, 3]

# Sort by values
sorted_items = sorted(d.items(), key=lambda x: x[1])
# Result: [(1, 'a'), (2, 'b'), (3, 'c')]
```

<br>

### Set (Returns List)

```python
s = {5, 2, 8, 1, 9}
sorted_list = sorted(s)
# Result: [1, 2, 5, 8, 9]
```

<br>

---

## Performance Tips

### 1. Use sort() Instead of sorted() for Lists

```python
# ✓ Faster: In-place
arr.sort()

# ❌ Slower: Creates new list
arr = sorted(arr)
```

<br>

### 2. Avoid Complex Calculations in key

```python
# ❌ Slow: Recalculates every comparison
points.sort(key=lambda p: (p[0]**2 + p[1]**2)**0.5)

# ✓ Fast: Avoid sqrt
points.sort(key=lambda p: p[0]**2 + p[1]**2)
```

<br>

### 3. Use Built-in Functions

```python
# ✓ Faster: Built-in function
words.sort(key=len)

# ❌ Slower: Lambda
words.sort(key=lambda x: len(x))
```

<br>

### 4. Precompute Values for Large Lists

```python
# For large lists with expensive key calculations
decorated = [(key_func(item), item) for item in arr]
decorated.sort()
result = [item for key, item in decorated]
```

<br>

---

## Common Patterns Summary

| Pattern | Code |
|---------|------|
| Ascending | `arr.sort()` |
| Descending | `arr.sort(reverse=True)` |
| By absolute value | `arr.sort(key=abs)` |
| By length | `arr.sort(key=len)` |
| By second element | `arr.sort(key=lambda x: x[1])` |
| Multiple criteria | `arr.sort(key=lambda x: (x[0], -x[1]))` |
| Case-insensitive | `arr.sort(key=str.lower)` |
| By frequency | `arr.sort(key=lambda x: freq[x])` |

<br>

---

## Comparison: sort() vs sorted()

| Feature | list.sort() | sorted() |
|---------|-------------|----------|
| Returns | None | New list |
| Modifies original | Yes | No |
| Works on | Lists only | Any iterable |
| Memory | O(1) extra | O(n) extra |
| Speed | Slightly faster | Slightly slower |
| Use case | When you don't need original | When you need original |

<br>

---

## Key Takeaways

1. **TimSort** is stable and optimized for real-world data
2. Use `key` parameter for custom sorting (not `cmp`)
3. Return tuples from `key` for multiple criteria
4. Use negative values for descending in tuples: `(-x[1], x[0])`
5. `sort()` is in-place, `sorted()` returns new list
6. Python's sort is stable (preserves order of equal elements)
7. Avoid complex calculations in `key` function

<br>
<br>

---

```code```
