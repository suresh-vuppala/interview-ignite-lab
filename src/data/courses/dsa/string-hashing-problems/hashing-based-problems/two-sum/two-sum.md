Given an array of integers nums and an integer target, return indices of the two numbers such that they add up to target.

<br>

> Input: nums = [2, 7, 11, 15], target = 9
> Output: [0, 1]
> Explanation: nums[0] + nums[1] = 2 + 7 = 9

<br>

---

## Constraints

- `2 ≤ nums.length ≤ 10⁴`
- `-10⁹ ≤ nums[i] ≤ 10⁹`
- Exactly one solution exists

<br>

---

## All Possible Edge Cases

1. **Two elements only:** Must be the answer pair
2. **Negative numbers:** [-3, 4, 3, 90] target=0 → [0,2]
3. **Duplicate values:** [3,3] target=6 → [0,1]

<br>

---

## Solution 1: Brute Force — Check All Pairs

**Intuition:**
Check every pair of elements. For each element, scan all elements after it to find a complement.

**Algorithm:**
1. For each index i from 0 to n-2:
   - For each index j from i+1 to n-1:
     - If nums[i] + nums[j] == target → return [i, j]

### Time Complexity: O(n²)
### Space Complexity: O(1)

```code```

> **Key Insight for Improvement:**
> For each number, we're scanning the entire array to find its complement. Can we look up the complement in O(1)? Yes — use a hash map!

<br>

---

## Solution 2: Hash Map — One Pass (Optimal)

**Intuition:**
As we iterate, store each number and its index in a hash map. For each new number, check if its complement (target - num) is already in the map.

**Algorithm:**
1. Create empty hash map: value → index
2. For each index i:
   - complement = target - nums[i]
   - If complement exists in map → return [map[complement], i]
   - Else store nums[i] → i in map

### Time Complexity: O(n)
### Space Complexity: O(n)

```code```

<br>

---

## Complexity Progression Summary

| Solution | Time | Space | Key Improvement |
|----------|------|-------|----------------|
| Brute Force | O(n²) | O(1) | Check all pairs |
| Hash Map | O(n) | O(n) | O(1) complement lookup |

**Key Insights:**
1. **Brute → Hash Map:** Trade O(n) space for O(n²) → O(n) time
2. **One-pass trick:** Check complement BEFORE inserting — avoids using same element twice

<br>
<br>
