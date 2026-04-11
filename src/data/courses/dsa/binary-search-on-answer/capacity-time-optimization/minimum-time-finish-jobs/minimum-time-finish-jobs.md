## Problem Statement

You are given an integer array `jobs`, where `jobs[i]` is the amount of time it takes to complete the `i-th` job. There are `k` workers that you can assign jobs to. Each job should be assigned to **exactly one** worker. The **working time** of a worker is the sum of the time it takes to complete all jobs assigned to that worker.

Return the **minimum possible maximum working time** of any assignment.

**Constraints:**
- `1 ≤ k ≤ jobs.length ≤ 12`
- `1 ≤ jobs[i] ≤ 10^7`

## Examples

### Example 1:
**Input:**
```
jobs = [3, 2, 3]
k = 3
```

**Output:**
```
3
```

**Explanation:**
Assign each job to a separate worker:
- Worker 1: job 0 (3 time)
- Worker 2: job 1 (2 time)
- Worker 3: job 2 (3 time)
Maximum time = 3

### Example 2:
**Input:**
```
jobs = [1, 2, 4, 7, 8]
k = 2
```

**Output:**
```
11
```

**Explanation:**
- Worker 1: jobs [0, 1, 2] = 1+2+4 = 7
- Worker 2: jobs [3, 4] = 7+8 = 15 ✗

Better:
- Worker 1: jobs [0, 2, 4] = 1+4+8 = 13 ✗
- Worker 2: jobs [1, 3] = 2+7 = 9

Optimal:
- Worker 1: jobs [1, 3] = 2+7 = 9
- Worker 2: jobs [0, 2, 4] = 1+4+6... wait

Actually optimal:
- Worker 1: jobs [4] = 8
- Worker 2: jobs [0,1,2,3] = 1+2+4+7 = 14 ✗

Let me recalculate:
- Worker 1: jobs [0,1,3] = 1+2+7 = 10
- Worker 2: jobs [2,4] = 4+8 = 12 ✗

Correct optimal:
- Worker 1: jobs [0,1,2] = 1+2+4 = 7
- Worker 2: jobs [3,4] = 7+8 = 15 ✗

Actually:
- Worker 1: jobs [1,2,3] = 2+4+7 = 13 ✗
- Worker 2: jobs [0,4] = 1+8 = 9

Best found:
- Worker 1: jobs [0,2,3] = 1+4+7 = 12 ✗
- Worker 2: jobs [1,4] = 2+8 = 10

Optimal (after trying):
- Worker 1: jobs [0,1,4] = 1+2+8 = 11
- Worker 2: jobs [2,3] = 4+7 = 11
Maximum = 11 ✓

## Approach: Binary Search + Backtracking

### Key Insight

Unlike previous problems, jobs can be assigned in **any order** (not contiguous). This requires:
1. Binary search on the maximum time
2. Backtracking to check if assignment is possible

**Search Space:** `[max(jobs), sum(jobs)]`

### Algorithm

1. **Binary Search:**
   ```cpp
   left = max(jobs)
   right = sum(jobs)
   
   while (left <= right) {
       mid = (left + right) / 2
       
       if (canAssign(jobs, k, mid)) {
           answer = mid
           right = mid - 1
       } else {
           left = mid + 1
       }
   }
   ```

2. **Feasibility Check (Backtracking):**
   ```cpp
   canAssign(jobs, k, maxTime):
       workers = array of size k, all 0
       return backtrack(jobs, 0, workers, maxTime)
   
   backtrack(jobs, index, workers, maxTime):
       if (index == jobs.length) return true
       
       for each worker in workers:
           if (worker + jobs[index] <= maxTime) {
               worker += jobs[index]
               if (backtrack(jobs, index+1, workers, maxTime))
                   return true
               worker -= jobs[index]  // backtrack
           }
       
       return false
   ```

### Optimization: Sort Jobs Descending

Assign larger jobs first to prune search space faster.


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

### Time Complexity: **O(k^N × log(sum - max))**

**Why?**
- Binary search: `O(log(sum - max))`
- Each check: `O(k^N)` backtracking (worst case)
- With N ≤ 12, this is manageable

### Space Complexity: **O(N + k)**

**Why?**
- Recursion stack: `O(N)`
- Workers array: `O(k)`

## Edge Cases

1. **k = n (One job per worker):**
   ```
   jobs = [1, 2, 3]
   k = 3
   Answer = 3 (max job)
   ```

2. **k = 1 (One worker does all):**
   ```
   jobs = [1, 2, 3]
   k = 1
   Answer = 6 (sum of all)
   ```

3. **All jobs equal:**
   ```
   jobs = [5, 5, 5, 5]
   k = 2
   Answer = 10
   ```

## Common Mistakes

1. **Treating as contiguous allocation:**
   - ❌ Using greedy allocation like previous problems
   - ✅ Use backtracking for non-contiguous assignment

2. **Not sorting jobs:**
   - ❌ Trying jobs in given order
   - ✅ Sort descending for better pruning

3. **Duplicate work in backtracking:**
   - ❌ Trying same worker states multiple times
   - ✅ Skip duplicate worker loads

## Related Problems

1. **Allocate Minimum Number of Pages** - Contiguous variant
2. **Painter's Partition** - Contiguous variant
3. **Fair Distribution of Cookies** - Similar backtracking

## Key Takeaways

1. **Non-Contiguous:** Jobs can be assigned in any order
2. **Backtracking Required:** Cannot use simple greedy check
3. **Optimization:** Sort jobs descending
4. **Small N:** Constraint N ≤ 12 makes backtracking feasible
5. **Pattern:** Binary search + backtracking for assignment problems

```code```
