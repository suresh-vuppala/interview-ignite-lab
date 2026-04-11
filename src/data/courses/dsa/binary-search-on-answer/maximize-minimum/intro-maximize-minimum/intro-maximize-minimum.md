**Maximize Minimum** is a pattern where we want to maximize the minimum distance, gap, or value between elements.

<br>

## Problem Pattern

Given elements that need to be placed or selected:
- **Goal:** Maximize the minimum distance/gap between selected elements
- **Constraint:** Must select K elements or satisfy placement rules

<br>

## Core Intuition

**Question:** What's the maximum possible value for the minimum distance?

**Answer Space:** The answer lies in a range `[low, high]`
- `low` = minimum possible distance (worst case)
- `high` = maximum possible distance (best case)

**Binary Search:** Try different values of "minimum distance" and check if it's achievable.

<br>

## Template Structure

```cpp
bool canPlace(int minDistance) {
    // Check if we can place K elements
    // with minimum distance = minDistance
    return true/false;
}

int maximizeMinimum() {
    int low = minPossible;
    int high = maxPossible;
    int result = low;
    
    while (low <= high) {
        int mid = low + (high - low) / 2;
        
        if (canPlace(mid)) {
            result = mid;      // mid works, try larger
            low = mid + 1;
        } else {
            high = mid - 1;    // mid too large, decrease
        }
    }
    
    return result;
}
```

<br>

## Key Characteristics

**Search Space:** Distance/gap value (not array indices)

**Monotonic Property:** 
- If distance = X works → distance = X-1 also works
- If distance = X fails → distance = X+1 also fails

**Feasibility Check:** Can we place K elements with this minimum distance?

<br>

## Common Problem Types

### 1. Distance Maximization Problems
- Aggressive cows
- Magnetic force between balls
- Place K elements with maximum minimum distance

**Pattern:** Place K items to maximize the minimum distance between any two items.

### 2. Real-World Examples

**Aggressive Cows:**
- Stalls: `[1, 2, 4, 8, 9]`, Cows: 3
- Maximize minimum distance between any two cows
- Answer: 3 (place at positions 1, 4, 8)

**Magnetic Force:**
- Positions: `[1, 2, 3, 4, 7]`, Balls: 3
- Maximize minimum magnetic force (distance)
- Answer: 3 (place at positions 1, 4, 7)

<br>

## Why Binary Search?

**Brute Force:** Try all possible distances → O(maxDist × n)

**Binary Search:** Try log(maxDist) values → O(n × log(maxDist))

**Example:** For maxDist = 1,000,000
- Brute force: 1,000,000 checks
- Binary search: ~20 checks (log₂(1,000,000) ≈ 20)

<br>

## Greedy Placement Strategy

When checking if distance D is achievable:

```cpp
bool canPlace(vector<int>& positions, int k, int minDist) {
    int count = 1;  // Place first element
    int lastPos = positions[0];
    
    for (int i = 1; i < positions.size(); i++) {
        if (positions[i] - lastPos >= minDist) {
            count++;
            lastPos = positions[i];
            if (count == k) return true;
        }
    }
    
    return count >= k;
}
```

**Strategy:** Greedily place elements as soon as the distance constraint is satisfied.

<br>

## Decision Framework

Use **Maximize Minimum** when:
- ✓ Need to place/select K elements
- ✓ Want to maximize minimum distance/gap
- ✓ Answer has monotonic property
- ✓ Can check feasibility with greedy placement

<br>

## Comparison with Other Patterns

| Pattern | Goal | Example |
|---------|------|---------|
| Minimize Maximum | Minimize the largest value | Book allocation |
| **Maximize Minimum** | Maximize the smallest value | Aggressive cows |
| Capacity/Rate | Find minimum capacity/rate | Ship packages |

<br>
<br>

---

```code```
