## Problem Statement

You are given an array `arr[]` of size `N` where `arr[i]` represents the number of pages in the `i-th` book. There are `M` students, and the task is to allocate all books to students such that:

1. Each student gets at least one book
2. Each book is allocated to exactly one student
3. Books are allocated in contiguous manner (a student can only get consecutive books)
4. The objective is to **minimize the maximum number of pages** assigned to any student

Return the minimum possible value of the maximum pages assigned.

**Constraints:**
- `1 ≤ N ≤ 10^5`
- `1 ≤ M ≤ N`
- `1 ≤ arr[i] ≤ 10^9`

## Examples

### Example 1:
**Input:**
```
arr[] = [12, 34, 67, 90]
M = 2
```

**Output:**
```
113
```

**Explanation:**
- Allocation 1: [12, 34, 67] | [90] → max = 113
- Allocation 2: [12, 34] | [67, 90] → max = 157
- Allocation 3: [12] | [34, 67, 90] → max = 191

The minimum of maximum pages is 113.

### Example 2:
**Input:**
```
arr[] = [10, 20, 30, 40]
M = 2
```

**Output:**
```
60
```

**Explanation:**
- Best allocation: [10, 20, 30] | [40] → max = 60

### Example 3:
**Input:**
```
arr[] = [5, 17, 100, 11]
M = 4
```

**Output:**
```
100
```

**Explanation:**
- Each student gets one book: [5] | [17] | [100] | [11]
- Maximum pages = 100

## Visual Example

For `arr[] = [12, 34, 67, 90]`, `M = 2`:

```
Search Space: [90, 203]
              ↓
         mid = 146
         
Can allocate with max 146?
Student 1: [12, 34, 67] = 113 ✓
Student 2: [90] = 90 ✓
Yes! Try smaller → right = 145

         mid = 117
         
Can allocate with max 117?
Student 1: [12, 34, 67] = 113 ✓
Student 2: [90] = 90 ✓
Yes! Try smaller → right = 116

         mid = 103
         
Can allocate with max 103?
Student 1: [12, 34] = 46 ✓
Student 2: [67] = 67 ✓ (can't add 90)
Need 3 students ✗
Try larger → left = 104

Answer = 113
```

## Approach: Binary Search on Answer

### Key Insight

The answer lies in the range `[max(arr), sum(arr)]`:
- **Lower bound**: At least one student must read the largest book
- **Upper bound**: One student reads all books

We binary search on this range and check if allocation is possible with given maximum pages.

### Algorithm

1. **Define Search Space:**
   - `left = max(arr)` (minimum possible answer)
   - `right = sum(arr)` (maximum possible answer)

2. **Binary Search:**
   - Calculate `mid = (left + right) / 2`
   - Check if we can allocate books such that no student gets more than `mid` pages
   - If possible: try to minimize further → `right = mid - 1`
   - If not possible: increase limit → `left = mid + 1`

3. **Feasibility Check (canAllocate function):**
   ```
   canAllocate(arr, M, maxPages):
       students = 1
       currentPages = 0
       
       for each book in arr:
           if currentPages + book > maxPages:
               students++
               currentPages = book
           else:
               currentPages += book
       
       return students <= M
   ```

### Step-by-Step Walkthrough

For `arr[] = [12, 34, 67, 90]`, `M = 2`:

**Iteration 1:**
- `left = 90`, `right = 203`, `mid = 146`
- Check if allocation possible with max 146 pages:
  - Student 1: 12 + 34 + 67 = 113 ✓
  - Student 2: 90 ✓
  - Students needed = 2 ≤ 2 ✓
- Possible! Try smaller: `right = 145`

**Iteration 2:**
- `left = 90`, `right = 145`, `mid = 117`
- Check with max 117 pages:
  - Student 1: 12 + 34 + 67 = 113 ✓
  - Student 2: 90 ✓
  - Students needed = 2 ≤ 2 ✓
- Possible! Try smaller: `right = 116`

