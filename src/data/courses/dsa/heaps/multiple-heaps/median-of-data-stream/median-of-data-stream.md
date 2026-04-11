Design a data structure that supports adding integers and finding the median of all elements added so far.

<br>

> Input:
> Operations: ["addNum", 1], ["addNum", 2], ["findMedian"], ["addNum", 3], ["findMedian"]

> Output:
> [null, null, 1.5, null, 2.0]

> Explanation:
> Two heap process:
> - addNum(1): maxHeap=[1], minHeap=[], median=1
> - addNum(2): maxHeap=[1], minHeap=[2], median=(1+2)/2=1.5
> - findMedian(): return 1.5
> - addNum(3): maxHeap=[1], minHeap=[2,3], rebalance → maxHeap=[1,2], minHeap=[3], median=2
> - findMedian(): return 2.0
> 
> Heap structure after each operation:
> - After 1: maxHeap(lower half)=[1], minHeap(upper half)=[]
> - After 2: maxHeap=[1], minHeap=[2] (balanced)
> - After 3: maxHeap=[1,2], minHeap=[3] (maxHeap has 1 more)

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

## Solution: Two Heaps (Max Heap + Min Heap)

Use two heaps to maintain median efficiently:
1. **Max heap** (lower half): Stores smaller half of numbers
2. **Min heap** (upper half): Stores larger half of numbers
3. **Invariant**: 
   - maxHeap.size() = minHeap.size() OR maxHeap.size() = minHeap.size() + 1
   - All elements in maxHeap ≤ all elements in minHeap
4. **Median**:
   - If sizes equal: (maxHeap.top() + minHeap.top()) / 2
   - If maxHeap larger: maxHeap.top()

**Key insight:** Median is at boundary between two halves; heaps maintain this boundary.

```code```

<br>

### Time Complexity Analysis

**addNum: O(log n)**
- Insert into heap: O(log n)
- Rebalance (if needed):
  - Remove from one heap: O(log n)
  - Insert into other heap: O(log n)
- Total: O(log n) + O(log n) = O(log n)

**findMedian: O(1)**
- Access heap tops: O(1) for both heaps
- Calculate average: O(1)
- Total: O(1)

**Why two heaps?**
- Single sorted array: addNum O(n), findMedian O(1)
- Single heap: Can't efficiently find median
- Two heaps: addNum O(log n), findMedian O(1) - optimal!

**Space Complexity: O(n)**
- Both heaps together store n elements
- maxHeap: ~n/2 elements
- minHeap: ~n/2 elements
- Total: O(n)

**Balancing strategy:**
- Always add to maxHeap first
- If maxHeap.top() > minHeap.top(), swap tops
- If size difference > 1, rebalance
- Maintains invariant: maxHeap.size() ∈ {minHeap.size(), minHeap.size()+1}

**Why this works:**
- Median is middle element(s)
- Two heaps split data at median
- Max heap top = largest of lower half
- Min heap top = smallest of upper half
- Median is between these two values

**Comparison with alternatives:**
- Sorted array: O(n) insert, O(1) median - too slow for inserts
- BST: O(log n) insert, O(n) median - need to traverse
- Two heaps: O(log n) insert, O(1) median - optimal!

> **Time Complexity:** 
> - addNum: O(log n) - heap insert and rebalance
> - findMedian: O(1) - access heap tops
> 
> **Space Complexity:** O(n) - two heaps store all n elements

<br>
<br>

---
