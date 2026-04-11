Given an array of tasks and a cooling interval n, find the minimum time needed to execute all tasks. Same task must wait n intervals before executing again.

<br>

> Input:
> tasks = ['A', 'A', 'A', 'B', 'B', 'B'], n = 2

> Output:
> 8

> Explanation:
> Task frequencies: A=3, B=3
> Most frequent task: A (or B), frequency = 3
> 
> Optimal schedule:
> A → B → idle → A → B → idle → A → B
> 
> Calculation:
> - Frames needed: (maxFreq - 1) = 3 - 1 = 2
> - Frame size: (n + 1) = 2 + 1 = 3
> - Base time: 2 × 3 = 6
> - Tasks with max frequency: 2 (A and B)
> - Total time: 6 + 2 = 8

<br>


---

## Constraints

- `1 ≤ tasks.length ≤ 10⁴`
- `0 ≤ n ≤ 100`
- `tasks[i] is uppercase English letter`

<br>

---

## All Possible Edge Cases

1. **n = 0:** No cooldown — total time = tasks.length
2. **All same task:** 'AAAA' n=2 → A_A_A_A → needs idle slots
3. **All unique tasks:** No idle time needed if enough variety
4. **Single task:** Time = 1
5. **Two tasks same, n=1:** 'AA' n=1 → A_A → 3
6. **Many distinct tasks:** Cooldown easily filled by other tasks

<br>

---

## Solution: Greedy Frequency-Based Scheduling

Approach:
1. Count frequency of each task
2. Find maximum frequency
3. Calculate idle slots: (maxFreq - 1) × n
4. Fill idle slots with remaining tasks
5. Return max(total tasks, calculated time)

**Formula:** max(tasks.length, (maxFreq - 1) × (n + 1) + countOfMaxFreqTasks)



<br>

### Time Complexity Analysis

**Frequency Counting: O(n)**
- Traverse all n tasks once
- Count frequency in hash map: O(1) per task
- Total: O(n)

**Finding Max Frequency: O(26) = O(1)**
- At most 26 different tasks (A-Z)
- Iterate through frequency map: O(26) = constant

**Calculation: O(1)**
- Simple arithmetic operations
- No loops or recursion

**Overall: O(n)**
- Linear in number of tasks
- Constant space for frequency map (max 26 entries)

**Why this works:**
- Most frequent task determines minimum frames needed
- Other tasks fill idle slots between most frequent task
- If no idle slots remain, answer is simply total tasks

> **Time Complexity:** O(n) - single pass through tasks
> **Space Complexity:** O(1) - frequency map has at most 26 entries (constant)

<br>
<br>

---

---

```code```
