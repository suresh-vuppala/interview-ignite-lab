## Subarrays (Continuous)
- Contiguous elements: [1,2,3] → [1], [1,2], [1,2,3], [2], [2,3], [3]
- Count: O(n²)
- Generation: O(n²)

## Subsequences (Order Maintained)
- Non-contiguous, order preserved: [1,2,3] → [1], [2], [3], [1,2], [1,3], [2,3], [1,2,3]
- Count: O(2^n)
- Generation: O(2^n)

## Subsets (No Order)
- Same as subsequences but unordered
- Count: O(2^n)
- Use recursion or bitmask

## Code
```code```