Understanding how to handle input and output is fundamental to solving programming problems. This guide covers essential I/O techniques across different programming languages.

<br>

---

## Why Input/Output Matters

In competitive programming and technical interviews:
- **Input** defines the problem data you'll work with
- **Output** is how you present your solution
- Incorrect I/O handling leads to wrong answers even with correct logic
- Fast I/O can make difference between passing and timing out

<br>

---

## Input/Output in Different Languages

### Java

**Reading Input:**
```java
import java.util.Scanner;

Scanner sc = new Scanner(System.in);

// Read integer
int n = sc.nextInt();

// Read string
String s = sc.next();      // Single word
String line = sc.nextLine(); // Entire line

// Read double
double d = sc.nextDouble();

// Read long
long l = sc.nextLong();
```

**Writing Output:**
```java
// Print with newline
System.out.println("Hello");

// Print without newline
System.out.print("Hello");

// Formatted output
System.out.printf("Value: %d\n", 42);
System.out.printf("%.2f\n", 3.14159); // 2 decimal places
```

<br>

### C++

**Reading Input:**
```cpp
#include <iostream>
using namespace std;

// Read integer
int n;
cin >> n;

// Read string
string s;
cin >> s;           // Single word
getline(cin, s);    // Entire line

// Read multiple values
int a, b, c;
cin >> a >> b >> c;

// Read double
double d;
cin >> d;
```

**Writing Output:**
```cpp
// Print with newline
cout << "Hello" << endl;

// Print without newline
cout << "Hello";

// Print multiple values
cout << a << " " << b << endl;

// Formatted output
cout << fixed << setprecision(2) << 3.14159; // 2 decimals
```

<br>

### Python

**Reading Input:**
```python
# Read integer
n = int(input())

# Read string
s = input()

# Read multiple integers
a, b, c = map(int, input().split())

# Read list of integers
arr = list(map(int, input().split()))

# Read float
f = float(input())
```

**Writing Output:**
```python
# Print with newline
print("Hello")

# Print without newline
print("Hello", end="")

# Print multiple values
print(a, b, c)

# Formatted output
print(f"Value: {x}")
print(f"{3.14159:.2f}")  # 2 decimal places
```

<br>

---

## Common Input Patterns

### Pattern 1: Single Test Case

**Problem:** Read n, then read n integers

**Input Format:**
```
5
1 2 3 4 5
```

**Java:**
```java
Scanner sc = new Scanner(System.in);
int n = sc.nextInt();
int[] arr = new int[n];
for (int i = 0; i < n; i++) {
    arr[i] = sc.nextInt();
}
```

**Python:**
```python
n = int(input())
arr = list(map(int, input().split()))
```

<br>

### Pattern 2: Multiple Test Cases

**Problem:** First line has T (test cases), then T test cases follow

**Input Format:**
```
3
5
10
15
```

**Java:**
```java
Scanner sc = new Scanner(System.in);
int t = sc.nextInt();
while (t-- > 0) {
    int n = sc.nextInt();
    // Process test case
}
```

**Python:**
```python
t = int(input())
for _ in range(t):
    n = int(input())
    # Process test case
```

<br>

### Pattern 3: Matrix Input

**Problem:** Read n×m matrix

**Input Format:**
```
3 3
1 2 3
4 5 6
7 8 9
```

**Java:**
```java
Scanner sc = new Scanner(System.in);
int n = sc.nextInt();
int m = sc.nextInt();
int[][] matrix = new int[n][m];
for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
        matrix[i][j] = sc.nextInt();
    }
}
```

**Python:**
```python
n, m = map(int, input().split())
matrix = []
for i in range(n):
    row = list(map(int, input().split()))
    matrix.append(row)
```

<br>

### Pattern 4: String Array Input

**Problem:** Read n strings

**Input Format:**
```
3
apple
banana
cherry
```

**Java:**
```java
Scanner sc = new Scanner(System.in);
int n = sc.nextInt();
sc.nextLine(); // Consume newline
String[] arr = new String[n];
for (int i = 0; i < n; i++) {
    arr[i] = sc.nextLine();
}
```

**Python:**
```python
n = int(input())
arr = []
for i in range(n):
    arr.append(input())
```

<br>

---