**Iteration 3:**
- `left = 90`, `right = 116`, `mid = 103`
- Check with max 103 pages:
  - Student 1: 12 + 34 = 46 ✓
  - Student 2: 67 ✓
  - Student 3: 90 (need 3rd student)
  - Students needed = 3 > 2 ✗
- Not possible! Increase: `left = 104`

**Iteration 4:**
- `left = 104`, `right = 116`, `mid = 110`
- Not possible (needs 3 students)
- `left = 111`

**Iteration 5:**
- `left = 111`, `right = 116`, `mid = 113`
- Check with max 113 pages:
  - Student 1: 12 + 34 + 67 = 113 ✓
  - Student 2: 90 ✓
  - Students needed = 2 ≤ 2 ✓
- Possible! `right = 112`

**Iteration 6:**
- `left = 111`, `right = 112`, `mid = 111`
- Not possible (needs 3 students)
- `left = 112`

**Iteration 7:**
- `left = 112`, `right = 112`, `mid = 112`
- Not possible
- `left = 113`

**Final:** `left = 113` → Answer = **113**


---

## Constraints

- `1 ≤ n ≤ 10⁵`
- `Input array elements ≥ 1`
- `Answer is monotonic — if X works, X+1 also works (or vice versa)`

<br>

---

## All Possible Edge Cases

1. **Minimum possible answer:** Binary search low boundary
2. **Maximum possible answer:** Binary search high boundary
3. **Single element array:** Answer is trivially that element
4. **All elements same:** Answer may be the element or a function of it
5. **Large range:** Binary search on answer space O(log(range))

<br>

## Complexity Analysis

### Time Complexity: **O(N × log(sum - max))**

**Why?**
- Binary search runs in `O(log(sum - max))` iterations
- Each iteration calls `canAllocate()` which takes `O(N)` time
- Total: `O(N × log(sum - max))`

For `N = 10^5`, `sum = 10^14`:
- `log(10^14) ≈ 47` iterations
- Total operations ≈ `10^5 × 47 ≈ 5 × 10^6` (very efficient)

### Space Complexity: **O(1)**

**Why?**
- Only using constant extra space for variables
- No additional data structures needed

## Edge Cases

1. **M = N (Each student gets one book):**
   ```
   arr[] = [10, 20, 30]
   M = 3
   Answer = 30 (maximum book pages)
   ```

2. **M = 1 (One student gets all books):**
   ```
   arr[] = [10, 20, 30]
   M = 1
   Answer = 60 (sum of all pages)
   ```

3. **All books have same pages:**
   ```
   arr[] = [50, 50, 50, 50]
   M = 2
   Answer = 100 (each student gets 2 books)
   ```

4. **One very large book:**
   ```
   arr[] = [5, 5, 5, 100]
   M = 2
   Answer = 100 (one student must take the large book)
   ```

## Common Mistakes

1. **Wrong search space:**
   - ❌ Starting from 0 or 1
   - ✅ Start from `max(arr)` (minimum possible answer)

2. **Incorrect feasibility check:**
   - ❌ Allowing non-contiguous allocation
   - ✅ Books must be allocated in contiguous manner

3. **Off-by-one errors:**
   - ❌ Using `right = mid` when answer is possible
   - ✅ Use `right = mid - 1` to find minimum

4. **Integer overflow:**
   - ❌ Using `int` for sum calculation
   - ✅ Use `long long` for large inputs

## Related Problems

1. **Painter's Partition Problem** - Same pattern, different context
2. **Split Array Largest Sum** - Identical problem with different wording
3. **Capacity To Ship Packages Within D Days** - Similar binary search on answer
4. **Minimize Max Distance to Gas Station** - Distance optimization variant

## Key Takeaways

1. **Pattern Recognition:** "Minimize the maximum" → Binary search on answer
2. **Search Space:** Always between `max(arr)` and `sum(arr)`
3. **Feasibility Check:** Greedy allocation to verify if answer is possible
4. **Optimization Direction:** If feasible, try smaller; if not, try larger
5. **Contiguous Constraint:** Books must be allocated consecutively

```code```
