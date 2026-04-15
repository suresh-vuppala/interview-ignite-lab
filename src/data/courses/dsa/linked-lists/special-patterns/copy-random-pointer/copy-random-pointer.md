Deep copy a linked list where each node has a next pointer and a random pointer to any node in the list.

<br>

> Input: list with random pointers
> Output: deep copy with correct random pointers
> **Key insight:** Three-pass O(1) space: 1) Interleave clones (A→A'→B→B'→...) 2) Set random pointers (clone.random = original.random.next) 3) Separate original and clone lists.

<br>

---

## Constraints
- `0 ≤ N ≤ 1000`

<br>

---

## All Possible Edge Cases
1. **Empty list**
2. **Random points to self**
3. **Random is null**
4. **All randoms point to head**

<br>

---

## Solution 1: Hash Map — O(N) space

**Intuition:**
The most straightforward approach — try all possibilities and check each one.

**Algorithm:**
1. Initialize a hash set/map for tracking
2. Iterate through each element
3. Check against the hash set/map for the required condition
4. Update the hash set/map with the current element

### Time Complexity: O(N²)
**Why?**
Two nested loops each running up to N iterations.
Outer loop: N iterations × Inner loop: up to N iterations = N² total operations.

**Detailed breakdown:**
For N=1,000: ~1 million operations (OK). For N=10,000: ~100 million (borderline TLE).

### Space Complexity: O(1) extra (or O(N) if using auxiliary structures)
**Why?**
Depends on whether auxiliary data structures are used. Pure brute force typically uses O(1) extra space beyond the input.

> **Drawback:**
> Suboptimal time complexity for large inputs. Redundant work is performed.

> **Key Insight for Improvement:**
> Use a more efficient data structure or algorithm to reduce redundant computation.

<br>

---

## Solution 2: Interleave Clones (Optimal space)

### Time Complexity: O(N)
### Space Complexity: O(1) extra (output doesn't count)

> **Drawback:** Modifies original list temporarily (must restore).

> **Key Insight for Improvement:** Three passes: create interleaved → set random → separate lists. Each pass is O(N).

<br>

---

**Key Insights:**
1. **Interleave trick:** Place clone right after its original → clone.random = original.random.next
2. **Must restore original:** Separate the two lists in pass 3
3. **FAANG classic:** Tests pointer manipulation skill

<br><br>

---

```code```
