Java provides multiple sorting methods with flexible comparator options. Understanding these is essential for interviews and competitive programming.

<br>

## Java Sort Internals

### Arrays.sort() for Primitives

**Algorithm:** **Dual-Pivot Quick Sort** (Java 7+)
- Faster than traditional Quick Sort
- Uses two pivots instead of one
- Falls back to Insertion Sort for small arrays

**Time Complexity:** O(n log n) average, O(n²) worst case

**Space Complexity:** O(log n)

```java
int[] arr = {5, 2, 8, 1, 9};
Arrays.sort(arr);
// Result: [1, 2, 5, 8, 9]
```

<br>

### Arrays.sort() for Objects

**Algorithm:** **TimSort** (modified Merge Sort)
- Stable sort
- Optimized for real-world data
- Performs well on partially sorted data

**Time Complexity:** O(n log n) guaranteed

**Space Complexity:** O(n)

```java
Integer[] arr = {5, 2, 8, 1, 9};
Arrays.sort(arr);
// Result: [1, 2, 5, 8, 9]
```

<br>

### Collections.sort()

**Algorithm:** **TimSort**

```java
List<Integer> list = new ArrayList<>(Arrays.asList(5, 2, 8, 1, 9));
Collections.sort(list);
// Result: [1, 2, 5, 8, 9]
```

<br>

---

## Comparator Methods

### 1. Lambda Expression (Java 8+)

**Syntax:**
```java
Arrays.sort(arr, (a, b) -> /* comparison */);
```

**Example: Sort by absolute value**
```java
Integer[] arr = {-5, 2, -8, 1, 9};

Arrays.sort(arr, (a, b) -> Math.abs(a) - Math.abs(b));
// Result: [1, 2, -5, -8, 9]
```

**Example: Sort strings by length**
```java
String[] words = {"apple", "pie", "banana", "cat"};

Arrays.sort(words, (a, b) -> a.length() - b.length());
// Result: ["pie", "cat", "apple", "banana"]
```

<br>

### 2. Comparator.comparing() (Java 8+)

**Syntax:**
```java
Arrays.sort(arr, Comparator.comparing(keyExtractor));
```

**Example: Sort by length**
```java
String[] words = {"apple", "pie", "banana", "cat"};

Arrays.sort(words, Comparator.comparing(String::length));
// Result: ["pie", "cat", "apple", "banana"]
```

**Example: Reverse order**
```java
Arrays.sort(words, Comparator.comparing(String::length).reversed());
// Result: ["banana", "apple", "pie", "cat"]
```

<br>

### 3. Separate Comparator Class

**Syntax:**
```java
class MyComparator implements Comparator<Type> {
    @Override
    public int compare(Type a, Type b) {
        return /* comparison */;
    }
}

Arrays.sort(arr, new MyComparator());
```

**Example: Sort pairs by second element**
```java
class PairComparator implements Comparator<int[]> {
    @Override
    public int compare(int[] a, int[] b) {
        return a[1] - b[1];
    }
}

int[][] pairs = {{1, 5}, {2, 3}, {3, 8}};
Arrays.sort(pairs, new PairComparator());
// Result: [[2,3], [1,5], [3,8]]
```

<br>

### 4. Anonymous Inner Class

**Syntax:**
```java
Arrays.sort(arr, new Comparator<Type>() {
    @Override
    public int compare(Type a, Type b) {
        return /* comparison */;
    }
});
```

**Example: Sort by multiple criteria**
```java
Integer[] arr = {5, 2, 8, 1, 9};

Arrays.sort(arr, new Comparator<Integer>() {
    @Override
    public int compare(Integer a, Integer b) {
        return b - a;  // Descending order
    }
});
// Result: [9, 8, 5, 2, 1]
```

<br>

### 5. Comparable Interface

**Syntax:**
```java
class MyClass implements Comparable<MyClass> {
    @Override
    public int compareTo(MyClass other) {
        return /* comparison */;
    }
}
```

**Example: Custom Student class**
```java
class Student implements Comparable<Student> {
    String name;
    int marks;
    
    Student(String name, int marks) {
        this.name = name;
        this.marks = marks;
    }
    
    @Override
    public int compareTo(Student other) {
        return other.marks - this.marks;  // Descending by marks
    }
}

Student[] students = {
    new Student("Alice", 85),
    new Student("Bob", 92),
    new Student("Charlie", 78)
};

Arrays.sort(students);
// Result: Bob(92), Alice(85), Charlie(78)
```

<br>

---

## Comparator Return Value Rules

### Critical Rule

