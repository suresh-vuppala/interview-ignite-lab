Given an array of size n, find the majority element. The majority element is the element that appears more than ⌊n/2⌋ times. You may assume that the majority element always exists in the array.

<br>

> Input:
> nums = [3, 2, 3]

> Output:
> 3

> Explanation:
> Element 3 appears 2 times out of 3, which is more than ⌊3/2⌋ = 1.
> 
> **Key insight:** Use Boyer-Moore Voting Algorithm - maintain a candidate and count, cancel out different elements.

<br>

---

## Solution 1: Brute Force

**Intuition:**
For each element, count its occurrences in the entire array. If count > n/2, it's the majority element.

**Algorithm:**
1. For each element nums[i]:
   - Count occurrences of nums[i] in entire array
   - If count > n/2, return nums[i]
2. Return -1 (no majority element)

### Time Complexity: O(N²)
**Why?**
- Outer loop: N iterations (each element)
- Inner loop: N iterations (count occurrences)
- Total: N × N = O(N²)

**Detailed breakdown:**
- For each of N elements: scan entire array
- Total: N × N = N² operations
- Example: Array size 1000 → 1,000,000 operations

### Space Complexity: O(1)
**Why?**
- Only storing count variable
- No extra data structures

**Problem:** Very slow for large arrays due to repeated counting.

> **Key Insight for Improvement:**
> We're counting each element multiple times. Can we count once? Yes! Use HashMap to store frequency of each element in single pass.

<br>

---

## Solution 2: HashMap (Frequency Count)

**Intuition:**
Use HashMap to count frequency of each element in one pass. Then find element with frequency > n/2.

**Algorithm:**
1. Create HashMap to store element → frequency
2. For each element in array:
   - Increment frequency in map
   - If frequency > n/2, return element
3. Return -1 (no majority element)

### Time Complexity: O(N)
**Why?**
- Single pass through array: N iterations
- HashMap operations (get/put): O(1) average
- Total: N × O(1) = O(N)

**Detailed breakdown:**
- One loop: N iterations
- Each iteration: O(1) map operations
- Total: N operations
- Example: Array size 1000 → 1000 operations

**Improvement:** From O(N²) to O(N)
- Example: Array size 1000
- Brute force: 1,000,000 operations
- HashMap: 1000 operations (1000× faster!)

### Space Complexity: O(N)
**Why?**
- HashMap stores at most N different elements
- Worst case: all elements unique
- O(N) space

**Why this works:**
- Count each element exactly once
- Majority element will have count > n/2
- Can return immediately when found

> **Key Insight for Improvement:**
> We're using O(N) space. Can we do better? Yes! Sort the array - the middle element must be the majority element (since it appears > n/2 times).

<br>

---

## Solution 3: Sorting

**Intuition:**
Sort the array. The element at index n/2 must be the majority element because it appears more than n/2 times.

**Why middle element?**
- Majority element appears > n/2 times
- After sorting, it must occupy the middle position
- Even if not centered, it spans across the middle

**Algorithm:**
1. Sort the array
2. Return element at index n/2

### Time Complexity: O(N log N)
**Why?**
- Sorting: O(N log N)
- Accessing middle element: O(1)
- Total: O(N log N)

**Detailed breakdown:**
- Sorting dominates: N log N
- Example: Array size 1000 → 1000 × 10 = 10,000 operations

**Comparison:**
- Slower than HashMap O(N)
- But simpler implementation
- Good if array already sorted or nearly sorted

### Space Complexity: O(1) or O(N)
**Why?**
- Depends on sorting algorithm
- In-place sort (heapsort): O(1)
- Merge sort: O(N)
- Typically O(log N) for quicksort recursion stack

**Why this works:**
```
Example: [2,2,1,1,1,2,2]
Sorted:  [1,1,1,2,2,2,2]
         ↑     ↑     ↑
         0     3     6
Middle (n/2 = 3): element is 2 ✓

If majority element is 1:
[1,1,1,1,2,2,2]
       ↑
Middle: element is 1 ✓
```

> **Key Insight for Improvement:**
> Sorting is O(N log N). Can we achieve O(N) time with O(1) space? Yes! Boyer-Moore Voting Algorithm - cancel out different elements.

