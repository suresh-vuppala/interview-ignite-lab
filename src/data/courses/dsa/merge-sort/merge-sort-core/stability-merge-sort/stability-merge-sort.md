Understand and demonstrate the stability property of merge sort algorithm.

<br>

> Input:
> arr = [(3, 'a'), (1, 'b'), (3, 'c'), (2, 'd')]

> Output:
> [(1, 'b'), (2, 'd'), (3, 'a'), (3, 'c')]

> Explanation:
> Two elements with value 3: (3, 'a') and (3, 'c')
> After sorting, (3, 'a') still comes before (3, 'c')
> 
> **Key insight:** Merge sort is stable because it preserves relative order of equal elements during merge.

<br>

---

## What is Stability?

**Definition:**
A sorting algorithm is **stable** if it preserves the relative order of equal elements.

**Example:**
```
Input: [(3, 'a'), (1, 'b'), (3, 'c'), (2, 'd')]
         ↑                    ↑
    First 3              Second 3

Stable Sort Output: [(1, 'b'), (2, 'd'), (3, 'a'), (3, 'c')]
                                          ↑         ↑
                                     Still in original order

Unstable Sort Output: [(1, 'b'), (2, 'd'), (3, 'c'), (3, 'a')]
                                            ↑         ↑
                                       Order reversed!
```

**Why It Matters:**
- Multi-key sorting (sort by name, then by age)
- Maintaining data integrity
- Database operations
- Stable behavior in production systems

<br>

---

## Why Merge Sort is Stable

**Key Observation:**
During merge, when two elements are equal, we always pick from the **left** subarray first.

**Merge Logic:**
```cpp
if (left[i] <= right[j]) {  // ← Note: <= not <
    result.append(left[i])
    i++
} else {
    result.append(right[j])
    j++
}
```

**Critical Detail:**
- Use `<=` (not `<`)
- When equal, pick from left
- Left subarray contains earlier elements
- This preserves original order

<br>

---

## Proof of Stability

**Claim:** Merge sort is stable.

**Proof by Induction:**

**Base Case:**
- Array of size 1: Trivially stable (no equal elements to reorder)

**Inductive Step:**
Assume merge sort is stable for arrays of size < N.
Prove it's stable for array of size N.

**Case 1: Equal elements in same subarray**
- They stay in same subarray after split
- By induction, they remain in order after recursive sort
- Merge doesn't change their relative order

**Case 2: Equal elements in different subarrays**
- Let x₁ be in left subarray, x₂ be in right subarray
- x₁ appeared before x₂ in original array
- During merge, when x₁ == x₂:
  - We pick x₁ first (because of `<=`)
  - x₁ comes before x₂ in result
  - Original order preserved ✓

**Conclusion:** Merge sort is stable.

<br>

---

## Example Walkthrough

**Input:**
```
arr = [(3, 'a'), (1, 'b'), (3, 'c'), (2, 'd')]
```

**Step-by-Step Execution:**

**Level 1: Split**
```
Left: [(3, 'a'), (1, 'b')]
Right: [(3, 'c'), (2, 'd')]
```

**Level 2: Split Left**
```
Left-Left: [(3, 'a')]
Left-Right: [(1, 'b')]
```

**Level 2: Merge Left**
```
Compare (3, 'a') vs (1, 'b'):
  1 < 3 → pick (1, 'b')
  Append (3, 'a')
Result: [(1, 'b'), (3, 'a')]
```

**Level 2: Split Right**
```
Right-Left: [(3, 'c')]
Right-Right: [(2, 'd')]
```

**Level 2: Merge Right**
```
Compare (3, 'c') vs (2, 'd'):
  2 < 3 → pick (2, 'd')
  Append (3, 'c')
Result: [(2, 'd'), (3, 'c')]
```

**Level 1: Final Merge**
```
Left: [(1, 'b'), (3, 'a')]
Right: [(2, 'd'), (3, 'c')]

Step 1: Compare (1, 'b') vs (2, 'd')
  1 < 2 → pick (1, 'b')
  Result: [(1, 'b')]

Step 2: Compare (3, 'a') vs (2, 'd')
  2 < 3 → pick (2, 'd')
  Result: [(1, 'b'), (2, 'd')]

Step 3: Compare (3, 'a') vs (3, 'c')
  3 == 3 → pick (3, 'a') from LEFT (stability!)
  Result: [(1, 'b'), (2, 'd'), (3, 'a')]

Step 4: Append remaining
  Result: [(1, 'b'), (2, 'd'), (3, 'a'), (3, 'c')]
```