## Common Output Patterns

### Pattern 1: Single Value

**Java:**
```java
System.out.println(result);
```

**Python:**
```python
print(result)
```

<br>

### Pattern 2: Array/List Output

**Problem:** Print array elements space-separated

**Java:**
```java
for (int i = 0; i < arr.length; i++) {
    System.out.print(arr[i]);
    if (i < arr.length - 1) System.out.print(" ");
}
System.out.println();
```

**Python:**
```python
print(*arr)  # Space-separated
# OR
print(' '.join(map(str, arr)))
```

<br>

### Pattern 3: Matrix Output

**Problem:** Print matrix row by row

**Java:**
```java
for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
        System.out.print(matrix[i][j] + " ");
    }
    System.out.println();
}
```

**Python:**
```python
for row in matrix:
    print(*row)
```

<br>

### Pattern 4: Yes/No Output

**Java:**
```java
System.out.println(condition ? "YES" : "NO");
```

**Python:**
```python
print("YES" if condition else "NO")
```

<br>

---

## Fast I/O Techniques

### Java - BufferedReader (Faster than Scanner)

```java
import java.io.*;
import java.util.*;

BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

// Read line
String line = br.readLine();

// Read integer
int n = Integer.parseInt(br.readLine());

// Read multiple integers
String[] tokens = br.readLine().split(" ");
int a = Integer.parseInt(tokens[0]);
int b = Integer.parseInt(tokens[1]);

// Fast output
BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
bw.write("Hello\n");
bw.flush();
```

<br>

### C++ - Fast I/O

```cpp
// Add at beginning of main()
ios_base::sync_with_stdio(false);
cin.tie(NULL);

// Now cin/cout are much faster
```

<br>

### Python - sys module (Faster than input())

```python
import sys
input = sys.stdin.readline

# Now input() is faster
n = int(input())
```

<br>

---

## Common Mistakes and Solutions

### Mistake 1: Not Consuming Newline

**Problem:**
```java
int n = sc.nextInt();
String s = sc.nextLine(); // Gets empty string!
```

**Solution:**
```java
int n = sc.nextInt();
sc.nextLine(); // Consume newline
String s = sc.nextLine(); // Now works correctly
```

<br>

### Mistake 2: Wrong Data Type

**Problem:** Reading large number as int (overflow)

**Solution:** Use long instead
```java
long n = sc.nextLong(); // Instead of nextInt()
```

<br>

### Mistake 3: Forgetting to Flush Output

**Problem:** Output not appearing immediately

**Solution:**
```java
System.out.flush();
```

<br>

### Mistake 4: Reading Past End of Input

**Problem:** Trying to read when no more input

**Solution:**
```java
while (sc.hasNext()) {
    // Safe to read
}
```

<br>

---

## Practice Tips

1. **Test with Sample Input:** Always test with provided examples
2. **Check Edge Cases:** Empty input, single element, large numbers
3. **Match Output Format Exactly:** Extra spaces or newlines cause wrong answer
4. **Use Fast I/O for Large Inputs:** When n > 10^5
5. **Close Scanner:** `sc.close()` at end (good practice)

<br>

---

## Quick Reference

| Task | Java | C++ | Python |
|------|------|-----|--------|
| Read int | `sc.nextInt()` | `cin >> n` | `int(input())` |
| Read string | `sc.next()` | `cin >> s` | `input()` |
| Read line | `sc.nextLine()` | `getline(cin,s)` | `input()` |
| Print | `System.out.println()` | `cout << endl` | `print()` |
| Print no newline | `System.out.print()` | `cout <<` | `print(end="")` |

<br>

---

## Key Takeaways

- Master basic I/O in your preferred language
- Understand common input patterns
- Use fast I/O for competitive programming
- Always test with sample inputs
- Match output format exactly
- Handle edge cases (empty input, large numbers)

> **Interview Tip:** In interviews, clarify input format before coding. Ask: "Will input always be valid?" "What's the range of values?" "How many test cases?"

<br>
<br>

---

---

## Constraints

- `Introductory lessons — basic constraints`

<br>

---

## All Possible Edge Cases

1. **Empty input:** Handle base case
2. **Single element:** Trivial case
3. **Large input:** Consider time complexity

<br>

---

```code```
