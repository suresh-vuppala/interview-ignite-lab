Find the kth largest element in an unsorted array.

<br>

> Input:
> nums = [3,2,1,5,6,4], k = 2

> Output:
> 5

> Explanation:
> Sorted array: [1,2,3,4,5,6]
> 2nd largest element: 5
> 
> Min heap approach (size k=2):
> - Add 3: heap = [3]
> - Add 2: heap = [2,3]
> - Add 1: 1 < 2 (top), skip
> - Add 5: 5 > 2 (top), remove 2, add 5: heap = [3,5]
> - Add 6: 6 > 3 (top), remove 3, add 6: heap = [5,6]
> - Add 4: 4 < 5 (top), skip
> - Result: heap top = 5
> 
> **Key insight:** Min heap of size k keeps k largest, top is kth largest.

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

## Solution: Min Heap of Size K

**Algorithm:**
1. Create min heap of size k
2. For each element:
   - If heap size < k: add element
   - If element > heap top: remove top, add element
3. Return heap top (kth largest)

**Key insight:** Min heap maintains k largest elements, smallest of them is kth largest.



<br>

### Time Complexity Analysis

**Heap Approach: O(n log k)**
- Process n elements: O(n)
- Each heap operation: O(log k)
- Total: O(n log k)

**Why min heap (not max heap)?**
- Min heap of size k: stores k largest elements
- Top = smallest of k largest = kth largest
- Max heap would need to store all elements

**Alternative: QuickSelect**
- Partition-based selection
- Average: O(n)
- Worst: O(n²)
- Best for one-time query

**Alternative: Sorting**
- Sort array: O(n log n)
- Return nums[n-k]
- Simple but slower than heap when k is small

**Space Complexity: O(k)**
- Min heap stores k elements
- Optimal space usage

**When to use each approach:**
- k is small: Heap O(n log k)
- k ≈ n: QuickSelect O(n) average
- Multiple queries: Sort once O(n log n)

**Applications:**
- Top K problems
- Streaming data (find kth largest online)
- Priority queues

> **Time Complexity:** O(n log k) for heap approach
> **Space Complexity:** O(k)

<br>
<br>

---

---

```code```
