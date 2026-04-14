Rearrange numbers into the lexicographically next greater permutation. If no greater permutation exists, rearrange to the lowest (sorted ascending).

<br>

> Input:
> nums = [1, 2, 3]

> Output:
> [1, 3, 2]

> Explanation:
> Permutations in order: 123, 132, 213, 231, 312, 321. Next after 123 is 132.
> 
> **Key insight:** Find the rightmost "dip" (where nums[i] < nums[i+1]). Swap with the smallest-larger element to its right. Reverse the suffix.

<br>



---

## Constraints

- `1 ≤ nums.length ≤ 100`
- `0 ≤ nums[i] ≤ 100`

<br>

---

## All Possible Edge Cases

1. **Already max permutation:** [3,2,1] → wrap to [1,2,3]
2. **Single element:** [1] → [1] unchanged
3. **Sorted ascending:** [1,2,3] → [1,3,2]
4. **Duplicates:** [1,1,5] → [1,5,1]

<br>

---

## Solution 1: Naive / Brute Force Approach

**Intuition:**
Try the most straightforward method without optimization.

**Algorithm:**
1. Apply the direct/naive approach
2. May involve extra space, multiple passes, or higher time complexity
3. Serves as baseline to understand the problem before optimizing

### Time Complexity: Higher than optimal
**Why?**
Does not exploit key structural properties of the problem.

### Space Complexity: May use extra space

> **Drawback:**
> If you don't know the three-step algorithm, you might try generating all permutations — O(N!) which is infeasible.

> **Key Insight for Improvement:**
> Find the rightmost "dip" (nums[i] < nums[i+1]), swap with the smallest-larger element to its right, and reverse the suffix. This directly constructs the next permutation in O(N).

<br>

---

## Solution 2: Three-Step Algorithm (Optimal)

**Intuition:**
To find the next permutation, we need the smallest increase. Find the rightmost position where we can make an increase (the "dip"), make the smallest possible swap, then minimize the suffix.

**Algorithm:**
1. **Find dip:** Scan right to left, find largest i where nums[i] < nums[i+1]
2. **Find swap partner:** Find largest j > i where nums[j] > nums[i] (smallest element larger than nums[i])
3. **Swap:** swap nums[i] and nums[j]
4. **Reverse suffix:** Reverse nums[i+1..end] to get the smallest suffix arrangement
5. **No dip found:** Reverse entire array (wrap to smallest permutation)

### Time Complexity: O(N)
**Why?**
- Finding dip: O(N) scan from right
- Finding swap partner: O(N) scan from right
- Swap: O(1)
- Reverse: O(N)
- Total: O(N)

**Detailed breakdown:**
- Array size 100 → at most 300 operations (3 passes)
- Optimal — cannot do better since we may need to read all elements

**Example walkthrough:**
```
nums = [1, 5, 8, 4, 7, 6, 5, 3, 1]

Step 1: Find dip — scan right: 1<3? no, 3<5? no, 5<6? no, 6<7? no, 4<7? YES
        dip at i=3 (value 4)

Step 2: Find swap partner — scan right for smallest > 4:
        1? no. 3? no. 5? YES → j=6 (value 5)

Step 3: Swap: [1, 5, 8, 5, 7, 6, 4, 3, 1]

Step 4: Reverse suffix [i+1..end]: [7,6,4,3,1] → [1,3,4,6,7]
        Result: [1, 5, 8, 5, 1, 3, 4, 6, 7] ✓
```

**Why reverse works:**
- After the swap, the suffix nums[i+1..end] is still in descending order
- Reversing a descending sequence gives ascending (smallest possible suffix)

### Space Complexity: O(1)
**Why?**
- All operations are in-place swaps and reversal

> **Drawback:**
> If you don't know the three-step algorithm, you might try generating all permutations — O(N!) which is infeasible.

> **Key Insight for Improvement:**
> Find the rightmost "dip" (nums[i] < nums[i+1]), swap with the smallest-larger element to its right, and reverse the suffix. This directly constructs the next permutation in O(N).


<br>

---

## Complexity Progression Summary

| Solution | Time | Space | Key Improvement |
|----------|------|-------|----------------|
| Generate All Perms | O(N!) | O(N!) | Generate all, find next |
| Three-Step | O(N) | O(1) | Find dip, swap, reverse suffix |

**Recommended Solution:** Three-Step Algorithm — O(N) time, O(1) space.

**Key Insights:**
1. **Dip = rightmost ascent:** The point where we can make a larger number
2. **Swap partner:** Smallest number greater than dip value (ensures minimal increase)
3. **Reverse suffix:** Converts descending suffix to ascending (smallest arrangement)


<br>
<br>

---

```code```
