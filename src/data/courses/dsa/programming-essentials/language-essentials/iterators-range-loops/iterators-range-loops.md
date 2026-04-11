## Iterators & Loops — Write Clean Interview Code Fast

Clean iteration patterns make your code readable and less error-prone under pressure.

<br>

## C++ Iteration Patterns

```cpp
// Range-based for (preferred):
for (int x : nums) { ... }              // By value (copy)
for (int& x : nums) { x *= 2; }        // By reference (modify)
for (const auto& [key, val] : mp) { ... } // Structured binding (C++17)

// Index-based (when you need the index):
for (int i = 0; i < n; i++) { ... }

// Iterator-based (for erase during iteration):
for (auto it = s.begin(); it != s.end(); ) {
    if (*it == target) it = s.erase(it);  // erase returns next iterator
    else ++it;
}

// Reverse iteration:
for (int i = n - 1; i >= 0; i--) { ... }
for (auto it = v.rbegin(); it != v.rend(); ++it) { ... }
```

<br>

## Java Iteration Patterns

```java
// Enhanced for:
for (int x : nums) { ... }
for (Map.Entry<String, Integer> e : map.entrySet()) { ... }

// Index-based:
for (int i = 0; i < nums.length; i++) { ... }

// Iterator (for safe removal):
Iterator<Integer> it = set.iterator();
while (it.hasNext()) {
    if (it.next() == target) it.remove();  // Safe removal
}

// Java 8+ streams:
list.stream().filter(x -> x > 0).mapToInt(x -> x).sum();
```

<br>

## Python Iteration Patterns

```python
# Direct:
for x in nums: ...

# With index:
for i, x in enumerate(nums): ...

# Pairs:
for k, v in dictionary.items(): ...

# Zip two lists:
for a, b in zip(list1, list2): ...

# Reverse:
for x in reversed(nums): ...

# List comprehension:
squares = [x*x for x in nums if x > 0]
```

<br>

## Common Pitfalls in Interviews

1. **Modifying a collection during iteration** → Use iterator-based removal or iterate over a copy
2. **Off-by-one in loops** → Clarify: is it `i < n` or `i <= n`?
3. **Integer overflow in index arithmetic** → Use `mid = lo + (hi - lo) / 2` not `(lo + hi) / 2`
4. **Forgetting to handle empty input** → Check `if (nums.empty())` before accessing `nums[0]`

<br>