**Verification:**
- Original: (3, 'a') before (3, 'c') ✓
- Sorted: (3, 'a') before (3, 'c') ✓
- **Stable!**

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

## Comparison: Stable vs Unstable

**Stable Merge (using <=):**
```cpp
if (left[i] <= right[j]) {  // Pick left when equal
    result.append(left[i])
    i++
}
```

**Unstable Merge (using <):**
```cpp
if (left[i] < right[j]) {  // Pick right when equal
    result.append(left[i])
    i++
} else {
    result.append(right[j])  // This breaks stability!
    j++
}
```

**Example:**
```
Left: [(3, 'a')]
Right: [(3, 'c')]

Stable (<=): Pick (3, 'a') first → [(3, 'a'), (3, 'c')] ✓
Unstable (<): Pick (3, 'c') first → [(3, 'c'), (3, 'a')] ✗
```

<br>

---

## Real-World Application: Multi-Key Sorting

**Scenario:**
Sort students by grade, then by name.

**Data:**
```
[(85, "Alice"), (90, "Bob"), (85, "Charlie"), (90, "David")]
```

**Step 1: Sort by name (stable)**
```
[(85, "Alice"), (90, "Bob"), (85, "Charlie"), (90, "David")]
```

**Step 2: Sort by grade (stable)**
```
[(85, "Alice"), (85, "Charlie"), (90, "Bob"), (90, "David")]
                                  ↑            ↑
                            Bob before David (name order preserved!)
```

**Why Stability Matters:**
- Within same grade, students sorted by name
- Stability preserves the name ordering
- Without stability, name order would be lost

<br>

---

## Stable vs Unstable Algorithms

**Stable Algorithms:**
- Merge Sort ✓
- Insertion Sort ✓
- Bubble Sort ✓
- Counting Sort ✓
- Radix Sort ✓

**Unstable Algorithms:**
- Quick Sort ✗
- Heap Sort ✗
- Selection Sort ✗

**Why Quick Sort is Unstable:**
```
arr = [3a, 3b, 1]
Pivot = 3a

Partition: [1] [3a] [3b]
But during partition, 3b might be swapped before 3a
Result: [1, 3b, 3a] ✗ (order reversed)
```

**Why Heap Sort is Unstable:**
```
arr = [3a, 3b, 1]
Build heap: [3b, 3a, 1] (heap property, not original order)
Extract: [1, 3b, 3a] ✗ (order reversed)
```

<br>

---

## Making Unstable Algorithms Stable

**Technique: Add Index as Secondary Key**
```
Original: [(3, 'a'), (3, 'c'), (1, 'b')]
Add index: [(3, 'a', 0), (3, 'c', 1), (1, 'b', 2)]

Sort by (value, index):
  Compare (3, 0) vs (3, 1) → (3, 0) comes first
  Result: [(1, 'b', 2), (3, 'a', 0), (3, 'c', 1)]

Remove index: [(1, 'b'), (3, 'a'), (3, 'c')] ✓
```

**Cost:**
- Extra space: O(N) for indices
- Extra comparisons: O(N log N)
- Worth it when stability required

<br>

---

## Testing Stability

**Test Case:**
```cpp
struct Element {
    int key;
    char value;
};

Element arr[] = {
    {3, 'a'}, {1, 'b'}, {3, 'c'}, {2, 'd'}, {3, 'e'}
};

mergeSort(arr);

// Check: All 3's should be in order a, c, e
assert(arr[2].value == 'a');
assert(arr[3].value == 'c');
assert(arr[4].value == 'e');
```

<br>

---

## Edge Cases

1. **No duplicates:** Stability doesn't matter (all elements unique)
2. **All equal:** Order should remain unchanged
3. **Two equal elements:** Should maintain original order
4. **Multiple groups of equal elements:** Each group maintains order

**Examples:**
```
Input: [(1, 'a'), (2, 'b'), (3, 'c')]
Output: [(1, 'a'), (2, 'b'), (3, 'c')] (no duplicates)

Input: [(3, 'a'), (3, 'b'), (3, 'c')]
Output: [(3, 'a'), (3, 'b'), (3, 'c')] (all equal)

Input: [(3, 'a'), (1, 'b'), (3, 'c')]
Output: [(1, 'b'), (3, 'a'), (3, 'c')] (two equal)
```

<br>

---

## Applications

1. **Database Sorting:** Multi-column sort (ORDER BY col1, col2)
2. **Spreadsheet Applications:** Sort by multiple columns
3. **Event Processing:** Maintain timestamp order for same-priority events
4. **Stable Partitioning:** Preserve order within partitions
5. **Radix Sort:** Requires stable sort for each digit

<br>
<br>

---

```code```
