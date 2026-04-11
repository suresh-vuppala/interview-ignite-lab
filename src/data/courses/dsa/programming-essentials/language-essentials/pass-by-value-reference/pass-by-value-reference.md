## Pass by Value vs Reference — Avoid Silent Bugs in Interviews

Misunderstanding how arguments are passed is one of the most common sources of bugs during interviews. Know exactly what happens when you pass data to a function.

<br>

## C++

| Pass Style | Syntax | What Happens | When to Use |
|------------|--------|--------------|-------------|
| **By value** | `void f(int x)` | Copy of x is made | Small types, don't need to modify |
| **By reference** | `void f(int& x)` | No copy, modifies original | Need to modify, or avoid expensive copy |
| **By const reference** | `void f(const vector<int>& v)` | No copy, read-only | **Default for containers** — most common in interviews |
| **By pointer** | `void f(int* x)` | Pass address | Nullable, array parameters |

**Interview rule of thumb:** Always pass containers (vector, string, map) by `const&` unless you need to modify them.

```cpp
// ❌ BAD — copies the entire vector every call
void solve(vector<int> nums) { ... }

// ✅ GOOD — no copy, read-only
void solve(const vector<int>& nums) { ... }

// ✅ GOOD — no copy, can modify
void solve(vector<int>& nums) { ... }
```

<br>

## Java

- **Primitives** (int, char, boolean) → always **pass by value** (copy)
- **Objects** (arrays, String, custom objects) → pass **reference by value** (the reference is copied, but both point to the same object)

```java
void modify(int[] arr) {
    arr[0] = 99;  // ✅ Modifies original — arr points to same object
}

void reassign(int[] arr) {
    arr = new int[]{1, 2, 3};  // ❌ Does NOT affect caller — local reference changed
}
```

<br>

## Python

- Everything is **pass by object reference**
- Mutable objects (list, dict, set) → modifications visible to caller
- Immutable objects (int, str, tuple) → reassignment creates new object

<br>

---

```code```
