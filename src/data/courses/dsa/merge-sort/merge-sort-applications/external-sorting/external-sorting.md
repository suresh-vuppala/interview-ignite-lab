Sort large datasets that don't fit in main memory using external storage (disk).

<br>

> Input:
> Large file with 1TB of data, RAM = 1GB

> Output:
> Sorted file

> Explanation:
> Cannot load entire file into memory
> Use two-phase external merge sort
> 
> **Key insight:** Divide data into chunks that fit in memory, sort chunks, then merge using k-way merge.

<br>

---

## Problem Statement

**Challenge:**
- Data size: Much larger than available RAM
- Example: 1TB file, 1GB RAM
- Cannot use traditional in-memory sorting

**Goal:**
Sort data using limited memory and external storage (disk).

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

## Solution: External Merge Sort

**Intuition:**
Two-phase approach:
1. **Phase 1 (Sorting):** Divide data into chunks that fit in memory, sort each chunk
2. **Phase 2 (Merging):** Merge sorted chunks using k-way merge with min heap

**Algorithm:**

**Phase 1: Create Sorted Runs**
1. Read chunk of data that fits in memory (e.g., 1GB)
2. Sort chunk using in-memory algorithm (quick sort, merge sort)
3. Write sorted chunk to disk as "run"
4. Repeat until all data processed

**Phase 2: K-Way Merge**
1. Open all sorted runs
2. Read first element from each run into min heap
3. Extract minimum from heap, write to output
4. Read next element from same run, add to heap
5. Repeat until all runs exhausted

**Example Walkthrough:**
```
Data: [64, 34, 25, 12, 22, 11, 90, 88, 45, 50, 33, 17]
Memory: Can hold 3 elements

Phase 1: Create Sorted Runs
  Chunk 1: [64, 34, 25] → Sort → [25, 34, 64] → Run 1
  Chunk 2: [12, 22, 11] → Sort → [11, 12, 22] → Run 2
  Chunk 3: [90, 88, 45] → Sort → [45, 88, 90] → Run 3
  Chunk 4: [50, 33, 17] → Sort → [17, 33, 50] → Run 4

Phase 2: K-Way Merge (4 runs)
  Heap: [25(R1), 11(R2), 45(R3), 17(R4)]
  
  Step 1: Extract 11 (R2), add 12 (R2)
    Output: [11]
    Heap: [12(R2), 17(R4), 25(R1), 45(R3)]
  
  Step 2: Extract 12 (R2), add 22 (R2)
    Output: [11, 12]
    Heap: [17(R4), 22(R2), 25(R1), 45(R3)]
  
  Step 3: Extract 17 (R4), add 33 (R4)
    Output: [11, 12, 17]
    Heap: [22(R2), 25(R1), 33(R4), 45(R3)]
  
  Continue until all elements processed...
  
  Final: [11, 12, 17, 22, 25, 33, 34, 45, 50, 64, 88, 90]
```

**K-Way Merge Detail:**
```
Runs:
  R1: [25, 34, 64]
  R2: [11, 12, 22]
  R3: [45, 88, 90]
  R4: [17, 33, 50]

Min Heap (value, run_id, index):
  Initial: [(25,1,0), (11,2,0), (45,3,0), (17,4,0)]
  
Heapify: [11, 17, 25, 45]

Extract 11:
  Output: 11
  Add next from R2: 12
  Heap: [12, 17, 25, 45]

Extract 12:
  Output: 11, 12
  Add next from R2: 22
  Heap: [17, 22, 25, 45]

Extract 17:
  Output: 11, 12, 17
  Add next from R4: 33
  Heap: [22, 25, 33, 45]

Continue...
```

### Time Complexity: O(N log K)
**Why?**
- Phase 1: O(N log M) where M is chunk size
  - Sort each chunk: O(M log M)
  - Number of chunks: N/M
  - Total: (N/M) × O(M log M) = O(N log M)
- Phase 2: O(N log K) where K is number of runs
  - Each element: Extract from heap O(log K)
  - N elements: O(N log K)
- Total: O(N log M + N log K) ≈ O(N log N)

**Detailed breakdown:**
- Heap operations: O(log K) per element
- N elements total: N × O(log K)
- K = N/M (number of runs)
- Total: O(N log(N/M))

### Space Complexity: O(M + K)
**Why?**
- Memory for one chunk: O(M)
- Min heap size: O(K) for K runs
- Buffer for each run: O(K)
- Total: O(M + K)

**Where:**
- M = chunk size (fits in memory)
- K = number of runs = N/M
- N = total data size

<br>

---

## Optimization: Multi-Way Merge

**Problem:**
If K (number of runs) is very large, Phase 2 becomes slow.

**Solution:**
Perform merge in multiple passes:
1. Merge K runs into K/B runs (B = merge factor)
2. Repeat until single sorted file

**Example:**
```
100 runs, B = 10 (10-way merge)

Pass 1: Merge 100 runs → 10 runs
  Merge runs 1-10 → run A
  Merge runs 11-20 → run B
  ...
  Merge runs 91-100 → run J

Pass 2: Merge 10 runs → 1 run
  Merge runs A-J → final sorted file

Total passes: log_B(K) = log_10(100) = 2
```

### Time Complexity: O(N × log_B(K))
**Why?**
- Number of passes: log_B(K)
- Work per pass: O(N)
- Total: O(N × log_B(K))

<br>

---

## Practical Considerations

**1. Buffer Management:**
- Allocate input buffers for each run
- Allocate output buffer for merged data
- Use double buffering for I/O overlap

**2. I/O Optimization:**
- Read/write in large blocks (not single elements)
- Use asynchronous I/O
- Prefetch next block while processing current

**3. Memory Allocation:**
```
Total Memory = M
Input buffers = K × B_in
Output buffer = B_out
Heap = K
Sorting buffer = M - (K × B_in) - B_out - K
```

**4. Choosing K (Number of Runs):**
- Larger chunks → Fewer runs → Faster merge
- But chunks must fit in memory
- Optimal: K = M / B (M = memory, B = block size)

<br>

---

## Real-World Example

**Scenario:**
Sort 1TB file with 1GB RAM

**Phase 1:**
- Chunk size: 1GB
- Number of chunks: 1024
- Sort each 1GB chunk: ~10 seconds
- Total Phase 1: ~3 hours

**Phase 2:**
- 1024-way merge
- Heap size: 1024 elements
- Read buffer per run: 1MB
- Total buffers: 1024MB ≈ 1GB
- Merge time: ~2 hours

**Total:** ~5 hours

**Optimization with 10-way merge:**
- Pass 1: 1024 → 103 runs
- Pass 2: 103 → 11 runs
- Pass 3: 11 → 2 runs
- Pass 4: 2 → 1 run
- Total: ~4 hours (faster due to better I/O)

<br>

---

## Applications

1. **Database Systems:** Sorting large tables that don't fit in memory
2. **Log Processing:** Sorting massive log files
3. **Data Warehousing:** ETL operations on large datasets
4. **MapReduce:** Shuffle phase in distributed computing
5. **File Systems:** Sorting directory entries

<br>

---

## Comparison with In-Memory Sorting

| Aspect | In-Memory | External |
|--------|-----------|----------|
| Data Size | Fits in RAM | Larger than RAM |
| Speed | Fast (ns) | Slow (ms) due to disk I/O |
| Complexity | O(N log N) | O(N log K) |
| Space | O(N) | O(M + K) where M << N |
| Algorithm | Quick/Merge Sort | External Merge Sort |

<br>
<br>

---

```code```
