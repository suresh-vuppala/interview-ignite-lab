# Maximum XOR of Two Numbers

## Problem Statement
Find maximum XOR of any two numbers in an array.

## Approach

### Binary Trie
- Insert all numbers into binary trie
- For each number:
  - Traverse trie choosing opposite bit when possible
  - This maximizes XOR
- Time: O(N*32)

### Greedy Bit Manipulation
- Build XOR from MSB to LSB
- Check if current bit can be 1
- Time: O(N*32)

## Complexity
- Trie: O(N*32) time, O(N*32) space
- Greedy: O(N*32) time, O(N) space

```code```
