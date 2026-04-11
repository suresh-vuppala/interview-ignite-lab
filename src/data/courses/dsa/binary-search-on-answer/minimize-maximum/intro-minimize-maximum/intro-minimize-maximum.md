**Minimize Maximum** is a pattern where we want to minimize the maximum value across partitions, allocations, or groups.

<br>

## Problem Pattern

Given a resource that needs to be divided or allocated:
- **Goal:** Minimize the maximum load/sum/value in any partition
- **Constraint:** Must satisfy certain conditions (number of partitions, capacity limits, etc.)

<br>

## Core Intuition

**Question:** What's the minimum possible value for the maximum?

**Answer Space:** The answer lies in a range `[low, high]`
- `low` = minimum possible maximum (best case)
- `high` = maximum possible maximum (worst case)

**Binary Search:** Try different values of "maximum allowed" and check if it's feasible.

<br>

## Template Structure

```cpp
bool canAllocate(int maxAllowed) {
    // Check if we can satisfy constraints
    // with maximum value = maxAllowed
    return true/false;
}

int minimizeMaximum() {
    int low = minPossible;
    int high = maxPossible;
    int result = high;
    
    while (low <= high) {
        int mid = low + (high - low) / 2;
        
        if (canAllocate(mid)) {
            result = mid;      // mid works, try smaller
            high = mid - 1;
        } else {
            low = mid + 1;     // mid too small, increase
        }
    }
    
    return result;
}
```

<br>

## Key Characteristics

**Search Space:** Answer value (not array indices)

**Monotonic Property:** 
- If maximum = X works → maximum = X+1 also works
- If maximum = X fails → maximum = X-1 also fails

**Feasibility Check:** Can we achieve the task with this maximum limit?

<br>

## Common Problem Types

### 1. Partition/Allocation Problems
- Allocate books to students
- Painter's partition
- Split array into subarrays
- Minimize maximum balls in bag

**Pattern:** Divide items into K groups, minimize the maximum sum in any group.

### 2. Real-World Examples

**Book Allocation:**
- Books: `[10, 20, 30, 40]`, Students: 2
- Minimize maximum pages any student reads
- Answer: 60 (split as `[10,20,30]` and `[40]`)

**Painter's Partition:**
- Boards: `[10, 20, 30, 40]`, Painters: 2
- Minimize maximum time any painter works
- Answer: 60 (split as `[10,20,30]` and `[40]`)

<br>

## Why Binary Search?

**Brute Force:** Try all possible maximum values → O(sum × n)

**Binary Search:** Try log(sum) values → O(n × log(sum))

**Example:** For sum = 1,000,000
- Brute force: 1,000,000 checks
- Binary search: ~20 checks (log₂(1,000,000) ≈ 20)

<br>

## Decision Framework

Use **Minimize Maximum** when:
- ✓ Need to partition/allocate resources
- ✓ Want to minimize the maximum load
- ✓ Answer has monotonic property
- ✓ Can check feasibility in O(n) or O(n log n)

<br>

## Comparison with Other Patterns

| Pattern | Goal | Example |
|---------|------|---------|
| **Minimize Maximum** | Minimize the largest value | Book allocation |
| Maximize Minimum | Maximize the smallest value | Aggressive cows |
| Capacity/Rate | Find minimum capacity/rate | Ship packages |

<br>
<br>

---

```code```
