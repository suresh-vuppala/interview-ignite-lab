C++ provides powerful sorting functions with customizable comparators. Understanding how to use them effectively is crucial for competitive programming and interviews.

<br>

## C++ Sort Function Internals

### Algorithm Used

**std::sort** uses **Introsort** (Introspective Sort):
- Starts with **Quick Sort**
- Switches to **Heap Sort** if recursion depth exceeds log(n)
- Uses **Insertion Sort** for small subarrays (< 16 elements)

**Time Complexity:** O(n log n) guaranteed

**Space Complexity:** O(log n) for recursion stack

<br>

### Basic Usage

```cpp
#include <algorithm>
#include <vector>
using namespace std;

int main() {
    vector<int> arr = {5, 2, 8, 1, 9};
    
    // Sort in ascending order
    sort(arr.begin(), arr.end());
    // Result: [1, 2, 5, 8, 9]
    
    // Sort in descending order
    sort(arr.begin(), arr.end(), greater<int>());
    // Result: [9, 8, 5, 2, 1]
    
    return 0;
}
```

<br>

---

## Comparator Functions

### 1. Inline Lambda Comparator

**Syntax:**
```cpp
sort(arr.begin(), arr.end(), [](type a, type b) {
    return /* condition */;
});
```

**Example: Sort by absolute value**
```cpp
vector<int> arr = {-5, 2, -8, 1, 9};

sort(arr.begin(), arr.end(), [](int a, int b) {
    return abs(a) < abs(b);
});
// Result: [1, 2, -5, -8, 9]
```

**Example: Sort strings by length**
```cpp
vector<string> words = {"apple", "pie", "banana", "cat"};

sort(words.begin(), words.end(), [](string a, string b) {
    return a.length() < b.length();
});
// Result: ["pie", "cat", "apple", "banana"]
```

<br>

### 2. Separate Comparator Function

**Syntax:**
```cpp
bool comparator(type a, type b) {
    return /* condition */;
}

sort(arr.begin(), arr.end(), comparator);
```

**Example: Sort pairs by second element**
```cpp
bool compareBySecond(pair<int, int> a, pair<int, int> b) {
    return a.second < b.second;
}

int main() {
    vector<pair<int, int>> pairs = {{1, 5}, {2, 3}, {3, 8}};
    
    sort(pairs.begin(), pairs.end(), compareBySecond);
    // Result: [{2,3}, {1,5}, {3,8}]
    
    return 0;
}
```

<br>

### 3. Struct/Class with Operator Overloading

**Syntax:**
```cpp
struct Item {
    int value;
    
    bool operator<(const Item& other) const {
        return value < other.value;
    }
};
```

**Example: Custom Student class**
```cpp
struct Student {
    string name;
    int marks;
    
    bool operator<(const Student& other) const {
        return marks > other.marks;  // Sort by marks descending
    }
};

int main() {
    vector<Student> students = {
        {"Alice", 85},
        {"Bob", 92},
        {"Charlie", 78}
    };
    
    sort(students.begin(), students.end());
    // Result: Bob(92), Alice(85), Charlie(78)
    
    return 0;
}
```

<br>

### 4. Functor (Function Object)

**Syntax:**
```cpp
struct Comparator {
    bool operator()(type a, type b) const {
        return /* condition */;
    }
};

sort(arr.begin(), arr.end(), Comparator());
```

**Example: Sort by multiple criteria**
```cpp
struct CompareStudent {
    bool operator()(const Student& a, const Student& b) const {
        if (a.marks != b.marks)
            return a.marks > b.marks;  // Higher marks first
        return a.name < b.name;        // Then alphabetically
    }
};

int main() {
    vector<Student> students = {
        {"Alice", 85},
        {"Bob", 85},
        {"Charlie", 92}
    };
    
    sort(students.begin(), students.end(), CompareStudent());
    // Result: Charlie(92), Alice(85), Bob(85)
    
    return 0;
}
```

<br>

---

## Comparator Return Value Rules

### Critical Rule

**Return `true` if `a` should come BEFORE `b` in sorted order**

```cpp
// Ascending order
return a < b;  // a comes before b if a is smaller

// Descending order
return a > b;  // a comes before b if a is larger
```

