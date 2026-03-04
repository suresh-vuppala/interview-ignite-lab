There are n gas stations along a circular route. Given two arrays: gas[i] = amount of gas at station i, and cost[i] = gas needed to travel from station i to i+1. Find the starting gas station index to complete the circuit, or return -1 if impossible.

<br>

> Input:
> gas = [1, 2, 3, 4, 5]
> cost = [3, 4, 5, 1, 2]

> Output:
> 3

> Explanation:
> Starting from station 3:
> - At station 3: gas = 4, cost to next = 1, remaining = 4-1 = 3
> - At station 4: gas = 3+5 = 8, cost to next = 2, remaining = 8-2 = 6
> - At station 0: gas = 6+1 = 7, cost to next = 3, remaining = 7-3 = 4
> - At station 1: gas = 4+2 = 6, cost to next = 4, remaining = 6-4 = 2
> - At station 2: gas = 2+3 = 5, cost to next = 5, remaining = 5-5 = 0
> - Back at station 3: Successfully completed circuit
> 
> Total gas = 15, Total cost = 15 (possible to complete)

<br>

---

## Solution: Greedy Single Pass

Approach:
1. If total gas < total cost, no solution exists
2. Track current tank gas while traversing
3. If tank becomes negative, reset start to next station
4. The last valid start position is the answer

**Key insight:** If we can't reach station j from station i, then we can't reach j from any station between i and j.

```code```

<br>

### Time Complexity Analysis

**Single Pass: O(n)**
- Traverse all n stations once
- For each station:
  - Calculate gas - cost: O(1)
  - Update total and current tank: O(1)
  - Check if reset needed: O(1)
- Total: n × O(1) = O(n)

**No sorting or nested loops needed**
- Greedy approach processes each station exactly once
- No backtracking required

**Why this works:**
- If total gas ≥ total cost, solution exists
- If we fail at station j starting from i, all stations between i and j also fail
- So we can skip directly to j+1 as potential start
- Last valid start is guaranteed to work if total gas ≥ total cost

> **Time Complexity:** O(n) - single pass through stations
> **Space Complexity:** O(1) - only a few variables needed

<br>
<br>

---