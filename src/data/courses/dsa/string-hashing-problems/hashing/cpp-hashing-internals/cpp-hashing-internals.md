# C++ Hashing Internals

C++ uses `unordered_map` and `unordered_set` with hash tables.

## Hash Function
- `std::hash<T>` for built-in types
- Custom hash for user types

## Collision Resolution
- Separate chaining (linked lists)
- Rehashing when load factor exceeds threshold

## Complexity
- Average O(1) insert/search/delete
- Worst O(n) with many collisions

## Code
```code```