<br>

### Common Mistakes

```cpp
// ❌ Wrong: Returns true when equal
bool badComparator(int a, int b) {
    return a <= b;  // Undefined behavior!
}

// ✓ Correct: Strict weak ordering
bool goodComparator(int a, int b) {
    return a < b;
}
```

**Rule:** Never use `<=` or `>=` in comparators. Always use `<` or `>`.

<br>

---

## Problem Variations

### Variation 1: Sort by Absolute Value

```cpp
vector<int> arr = {-5, 2, -8, 1, 9, -3};

sort(arr.begin(), arr.end(), [](int a, int b) {
    return abs(a) < abs(b);
});
// Result: [1, 2, -3, -5, -8, 9]
```

<br>

### Variation 2: Sort Strings by Length, Then Alphabetically

```cpp
vector<string> words = {"apple", "pie", "banana", "cat", "dog"};

sort(words.begin(), words.end(), [](string a, string b) {
    if (a.length() != b.length())
        return a.length() < b.length();
    return a < b;  // Alphabetically if same length
});
// Result: ["cat", "dog", "pie", "apple", "banana"]
```

<br>

### Variation 3: Sort Pairs by Sum

```cpp
vector<pair<int, int>> pairs = {{1, 5}, {2, 3}, {3, 8}};

sort(pairs.begin(), pairs.end(), [](pair<int, int> a, pair<int, int> b) {
    return (a.first + a.second) < (b.first + b.second);
});
// Result: [{2,3}(sum=5), {1,5}(sum=6), {3,8}(sum=11)]
```

<br>

### Variation 4: Sort by Frequency

```cpp
vector<int> arr = {4, 5, 6, 5, 4, 3};

// Count frequency
map<int, int> freq;
for (int x : arr) freq[x]++;

// Sort by frequency (descending), then by value (ascending)
sort(arr.begin(), arr.end(), [&freq](int a, int b) {
    if (freq[a] != freq[b])
        return freq[a] > freq[b];  // Higher frequency first
    return a < b;                   // Smaller value first
});
// Result: [4, 4, 5, 5, 3, 6]
```

<br>

### Variation 5: Sort 2D Vector by Column

```cpp
vector<vector<int>> matrix = {
    {1, 5, 3},
    {2, 1, 4},
    {3, 8, 2}
};

// Sort by second column (index 1)
sort(matrix.begin(), matrix.end(), [](vector<int>& a, vector<int>& b) {
    return a[1] < b[1];
});
// Result: [[2,1,4], [1,5,3], [3,8,2]]
```

<br>

### Variation 6: Sort by Distance from Origin

```cpp
struct Point {
    int x, y;
};

vector<Point> points = {{1, 2}, {3, 4}, {0, 1}};

sort(points.begin(), points.end(), [](Point a, Point b) {
    int distA = a.x * a.x + a.y * a.y;
    int distB = b.x * b.x + b.y * b.y;
    return distA < distB;
});
// Result: [{0,1}(dist=1), {1,2}(dist=5), {3,4}(dist=25)]
```

<br>

### Variation 7: Sort Intervals by Start, Then by End

```cpp
vector<pair<int, int>> intervals = {{1, 5}, {1, 3}, {2, 4}};

sort(intervals.begin(), intervals.end(), [](pair<int, int> a, pair<int, int> b) {
    if (a.first != b.first)
        return a.first < b.first;  // Sort by start
    return a.second < b.second;    // Then by end
});
// Result: [{1,3}, {1,5}, {2,4}]
```

<br>

### Variation 8: Sort by Custom Priority

```cpp
// Sort: even numbers first (ascending), then odd numbers (descending)
vector<int> arr = {1, 2, 3, 4, 5, 6, 7, 8};

sort(arr.begin(), arr.end(), [](int a, int b) {
    bool aEven = (a % 2 == 0);
    bool bEven = (b % 2 == 0);
    
    if (aEven && !bEven) return true;   // Even before odd
    if (!aEven && bEven) return false;  // Odd after even
    
    if (aEven) return a < b;   // Even: ascending
    return a > b;              // Odd: descending
});
// Result: [2, 4, 6, 8, 7, 5, 3, 1]
```

<br>

