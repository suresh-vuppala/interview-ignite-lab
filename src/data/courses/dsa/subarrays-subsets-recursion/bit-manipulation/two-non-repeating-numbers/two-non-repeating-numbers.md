Find two elements appearing once when others appear twice.

## Approach
- XOR all to get xor = a ^ b
- Find rightmost set bit in xor
- Partition array by this bit
- XOR each partition

## Complexity
- Time: O(n)
- Space: O(1)

## Code
```code```