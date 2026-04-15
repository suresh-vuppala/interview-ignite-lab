**Capacity/Rate Optimization** is a pattern where we find the minimum capacity or rate needed to complete a task within constraints.

<br>

## Problem Pattern

Given a task that needs to be completed:
- **Goal:** Find minimum capacity/rate/speed to finish within time/resource limits
- **Constraint:** Must complete task within D days/hours or with K workers

<br>

## Core Intuition

**Question:** What's the minimum capacity/rate needed?

**Answer Space:** The answer lies in a range `[low, high]`
- `low` = minimum possible capacity (best case)
- `high` = maximum possible capacity (worst case)

**Binary Search:** Try different capacity values and check if task can be completed.

<br>

## Template Structure

```cpp
bool canComplete(int capacity) {
    // Check if we can complete the task
    // with given capacity/rate
    return true/false;
}

int minimizeCapacity() {
    int low = minPossible;
    int high = maxPossible;
    int result = high;
    
    while (low <= high) {
        int mid = low + (high - low) / 2;
        
        if (canComplete(mid)) {
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

**Search Space:** Capacity/rate/speed value (not array indices)

**Monotonic Property:** 
- If capacity = X works → capacity = X+1 also works
- If capacity = X fails → capacity = X-1 also fails

**Feasibility Check:** Can we complete the task with this capacity?

<br>

## Common Problem Types

### 1. Capacity Problems
- Ship packages within D days
- Minimum time to finish jobs

**Pattern:** Find minimum capacity to complete all tasks within time limit.

### 2. Rate/Speed Problems
- Koko eating bananas
- Minimum days to make bouquets
- Minimum speed to arrive on time

**Pattern:** Find minimum rate/speed to finish within deadline.

<br>

## Real-World Examples

**Ship Packages:**
- Weights: `[1, 2, 3, 4, 5, 6, 7, 8, 9, 10]`, Days: 5
- Find minimum ship capacity to ship all within 5 days
- Answer: 15 (can ship all packages in 5 days)

**Koko Eating Bananas:**
- Piles: `[3, 6, 7, 11]`, Hours: 8
- Find minimum eating speed to finish in 8 hours
- Answer: 4 bananas/hour

**Minimum Days for Bouquets:**
- Bloom days: `[1, 10, 3, 10, 2]`, Bouquets: 3, Flowers per bouquet: 1
- Find minimum days to make 3 bouquets
- Answer: 3 days

<br>

## Why Binary Search?

**Brute Force:** Try all possible capacities → O(maxCapacity × n)

**Binary Search:** Try log(maxCapacity) values → O(n × log(maxCapacity))

**Example:** For maxCapacity = 1,000,000
- Brute force: 1,000,000 checks
- Binary search: ~20 checks (log₂(1,000,000) ≈ 20)

<br>

## Simulation Strategy

When checking if capacity C works:

```cpp
bool canShip(vector<int>& weights, int days, int capacity) {
    int daysNeeded = 1;
    int currentLoad = 0;
    
    for (int weight : weights) {
        if (currentLoad + weight > capacity) {
            daysNeeded++;
            currentLoad = weight;
        } else {
            currentLoad += weight;
        }
    }
    
    return daysNeeded <= days;
}
```

**Strategy:** Simulate the process and count resources needed.

<br>

## Decision Framework

Use **Capacity/Rate Optimization** when:
- ✓ Need to find minimum capacity/rate/speed
- ✓ Must complete task within time/resource limit
- ✓ Answer has monotonic property
- ✓ Can simulate and check feasibility

<br>

## Comparison with Other Patterns

| Pattern | Goal | Example |
|---------|------|---------|
| Minimize Maximum | Minimize the largest value | Book allocation |
| Maximize Minimum | Maximize the smallest value | Aggressive cows |
| **Capacity/Rate** | Find minimum capacity/rate | Ship packages |

<br>

## Key Differences

**Minimize Maximum vs Capacity/Rate:**
- Minimize Maximum: Partition items, minimize max partition sum
- Capacity/Rate: Find minimum resource to complete task

**Example:**
- Minimize Maximum: Split `[1,2,3,4]` into 2 groups → minimize max sum
- Capacity/Rate: Ship `[1,2,3,4]` in 2 days → find min capacity

<br>
<br>

---

```code```


## All Possible Edge Cases
1. **N/A — pattern overview**
