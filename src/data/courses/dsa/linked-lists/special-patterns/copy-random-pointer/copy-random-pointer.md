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

## Solution 1: Hash Map — O(N) space

> **Drawback:** O(N) extra space for the map.

> **Key Insight for Improvement:** Interleave clones between originals. Clone's random = original.random.next (the clone of original.random). O(1) extra space.

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
