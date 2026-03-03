## Problem Statement
Implement a trie for binary representation of numbers to support XOR operations.

## Approach

### Binary Trie Structure
- Each node has two children: 0 and 1
- Store numbers bit by bit (MSB to LSB)
- Typically use 31 or 32 bits for integers

### Operations
- **Insert**: Add number bit by bit
- **Query**: Find number with max XOR
- Time: O(32) per operation

## Complexity
- Insert: O(32) = O(1)
- Query: O(32) = O(1)
- Space: O(N*32)

```code```
