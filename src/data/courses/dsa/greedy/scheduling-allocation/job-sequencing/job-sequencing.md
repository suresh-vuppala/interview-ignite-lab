Given an array of jobs where each job has a deadline and profit, schedule jobs to maximize total profit. Each job takes 1 unit of time and only one job can be scheduled at a time.

<br>

> Input:
> jobs = [{id: 'a', deadline: 2, profit: 100},
>         {id: 'b', deadline: 1, profit: 19},
>         {id: 'c', deadline: 2, profit: 27},
>         {id: 'd', deadline: 1, profit: 25},
>         {id: 'e', deadline: 3, profit: 15}]

> Output:
> Maximum Profit: 142
> Jobs: ['a', 'c', 'e']

> Explanation:
> After sorting by profit (descending): [a(100), c(27), d(25), b(19), e(15)]
> 
> Scheduling process (slots: [_, _, _]):
> 1. Job 'a' (deadline=2, profit=100): Schedule at slot 1 → [_, a, _]
> 2. Job 'c' (deadline=2, profit=27): Slot 1 taken, schedule at slot 0 → [c, a, _]
> 3. Job 'd' (deadline=1, profit=25): Slot 0 taken, skip
> 4. Job 'b' (deadline=1, profit=19): Slot 0 taken, skip
> 5. Job 'e' (deadline=3, profit=15): Schedule at slot 2 → [c, a, e]
> 
> Total profit: 27 + 100 + 15 = 142

<br>

---

## Solution: Greedy Job Scheduling

Approach:
1. Sort jobs by profit in descending order
2. Create slots array for scheduling
3. For each job, find latest available slot before its deadline
4. Schedule job in that slot if available

**Greedy choice:** Always pick highest profit job that can still meet its deadline.

```code```

<br>

### Time Complexity Analysis

**Sorting Phase: O(n log n)**
- Sort n jobs by profit in descending order
- Comparison-based sorting

**Scheduling Phase: O(n × m)**
- For each of n jobs:
  - Find latest available slot: O(m) where m = max deadline
  - In worst case, check all slots from deadline to 0
- Total: n × m

**Overall: O(n log n + n × m)**
- If m is small (constant), effectively O(n log n)
- If m is large (proportional to n), becomes O(n²)

**Optimization possible:**
- Using Union-Find (Disjoint Set): O(n log n + n × α(n)) where α is inverse Ackermann
- Practically O(n log n) with Union-Find

> **Time Complexity:** O(n²) worst case, O(n log n) with optimization
> **Space Complexity:** O(m) - for slots array where m = max deadline

<br>
<br>

---