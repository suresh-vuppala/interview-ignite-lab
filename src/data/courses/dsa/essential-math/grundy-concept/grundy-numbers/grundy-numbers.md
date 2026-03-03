# Grundy Numbers

## Overview
Understand Grundy numbers (Sprague-Grundy theorem) for solving impartial games.

## Topics Covered
1. **Grundy Number Definition**: MEX of reachable states
2. **Calculate Grundy**: For game positions
3. **Combine Games**: XOR of Grundy numbers

## Approach
### Grundy Number
- Grundy(position) = MEX({Grundy(next_positions)})
- MEX = Minimum Excludant (smallest non-negative integer not in set)
- Time: Depends on game complexity

### Winning Strategy
- Grundy = 0: Losing position
- Grundy ≠ 0: Winning position

## Complexity Analysis
### Time: O(states * transitions)

## Code
```code```