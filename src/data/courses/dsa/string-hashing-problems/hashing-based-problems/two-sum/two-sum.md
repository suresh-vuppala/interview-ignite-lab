Given an array of integers nums and an integer target, return indices of the two numbers such that they add up to target. Use a hash map for O(n) solution.

<br>

> Input:
> nums = [2, 7, 11, 15], target = 9

> Output:
> [0, 1]

> Explanation:
> nums[0] + nums[1] = 2 + 7 = 9
> 
> **Key insight:** For each number, check if its complement (target - num) was already seen using a hash map.

<br>

---

## Constraints

- `2 ≤ nums.length ≤ 10⁴`
- `-10⁹ ≤ nums[i] ≤ 10⁹`
- `-10⁹ ≤ target ≤ 10⁹`
- `Exactly one solution exists`
- `Cannot use the same element twice`

<br>

---

## All Possible Edge Cases

1. **Two elements only:** Must be the answer pair
2. **Negative numbers:** [-3, 4, 3, 90] target=0 → [0,2]
3. **Target is 0:** Need a + b = 0
4. **Duplicate values:** [3,3] target=6 → [0,1] — same value, different indices
5. **Large values:** Watch for integer overflow in sum
6. **First and last elements:** Answer at array extremes

<br>

---

## Solution 1: Brute Force

**Intuition:**
Check every pair of elements. For each element, scan all elements after it to find a complement.

**Algorithm:**
1. For each index i from 0 to n-2:
   - For each index j from i+1 to n-1:
     - If nums[i] + nums[j] == target → return [i, j]
2. No solution found (shouldn't happen per constraints)

### Time Complexity: O(n²)
**Why?**
- Outer loop: n iterations
- Inner loop: up to n iterations per outer
- Total pairs checked: n(n-1)/2

### Space Complexity: O(1)
- Only loop variables, no extra data structures

> **Key Insight for Improvement:**
> For each number, we're scanning the entire array to find its complement. Can we look up the complement in O(1)? Yes — use a hash map!

<br>

---

## Solution 2: Hash Map (One Pass)

**Intuition:**
As we iterate, store each number and its index in a hash map. For each new number, check if its complement (target - num) is already in the map.

**Algorithm:**
1. Create empty hash map: value → index
2. For each index i:
   - complement = target - nums[i]
   - If complement exists in map → return [map[complement], i]
   - Else store nums[i] → i in map
3. Return [] (no solution — shouldn't happen)

### Time Complexity: O(n)
**Why?**
- Single pass through array: n iterations
- Hash map lookup/insert: O(1) average each
- Total: O(n)

### Space Complexity: O(n)
- Hash map stores up to n entries

<br>

---

## Complexity Progression Summary

| Solution | Time | Space | Key Improvement |
|----------|------|-------|----------------|
| Brute Force | O(n²) | O(1) | Check all pairs |
| Hash Map | O(n) | O(n) | O(1) complement lookup via hash map |

**Recommended:** Hash Map — O(n) time, O(n) space.

**Key Insights:**
1. **Brute → Hash Map:** Trade O(n) space for O(n²) → O(n) time improvement
2. **One-pass trick:** Check complement BEFORE inserting current element — avoids using same element twice

<br>
<br>

---

```code```
