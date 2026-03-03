# Java Hashing Internals

Java uses `HashMap` and `HashSet` backed by hash tables.

## Hash Function
- `hashCode()` method
- Bucket index: `hash & (n-1)`

## Collision Resolution
- Chaining with linked lists
- Tree conversion (Java 8+) when bucket size > 8

## Complexity
- Average O(1) operations
- Worst O(log n) with tree conversion

## Code
```code```