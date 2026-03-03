Manipulate individual bits at position i.

## Operations
- Check: (n & (1 << i)) != 0
- Set: n | (1 << i)
- Unset: n & ~(1 << i)
- Toggle: n ^ (1 << i)

## Complexity
- Time: O(1)
- Space: O(1)

## Code
```code```