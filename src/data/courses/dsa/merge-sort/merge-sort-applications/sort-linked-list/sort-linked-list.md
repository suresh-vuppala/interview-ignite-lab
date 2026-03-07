Sort a linked list in ascending order using O(N log N) time complexity.

<br>

> Input:
> head = [4 → 2 → 1 → 3]

> Output:
> [1 → 2 → 3 → 4]

> Explanation:
> Apply merge sort on linked list
> Split using slow/fast pointers, recursively sort, merge
> 
> **Key insight:** Merge sort is ideal for linked lists - no random access needed, O(1) space for splitting.

<br>

---

## Solution 1: Convert to Array, Sort, Rebuild

**Intuition:**
Convert linked list to array, sort array, rebuild linked list.

**Algorithm:**
1. Traverse linked list and store values in array
2. Sort array using any O(N log N) algorithm
3. Create new linked list from sorted array

**Example:**
```
List: 4 → 2 → 1 → 3

Step 1: Extract to array [4, 2, 1, 3]
Step 2: Sort array [1, 2, 3, 4]
Step 3: Build list 1 → 2 → 3 → 4
```

### Time Complexity: O(N log N)
**Why?**
- Extract to array: O(N)
- Sort array: O(N log N)
- Build list: O(N)
- Total: O(N log N)

### Space Complexity: O(N)
**Why?**
- Array storage: O(N)
- New list: O(N)
- Total: O(N)

**Problem:** Uses extra O(N) space unnecessarily.

> **Key Insight for Improvement:**
> Merge sort works perfectly on linked lists without extra space! We can split in O(1) space using slow/fast pointers.

<br>

---

## Solution 2: Merge Sort on Linked List (Optimal)

**Intuition:**
Apply merge sort directly on linked list.
Use slow/fast pointer technique to find middle.
Recursively sort left and right halves.
Merge two sorted lists.

**Algorithm:**
1. **Base case:** If list has 0 or 1 node, return head
2. **Find middle:** Use slow/fast pointers
   - Slow moves 1 step, fast moves 2 steps
   - When fast reaches end, slow is at middle
3. **Split:** Break list at middle
4. **Recursively sort:** Left half and right half
5. **Merge:** Combine two sorted lists

**Example Walkthrough:**
```
List: 4 → 2 → 1 → 3

Step 1: Find middle using slow/fast
  slow=4, fast=4: slow→2, fast→1
  slow=2, fast=1: slow→1, fast→3
  slow=1, fast=3: slow→3, fast=null
  Middle = 1, Split at 2

Split: [4 → 2] and [1 → 3]

Left [4 → 2]:
  Find middle: 4
  Split: [4] and [2]
  Merge: 2 → 4

Right [1 → 3]:
  Find middle: 1
  Split: [1] and [3]
  Merge: 1 → 3

Final Merge [2 → 4] and [1 → 3]:
  Compare 2 and 1: pick 1 → 1
  Compare 2 and 3: pick 2 → 1 → 2
  Compare 4 and 3: pick 3 → 1 → 2 → 3
  Remaining: 4 → 1 → 2 → 3 → 4
```

**Finding Middle Detail:**
```
List: 4 → 2 → 1 → 3 → null

slow = head, fast = head
prev = null (to break link)

Iteration 1:
  prev = slow (4)
  slow = slow.next (2)
  fast = fast.next.next (1)

Iteration 2:
  prev = slow (2)
  slow = slow.next (1)
  fast = fast.next.next (3)

Iteration 3:
  prev = slow (1)
  slow = slow.next (3)
  fast = fast.next.next (null)

Break: prev.next = null
Left: 4 → 2 → 1 → null
Right: 3 → null
```

**Merge Two Sorted Lists:**
```cpp
dummy = new Node(0)
curr = dummy

while (l1 and l2):
    if l1.val <= l2.val:
        curr.next = l1
        l1 = l1.next
    else:
        curr.next = l2
        l2 = l2.next
    curr = curr.next

curr.next = l1 if l1 else l2
return dummy.next
```

### Time Complexity: O(N log N)
**Why?**
- Divide: O(log N) levels (splitting in half)
- Find middle at each level: O(N) total work
- Merge at each level: O(N) work
- Total: O(N log N)

**Detailed breakdown:**
- Level 0: 1 list of size N → O(N) to find middle + merge
- Level 1: 2 lists of size N/2 → O(N) total
- Level 2: 4 lists of size N/4 → O(N) total
- ...
- log N levels × O(N) work = O(N log N)

### Space Complexity: O(log N)
**Why?**
- Recursion stack: O(log N) depth
- No extra arrays needed
- In-place pointer manipulation

**Improvement:** From O(N) space to O(log N) space
- No auxiliary array needed
- Only recursion stack space

<br>

---

## Why Merge Sort for Linked Lists?

**Advantages:**
1. **No random access needed:** Merge sort only needs sequential access
2. **O(1) split:** Just break the link at middle
3. **O(1) merge:** Just adjust pointers
4. **Stable:** Preserves relative order of equal elements

**Why not Quick Sort?**
- Quick sort needs random access for partitioning
- Finding pivot in linked list is O(N)
- Partitioning is inefficient without random access

**Why not Heap Sort?**
- Heap operations need random access
- Building heap from linked list is inefficient

<br>

---

## Key Techniques

**1. Finding Middle (Slow/Fast Pointer):**
```cpp
slow = head, fast = head, prev = null
while (fast and fast.next):
    prev = slow
    slow = slow.next
    fast = fast.next.next
// slow is at middle
// prev.next = null to split
```

**2. Merging Two Sorted Lists:**
```cpp
dummy = new Node(0)
curr = dummy
while (l1 and l2):
    if l1.val <= l2.val:
        curr.next = l1
        l1 = l1.next
    else:
        curr.next = l2
        l2 = l2.next
    curr = curr.next
curr.next = l1 ? l1 : l2
return dummy.next
```

<br>

---

## Edge Cases

1. **Empty list:** Return null
2. **Single node:** Return head (already sorted)
3. **Two nodes:** Compare and swap if needed
4. **All equal values:** Return as is
5. **Already sorted:** Still O(N log N) but no swaps needed

<br>

---

## Applications

1. **Database Systems:** Sort query results stored as linked lists
2. **Memory-Constrained Systems:** When extra array space not available
3. **Stable Sorting:** When order of equal elements matters
4. **External Sorting:** Sorting data on disk (sequential access)
5. **Merge K Sorted Lists:** Foundation for merging multiple lists

<br>
<br>

---

```code```
