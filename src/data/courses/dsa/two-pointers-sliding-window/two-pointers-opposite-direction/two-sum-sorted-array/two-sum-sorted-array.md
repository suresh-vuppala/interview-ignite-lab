Find two numbers in a sorted array that add up to a target value. Return their 1-indexed indices.

<br>

> Input: numbers = [2, 7, 11, 15], target = 9
> Output: [1, 2]

<br>

---

## Constraints

- `2 ≤ numbers.length ≤ 3 × 10⁴`
- `-1000 ≤ numbers[i] ≤ 1000`
- `numbers is sorted in non-decreasing order`
- `Exactly one solution exists`

<br>

---

## All Possible Edge Cases

1. **First and last elements:** Answer at extremes
2. **Adjacent elements:** Answer is consecutive indices
3. **Negative numbers:** Both negative, sum is negative
4. **Zero in array:** One element could be zero

<br>

---

## Solution 1: Brute Force

**Intuition:** Check all pairs.

### Time Complexity: O(n²)
### Space Complexity: O(1)

<br>

---

## Solution 2: Binary Search for Complement

**Intuition:** For each element, binary search for (target - element) in the remaining array.

### Time Complexity: O(n log n)
### Space Complexity: O(1)

<br>

---

## Solution 3: Two Pointers (Optimal)

**Intuition:**
Start with pointers at both ends. If sum too large, move right pointer left. If sum too small, move left pointer right.

**Algorithm:**
1. left = 0, right = n-1
2. While left < right:
   - sum = nums[left] + nums[right]
   - If sum == target → return [left+1, right+1]
   - If sum < target → left++ (need larger)
   - If sum > target → right-- (need smaller)

**Why this works:** The array is sorted. Moving left increases sum, moving right decreases it. We converge to the answer.

### Time Complexity: O(n)
### Space Complexity: O(1)

<br>

---

## Complexity Progression Summary

| Solution | Time | Space | Key Improvement |
|----------|------|-------|----------------|
| Brute Force | O(n²) | O(1) | Check all pairs |
| Binary Search | O(n log n) | O(1) | Search for complement |
| Two Pointers | O(n) | O(1) | Sorted → converge from ends |

<br>
<br>

---

```code```