---

## Stable Sort

**std::stable_sort** maintains relative order of equal elements.

```cpp
struct Student {
    string name;
    int marks;
};

vector<Student> students = {
    {"Alice", 85},
    {"Bob", 90},
    {"Charlie", 85},
    {"David", 90}
};

// Sort by marks (stable)
stable_sort(students.begin(), students.end(), [](Student a, Student b) {
    return a.marks < b.marks;
});
// Result: Alice(85), Charlie(85), Bob(90), David(90)
// Alice comes before Charlie (original order preserved)
```

**Difference:**
- `sort`: May change relative order of equal elements
- `stable_sort`: Preserves relative order of equal elements

**Time Complexity:** O(n log² n) worst case, O(n log n) if enough memory

<br>

---

## Partial Sort

**std::partial_sort** sorts only the first K elements.

```cpp
vector<int> arr = {5, 2, 8, 1, 9, 3, 7};

// Sort only first 3 elements
partial_sort(arr.begin(), arr.begin() + 3, arr.end());
// Result: [1, 2, 3, ?, ?, ?, ?] (rest are unsorted)
```

**Use Case:** Finding top K elements

**Time Complexity:** O(n log k)

<br>

---

## Nth Element

**std::nth_element** partitions array so nth element is in correct position.

```cpp
vector<int> arr = {5, 2, 8, 1, 9, 3, 7};

// Find 3rd smallest element (index 2)
nth_element(arr.begin(), arr.begin() + 2, arr.end());
// arr[2] = 3 (3rd smallest)
// Elements before arr[2] are smaller
// Elements after arr[2] are larger
```

**Use Case:** Finding median, kth smallest/largest

**Time Complexity:** O(n) average

<br>

---

## Sorting Different Containers

### Array

```cpp
int arr[] = {5, 2, 8, 1, 9};
int n = 5;

sort(arr, arr + n);
```

<br>

### Vector

```cpp
vector<int> vec = {5, 2, 8, 1, 9};

sort(vec.begin(), vec.end());
```

<br>

### Deque

```cpp
deque<int> dq = {5, 2, 8, 1, 9};

sort(dq.begin(), dq.end());
```

<br>

### String

```cpp
string s = "hello";

sort(s.begin(), s.end());
// Result: "ehllo"
```

<br>

---

## Performance Tips

### 1. Use References in Lambda

```cpp
// ❌ Slow: Copies strings
sort(words.begin(), words.end(), [](string a, string b) {
    return a.length() < b.length();
});

// ✓ Fast: Uses references
sort(words.begin(), words.end(), [](const string& a, const string& b) {
    return a.length() < b.length();
});
```

<br>

### 2. Avoid Complex Calculations in Comparator

```cpp
// ❌ Slow: Recalculates distance every comparison
sort(points.begin(), points.end(), [](Point a, Point b) {
    return sqrt(a.x*a.x + a.y*a.y) < sqrt(b.x*b.x + b.y*b.y);
});

// ✓ Fast: Avoid sqrt, compare squared distances
sort(points.begin(), points.end(), [](Point a, Point b) {
    return (a.x*a.x + a.y*a.y) < (b.x*b.x + b.y*b.y);
});
```

<br>

### 3. Precompute Values

```cpp
// ❌ Slow: Recalculates sum every comparison
sort(pairs.begin(), pairs.end(), [](pair<int,int> a, pair<int,int> b) {
    return (a.first + a.second) < (b.first + b.second);
});

// ✓ Fast: Precompute sums
vector<pair<int, pair<int,int>>> temp;
for (auto p : pairs) {
    temp.push_back({p.first + p.second, p});
}
sort(temp.begin(), temp.end());
```

<br>

---

## Common Patterns Summary

| Pattern | Comparator |
|---------|------------|
| Ascending | `return a < b;` |
| Descending | `return a > b;` |
| By absolute value | `return abs(a) < abs(b);` |
| By length | `return a.length() < b.length();` |
| By second element | `return a.second < b.second;` |
| By sum | `return (a.first+a.second) < (b.first+b.second);` |
| Multiple criteria | `if (a.x != b.x) return a.x < b.x; return a.y < b.y;` |

<br>
<br>

---

```code```
