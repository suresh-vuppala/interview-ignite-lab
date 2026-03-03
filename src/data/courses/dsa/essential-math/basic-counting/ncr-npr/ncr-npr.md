## Overview
Calculate combinations (nCr) and permutations (nPr) with and without modulo.

## Topics Covered
1. **nCr Calculation**: Combinations formula
2. **nPr Calculation**: Permutations formula
3. **Pascal's Triangle**: Dynamic programming approach
4. **nCr % m**: Modular combinations

## Approach
### nCr = n! / (r! * (n-r)!)
- Optimize by canceling terms
- Time: O(r)

### nPr = n! / (n-r)!
- Time: O(r)

### Pascal's Triangle
- C(n,r) = C(n-1,r-1) + C(n-1,r)
- Time: O(n*r), Space: O(n*r)

## Complexity Analysis
### Time: O(r) direct, O(n*r) DP

## Code
```code```