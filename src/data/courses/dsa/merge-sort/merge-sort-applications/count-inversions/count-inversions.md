Count the number of inversions in an array where an inversion is a pair (i, j) such that i < j and arr[i] > arr[j].

<br>

> Input:
> arr = [8, 4, 2, 1]

> Output:
> 6

> Explanation:
> Inversions: (8,4), (8,2), (8,1), (4,2), (4,1), (2,1)
> Total count = 6
> 
> **Key insight:** Use merge sort to count inversions efficiently during merge phase.

<br>


---

## Constraints

- `0 ≤ n ≤ 10⁵`
- `-10⁹ ≤ nums[i] ≤ 10⁹`

<br>

---

## All Possible Edge Cases

1. **Already sorted:** Still O(n log n) but no inversions
2. **Reverse sorted:** Maximum inversions
3. **Single element:** Already sorted
4. **Empty array:** Nothing to sort
5. **All same elements:** No swaps needed
6. **Two elements:** Single comparison

<br>

---

## Solution 1: Brute Force

**Intuition:**
Check every pair (i, j) where i < j.
If arr[i] > arr[j], count it as an inversion.

**Algorithm:**
1. For each element at index i (0 to N-2):
   - For each element at index j (i+1 to N-1):
     - If arr[i] > arr[j], increment count
2. Return count

**Example:**
```
arr = [8, 4, 2, 1]

i=0 (8): Compare with 4,2,1 → 3 inversions
i=1 (4): Compare with 2,1 → 2 inversions
i=2 (2): Compare with 1 → 1 inversion
i=3 (1): No more elements

Total = 6 inversions
```

### Time Complexity: O(N²)
**Why?**
- Outer loop: N iterations
- Inner loop: N iterations on average
- Total: N × N = O(N²)

### Space Complexity: O(1)
**Why?**
- Only counter variable needed
- No extra space

**Problem:** Too slow for large arrays.

> **Key Insight for Improvement:**
> During merge sort, when we pick element from right subarray, it forms inversions with all remaining elements in left subarray!

<br>

---

## Solution 2: Merge Sort Based (Optimal)

**Intuition:**
Modify merge sort to count inversions during merge phase.
When element from right subarray is smaller than element from left subarray, it forms inversions with all remaining elements in left subarray.

**Algorithm:**
1. Divide array into two halves
2. Recursively count inversions in left half
3. Recursively count inversions in right half
4. Count split inversions during merge:
   - When arr[j] from right is picked before arr[i] from left
   - Add (mid - i + 1) to count (all remaining left elements form inversions)
5. Return total count

**Example Walkthrough:**
```
arr = [8, 4, 2, 1]

Split: [8, 4] and [2, 1]

Left [8, 4]:
  Split: [8] and [4]
  Merge: 8 > 4 → 1 inversion
  Result: [4, 8], count = 1

Right [2, 1]:
  Split: [2] and [1]
  Merge: 2 > 1 → 1 inversion
  Result: [1, 2], count = 1

Merge [4, 8] and [1, 2]:
  Compare 4 and 1: 1 < 4 → pick 1, inversions += 2 (both 4,8 > 1)
  Compare 4 and 2: 2 < 4 → pick 2, inversions += 2 (both 4,8 > 2)
  Pick remaining: 4, 8
  Result: [1, 2, 4, 8], split_inversions = 4

Total = 1 + 1 + 4 = 6 inversions
```

**Merge Phase Detail:**
```
Left = [4, 8], Right = [1, 2]
i = 0, j = 0

Step 1: arr[j]=1 < arr[i]=4
  Pick 1, inversions += (mid - i + 1) = (1 - 0 + 1) = 2
  (Both 4 and 8 are greater than 1)

Step 2: arr[j]=2 < arr[i]=4
  Pick 2, inversions += (mid - i + 1) = (1 - 0 + 1) = 2
  (Both 4 and 8 are greater than 2)

Step 3: Pick remaining 4, 8
```

### Time Complexity: O(N log N)
**Why?**
- Divide: O(log N) levels
- Merge at each level: O(N) work
- Total: O(N log N)

**Detailed breakdown:**
- Same as merge sort time complexity
- Counting inversions adds O(1) per comparison
- Overall: O(N log N)

### Space Complexity: O(N)
**Why?**
- Temporary arrays for merging: O(N)
- Recursion stack: O(log N)
- Total: O(N)

**Improvement:** From O(N²) to O(N log N)
- Example: N = 100,000
- Brute force: 10,000,000,000 operations
- Merge sort: ~1,660,000 operations (6000× faster!)

<br>

---

## Why This Works

**Key Observation:**
When merging two sorted subarrays:
- Left subarray: [a₁, a₂, ..., aₘ] (sorted)
- Right subarray: [b₁, b₂, ..., bₙ] (sorted)

If we pick bⱼ before aᵢ (because bⱼ < aᵢ):
- bⱼ < aᵢ means inversion (aᵢ, bⱼ)
- Since left is sorted: aᵢ < aᵢ₊₁ < ... < aₘ
- Therefore: bⱼ < aᵢ < aᵢ₊₁ < ... < aₘ
- All pairs (aᵢ, bⱼ), (aᵢ₊₁, bⱼ), ..., (aₘ, bⱼ) are inversions
- Count = (m - i + 1)

<br>

---

## Edge Cases

1. **Empty array:** 0 inversions
2. **Single element:** 0 inversions
3. **Sorted array:** 0 inversions
4. **Reverse sorted:** Maximum inversions = N×(N-1)/2
5. **All equal elements:** 0 inversions

<br>

---

## Applications

1. **Similarity Measure:** How far array is from being sorted
2. **Collaborative Filtering:** Measure disagreement between rankings
3. **Kendall Tau Distance:** Statistical measure of correlation
4. **Sorting Algorithms:** Measure of disorder in data
5. **Recommendation Systems:** Compare user preferences

<br>
<br>

---

```code```
