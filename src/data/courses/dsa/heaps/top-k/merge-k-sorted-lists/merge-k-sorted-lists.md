Merge k sorted linked lists into one sorted linked list.

<br>

> Input:
> lists = [[1,4,5], [1,3,4], [2,6]]

> Output:
> [1,1,2,3,4,4,5,6]

> Explanation:
> Merging process using min heap:
> - Initial: Add first node from each list to heap: [1,1,2]
> - Extract 1 (list 0), add 4: heap = [1,2,4]
> - Extract 1 (list 1), add 3: heap = [2,3,4]
> - Extract 2 (list 2), add 6: heap = [3,4,6]
> - Extract 3, add 4: heap = [4,4,6]
> - Extract 4, add 5: heap = [4,5,6]
> - Extract remaining: 4, 5, 6
> 
> **Key insight:** Min heap always gives smallest among k list heads.

<br>


---

## Constraints

- `1 ≤ n ≤ 10⁵`
- `-10⁴ ≤ nums[i] ≤ 10⁴`

<br>

---

## All Possible Edge Cases

1. **Single element:** It is both min and max
2. **All same elements:** Heap operations trivial
3. **Already a valid heap:** No restructuring needed
4. **k = 1:** Find min/max directly
5. **k = n:** Need to process entire heap
6. **Negative values:** Min heap with negatives

<br>

---

## Solution: Min Heap with K Pointers

**Algorithm:**
1. Create min heap with first node from each list
2. While heap not empty:
   - Extract minimum node
   - Add to result list
   - If extracted node has next, add next to heap
3. Return merged list

**Key insight:** Heap maintains smallest element across all k lists efficiently.

```code```

<br>

### Time Complexity Analysis

**Overall: O(N log k)**
- N = total number of nodes across all lists
- k = number of lists

**Build Initial Heap: O(k log k)**
- Insert k nodes (one from each list)
- Each insertion: O(log k)

**Process All Nodes: O(N log k)**
- Extract min: O(log k)
- Insert next node: O(log k)
- Total operations: N
- Total: N × O(log k)

**Why not merge two at a time?**
- Merge 2 lists: O(n₁ + n₂)
- Merge k lists sequentially: O(k×N) = O(kN)
- Heap approach: O(N log k)
- When k is large, O(N log k) << O(kN)

**Space Complexity: O(k)**
- Heap stores at most k nodes
- Result list: O(N) but required for output
- Auxiliary space: O(k)

**Alternative: Divide and Conquer**
- Merge pairs recursively
- Time: O(N log k)
- Space: O(log k) recursion stack
- Similar complexity but heap is simpler

**Applications:**
- External sorting (merge sorted files)
- Database query optimization
- Distributed system data merging

> **Time Complexity:** O(N log k) where N = total nodes, k = lists
> **Space Complexity:** O(k) for heap

<br>
<br>

---