<br>

---

## Solution 4: Boyer-Moore Voting Algorithm

**Intuition:**
Maintain a candidate and count. When we see the same element, increment count. When we see different element, decrement count. If count becomes 0, change candidate. The final candidate is the majority element.

**Why this works:**
- Majority element appears > n/2 times
- Even if we cancel it with all other elements, it will remain
- Think of it as a "voting" where majority wins

**Algorithm:**
1. Initialize candidate = None, count = 0
2. For each element:
   - If count == 0, set candidate = element
   - If element == candidate, increment count
   - Else decrement count
3. Return candidate

### Time Complexity: O(N)
**Why?**
- Single pass through array: N iterations
- Each iteration: O(1) operations
- Total: N × O(1) = O(N)

**Detailed breakdown:**
- One loop: N iterations
- Simple comparisons and arithmetic: O(1)
- Total: N operations
- Example: Array size 1000 → 1000 operations

**Comparison with other O(N) solutions:**
- Same time as HashMap: O(N)
- But better space: O(1) vs O(N)
- Optimal solution!

### Space Complexity: O(1)
**Why?**
- Only two variables: candidate and count
- No extra data structures
- Constant space

**Why this is optimal:**
- Time: O(N) - must visit each element at least once
- Space: O(1) - only two variables
- Cannot do better than O(N) time (must read entire array)

**Example walkthrough:**
```
nums = [2, 2, 1, 1, 1, 2, 2]

i=0: nums[0]=2, count=0 → candidate=2, count=1
i=1: nums[1]=2, same → count=2
i=2: nums[2]=1, diff → count=1
i=3: nums[3]=1, diff → count=0
i=4: nums[4]=1, count=0 → candidate=1, count=1
i=5: nums[5]=2, diff → count=0
i=6: nums[6]=2, count=0 → candidate=2, count=1

Final candidate: 2 ✓
```

**Intuition behind cancellation:**
- Each non-majority element can cancel at most one majority element
- Since majority > n/2, it will survive all cancellations
- Final candidate must be majority element

<br>

---

## Solution 5: Randomized Algorithm

**Intuition:**
Randomly pick an element. Check if it's the majority element. If yes, return it. If no, repeat. Since majority element is > n/2 of array, probability of picking it is > 50%, so expected iterations is small.

**Algorithm:**
1. Loop:
   - Pick random index
   - Count occurrences of nums[index]
   - If count > n/2, return nums[index]
2. Repeat until found

### Time Complexity: O(N) expected
**Why?**
- Each iteration: O(N) to count
- Expected iterations: 2 (probability > 0.5 to pick majority)
- Total: 2 × N = O(N) expected

**Detailed breakdown:**
- Probability of picking majority: > 0.5
- Expected iterations: 1/0.5 = 2
- Each iteration: O(N) counting
- Expected total: 2N = O(N)

**Worst case:** O(∞) theoretically, but practically very fast

### Space Complexity: O(1)
**Why?**
- Only storing count and random index
- No extra data structures

**When to use:**
- Interesting theoretical approach
- Not recommended for production (non-deterministic)
- Boyer-Moore is better (deterministic O(N))

<br>

---

## Complexity Progression Summary

| Solution | Time | Space | Key Feature |
|----------|------|-------|-------------|
| Brute Force | O(N²) | O(1) | Count each element repeatedly |
| HashMap | O(N) | O(N) | Count once - store frequencies |
| Sorting | O(N log N) | O(1) or O(N) | Middle element is majority |
| Boyer-Moore | O(N) | O(1) | Cancel different elements - optimal |
| Randomized | O(N) expected | O(1) | Random pick - non-deterministic |

**Recommended Solution:** Boyer-Moore Voting Algorithm (Solution 4) - O(N) time, O(1) space, deterministic.

**Key Insights:**
1. **Brute → HashMap:** Count once → avoid repeated counting
2. **HashMap → Sorting:** Trade time for space → middle element property
3. **Sorting → Boyer-Moore:** Cancellation idea → optimal O(N) time, O(1) space
4. **Boyer-Moore is optimal:** Cannot do better than O(N) time (must read array)

<br>
<br>

---

```code```