**Return:**
- **Negative** if `a` should come BEFORE `b`
- **Zero** if `a` equals `b`
- **Positive** if `a` should come AFTER `b`

```java
// Ascending order
return a - b;  // or Integer.compare(a, b)

// Descending order
return b - a;  // or Integer.compare(b, a)
```

<br>

### Common Mistakes

```java
// ❌ Wrong: Integer overflow
return a - b;  // If a = 2000000000, b = -2000000000, overflow!

// ✓ Correct: Use Integer.compare()
return Integer.compare(a, b);
```

<br>

---

## Problem Variations

### Variation 1: Sort by Absolute Value

```java
Integer[] arr = {-5, 2, -8, 1, 9, -3};

Arrays.sort(arr, (a, b) -> Math.abs(a) - Math.abs(b));
// Result: [1, 2, -3, -5, -8, 9]
```

<br>

### Variation 2: Sort Strings by Length, Then Alphabetically

```java
String[] words = {"apple", "pie", "banana", "cat", "dog"};

Arrays.sort(words, (a, b) -> {
    if (a.length() != b.length())
        return a.length() - b.length();
    return a.compareTo(b);
});
// Result: ["cat", "dog", "pie", "apple", "banana"]
```

<br>

### Variation 3: Sort 2D Array by Column

```java
int[][] matrix = {
    {1, 5, 3},
    {2, 1, 4},
    {3, 8, 2}
};

// Sort by second column (index 1)
Arrays.sort(matrix, (a, b) -> a[1] - b[1]);
// Result: [[2,1,4], [1,5,3], [3,8,2]]
```

<br>

### Variation 4: Sort by Frequency

```java
Integer[] arr = {4, 5, 6, 5, 4, 3};

// Count frequency
Map<Integer, Integer> freq = new HashMap<>();
for (int x : arr) {
    freq.put(x, freq.getOrDefault(x, 0) + 1);
}

// Sort by frequency (descending), then by value (ascending)
Arrays.sort(arr, (a, b) -> {
    int freqCompare = freq.get(b) - freq.get(a);
    if (freqCompare != 0) return freqCompare;
    return a - b;
});
// Result: [4, 4, 5, 5, 3, 6]
```

<br>

### Variation 5: Sort by Distance from Origin

```java
class Point {
    int x, y;
    Point(int x, int y) {
        this.x = x;
        this.y = y;
    }
}

Point[] points = {new Point(1, 2), new Point(3, 4), new Point(0, 1)};

Arrays.sort(points, (a, b) -> {
    int distA = a.x * a.x + a.y * a.y;
    int distB = b.x * b.x + b.y * b.y;
    return distA - distB;
});
// Result: [(0,1), (1,2), (3,4)]
```

<br>

### Variation 6: Sort Intervals by Start, Then by End

```java
int[][] intervals = {{1, 5}, {1, 3}, {2, 4}};

Arrays.sort(intervals, (a, b) -> {
    if (a[0] != b[0])
        return a[0] - b[0];
    return a[1] - b[1];
});
// Result: [[1,3], [1,5], [2,4]]
```

<br>

### Variation 7: Sort by Custom Priority

```java
// Sort: even numbers first (ascending), then odd numbers (descending)
Integer[] arr = {1, 2, 3, 4, 5, 6, 7, 8};

Arrays.sort(arr, (a, b) -> {
    boolean aEven = (a % 2 == 0);
    boolean bEven = (b % 2 == 0);
    
    if (aEven && !bEven) return -1;
    if (!aEven && bEven) return 1;
    
    if (aEven) return a - b;   // Even: ascending
    return b - a;              // Odd: descending
});
// Result: [2, 4, 6, 8, 7, 5, 3, 1]
```

<br>

### Variation 8: Sort with Multiple Keys

```java
class Student {
    String name;
    int marks;
    int age;
    
    Student(String name, int marks, int age) {
        this.name = name;
        this.marks = marks;
        this.age = age;
    }
}

Student[] students = {
    new Student("Alice", 85, 20),
    new Student("Bob", 85, 19),
    new Student("Charlie", 92, 20)
};

// Sort by marks (desc), then age (asc), then name (asc)
Arrays.sort(students, Comparator
    .comparing((Student s) -> s.marks).reversed()
    .thenComparing(s -> s.age)
    .thenComparing(s -> s.name));
// Result: Charlie(92,20), Bob(85,19), Alice(85,20)
```

<br>

---

## Comparator Chaining (Java 8+)

### thenComparing()

