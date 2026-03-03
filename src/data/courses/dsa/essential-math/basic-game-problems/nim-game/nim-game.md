## Overview
Understand basic game theory concepts including Nim game and stone-taking games.

## Topics Covered
1. **Nim Game**: XOR-based winning strategy
2. **Take 1 or 2 Stones**: Dynamic programming approach
3. **Winning/Losing Positions**: Game state analysis

## Approach
### Nim Game
- XOR all pile sizes
- If XOR = 0, losing position; else winning
- Time: O(n)

### Take 1 or 2 Stones
- Losing positions: multiples of 3
- Time: O(1)

## Complexity Analysis
### Time: O(n) for Nim, O(1) for simple games

## Code
```code```