```java
String[] words = {"apple", "pie", "banana", "cat", "dog"};

Arrays.sort(words, Comparator
    .comparing(String::length)
    .thenComparing(String::compareTo));
// Sort by length, then alphabetically
```

<br>

### Multiple Chaining

```java
class Person {
    String name;
    int age;
    double salary;
}

Arrays.sort(people, Comparator
    .comparing(Person::getAge)
    .thenComparing(Person::getSalary)
    .thenComparing(Person::getName));
```

<br>

---

## Sorting Different Collections

### Array of Primitives

```java
int[] arr = {5, 2, 8, 1, 9};
Arrays.sort(arr);
```

<br>

### Array of Objects

```java
Integer[] arr = {5, 2, 8, 1, 9};
Arrays.sort(arr, (a, b) -> b - a);  // Descending
```

<br>

### ArrayList

```java
List<Integer> list = new ArrayList<>(Arrays.asList(5, 2, 8, 1, 9));
Collections.sort(list);

// Or using List.sort() (Java 8+)
list.sort(Comparator.naturalOrder());
```

<br>

### Custom Objects in ArrayList

```java
List<Student> students = new ArrayList<>();
students.add(new Student("Alice", 85));
students.add(new Student("Bob", 92));

students.sort((a, b) -> b.marks - a.marks);
```

<br>

---

## Stream API Sorting (Java 8+)

### Basic Sorting

```java
List<Integer> list = Arrays.asList(5, 2, 8, 1, 9);

List<Integer> sorted = list.stream()
    .sorted()
    .collect(Collectors.toList());
```

<br>

### Custom Comparator

```java
List<String> words = Arrays.asList("apple", "pie", "banana");

List<String> sorted = words.stream()
    .sorted(Comparator.comparing(String::length))
    .collect(Collectors.toList());
```

<br>

### Reverse Order

```java
List<Integer> sorted = list.stream()
    .sorted(Comparator.reverseOrder())
    .collect(Collectors.toList());
```

<br>

---

## Performance Tips

### 1. Avoid Integer Overflow

```java
// ❌ Wrong: Can overflow
Arrays.sort(arr, (a, b) -> a - b);

// ✓ Correct: Use Integer.compare()
Arrays.sort(arr, (a, b) -> Integer.compare(a, b));

// Or use method reference
Arrays.sort(arr, Integer::compare);
```

<br>

### 2. Use Primitive Arrays When Possible

```java
// ✓ Faster: Primitive array
int[] arr = {5, 2, 8, 1, 9};
Arrays.sort(arr);

// ❌ Slower: Object array (boxing overhead)
Integer[] arr2 = {5, 2, 8, 1, 9};
Arrays.sort(arr2);
```

<br>

### 3. Precompute Values

```java
// ❌ Slow: Recalculates every comparison
Arrays.sort(points, (a, b) -> {
    return Math.sqrt(a.x*a.x + a.y*a.y) - Math.sqrt(b.x*b.x + b.y*b.y);
});

// ✓ Fast: Avoid sqrt
Arrays.sort(points, (a, b) -> {
    return (a.x*a.x + a.y*a.y) - (b.x*b.x + b.y*b.y);
});
```

<br>

---

## Parallel Sorting (Java 8+)

For large arrays, use parallel sort:

```java
int[] arr = new int[1000000];
// ... fill array

Arrays.parallelSort(arr);  // Uses Fork/Join framework
```

**When to use:**
- Array size > 8192 elements
- Multi-core processor available
- No custom comparator needed (primitives only)

<br>

---

## Common Patterns Summary

| Pattern | Comparator |
|---------|------------|
| Ascending | `(a, b) -> a - b` or `Integer::compare` |
| Descending | `(a, b) -> b - a` or `Comparator.reverseOrder()` |
| By absolute value | `(a, b) -> Math.abs(a) - Math.abs(b)` |
| By length | `Comparator.comparing(String::length)` |
| By second element | `(a, b) -> a[1] - b[1]` |
| Multiple criteria | Use `thenComparing()` |
| Natural order | `Comparator.naturalOrder()` |
| Reverse order | `Comparator.reverseOrder()` |

<br>

---

## Comparator vs Comparable

| Feature | Comparable | Comparator |
|---------|-----------|------------|
| Interface | `Comparable<T>` | `Comparator<T>` |
| Method | `compareTo(T other)` | `compare(T a, T b)` |
| Location | Inside class | Separate class/lambda |
| Sorting | `Arrays.sort(arr)` | `Arrays.sort(arr, comparator)` |
| Use case | Natural ordering | Custom ordering |
| Flexibility | Single ordering | Multiple orderings |

<br>
<br>

---

```code```
