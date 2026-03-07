Merge two sorted linked lists into one sorted linked list.

<br>

> Input:
> l1 = [1 → 2 → 4], l2 = [1 → 3 → 4]

> Output:
> [1 → 1 → 2 → 3 → 4 → 4]

> Explanation:
> Compare nodes from both lists one by one
> Pick smaller node and advance that pointer
> 
> **Key insight:** Use dummy node to simplify edge cases, merge in O(N+M) time with O(1) space.

<br>

---

## Solution 1: Recursive Approach

**Intuition:**
At each step, pick the smaller head node.
Recursively merge the rest.

**Algorithm:**
1. Base cases:
   - If l1 is null, return l2
   - If l2 is null, return l1
2. Compare l1.val and l2.val:
   - If l1.val <= l2.val:
     - l1.next = merge(l1.next, l2)
     - return l1
   - Else:
     - l2.next = merge(l1, l2.next)
     - return l2

**Example:**
```
l1 = [1 → 2 → 4]
l2 = [1 → 3 → 4]

merge(l1, l2):
  1 <= 1, pick l1
  l1.next = merge([2 → 4], [1 → 3 → 4])
    2 > 1, pick l2
    l2.next = merge([2 → 4], [3 → 4])
      2 < 3, pick l1
      l1.next = merge([4], [3 → 4])
        4 > 3, pick l2
        l2.next = merge([4], [4])
          4 <= 4, pick l1
          l1.next = merge(null, [4])
            return [4]
          return [4 → 4]
        return [3 → 4 → 4]
      return [2 → 3 → 4 → 4]
    return [1 → 2 → 3 → 4 → 4]
  return [1 → 1 → 2 → 3 → 4 → 4]

Result: [1 → 1 → 2 → 3 → 4 → 4]
```

### Time Complexity: O(N + M)
**Why?**
- Visit each node exactly once
- N nodes in l1, M nodes in l2
- Total: O(N + M)

### Space Complexity: O(N + M)
**Why?**
- Recursion stack depth: O(N + M)
- Each recursive call adds to stack
- Total: O(N + M)

**Problem:** Uses O(N + M) stack space.

> **Key Insight for Improvement:**
> Can we do this iteratively to avoid recursion stack? Yes - use dummy node and two pointers!

<br>

---

## Solution 2: Iterative with Dummy Node (Optimal)

**Intuition:**
Use dummy node to avoid null checks.
Use two pointers to traverse both lists.
Always pick smaller node and advance that pointer.

**Algorithm:**
1. Create dummy node (simplifies edge cases)
2. Initialize curr pointer to dummy
3. While both l1 and l2 exist:
   - If l1.val <= l2.val:
     - curr.next = l1
     - l1 = l1.next
   - Else:
     - curr.next = l2
     - l2 = l2.next
   - curr = curr.next
4. Attach remaining nodes (one list exhausted)
5. Return dummy.next

**Example Walkthrough:**
```
l1 = [1 → 2 → 4]
l2 = [1 → 3 → 4]

dummy = [0]
curr = dummy

Step 1: Compare 1 and 1
  1 <= 1, pick l1
  curr.next = l1 (1)
  l1 = l1.next (2)
  curr = curr.next (1)
  Result: [0 → 1]

Step 2: Compare 2 and 1
  2 > 1, pick l2
  curr.next = l2 (1)
  l2 = l2.next (3)
  curr = curr.next (1)
  Result: [0 → 1 → 1]

Step 3: Compare 2 and 3
  2 < 3, pick l1
  curr.next = l1 (2)
  l1 = l1.next (4)
  curr = curr.next (2)
  Result: [0 → 1 → 1 → 2]

Step 4: Compare 4 and 3
  4 > 3, pick l2
  curr.next = l2 (3)
  l2 = l2.next (4)
  curr = curr.next (3)
  Result: [0 → 1 → 1 → 2 → 3]

Step 5: Compare 4 and 4
  4 <= 4, pick l1
  curr.next = l1 (4)
  l1 = l1.next (null)
  curr = curr.next (4)
  Result: [0 → 1 → 1 → 2 → 3 → 4]

Step 6: l1 is null
  Attach remaining l2
  curr.next = l2 (4)
  Result: [0 → 1 → 1 → 2 → 3 → 4 → 4]

Return dummy.next: [1 → 1 → 2 → 3 → 4 → 4]
```

**Pointer Movement Visualization:**
```
Initial:
  l1: 1 → 2 → 4
  l2: 1 → 3 → 4
  dummy: 0
  curr: 0

After Step 1:
  l1: 2 → 4
  l2: 1 → 3 → 4
  dummy: 0 → 1
  curr: 1

After Step 2:
  l1: 2 → 4
  l2: 3 → 4
  dummy: 0 → 1 → 1
  curr: 1

After Step 3:
  l1: 4
  l2: 3 → 4
  dummy: 0 → 1 → 1 → 2
  curr: 2

After Step 4:
  l1: 4
  l2: 4
  dummy: 0 → 1 → 1 → 2 → 3
  curr: 3

After Step 5:
  l1: null
  l2: 4
  dummy: 0 → 1 → 1 → 2 → 3 → 4
  curr: 4

After Step 6:
  dummy: 0 → 1 → 1 → 2 → 3 → 4 → 4
```

### Time Complexity: O(N + M)
**Why?**
- Visit each node exactly once
- N nodes in l1, M nodes in l2
- Total: O(N + M)

**Detailed breakdown:**
- While loop: Runs min(N, M) times
- Attach remaining: O(1) pointer assignment
- Total: O(N + M)

### Space Complexity: O(1)
**Why?**
- Only use constant extra space
- Dummy node: O(1)
- Pointers (curr, l1, l2): O(1)
- No recursion stack
- Total: O(1)

**Improvement:** From O(N + M) space to O(1) space
- Iterative approach eliminates recursion stack
- Only pointer manipulation needed

<br>

---

## Why Dummy Node?

**Without Dummy Node:**
```cpp
if (!l1) return l2;
if (!l2) return l1;

ListNode* head = nullptr;
ListNode* curr = nullptr;

// Need special handling for first node
if (l1.val <= l2.val) {
    head = l1;
    curr = l1;
    l1 = l1.next;
} else {
    head = l2;
    curr = l2;
    l2 = l2.next;
}

// Then continue with loop
while (l1 && l2) {
    // ... merge logic
}
```

**With Dummy Node:**
```cpp
ListNode dummy(0);
ListNode* curr = &dummy;

// No special case needed!
while (l1 && l2) {
    if (l1.val <= l2.val) {
        curr.next = l1;
        l1 = l1.next;
    } else {
        curr.next = l2;
        l2 = l2.next;
    }
    curr = curr.next;
}

curr.next = l1 ? l1 : l2;
return dummy.next;
```

**Advantages:**
1. Eliminates special case for first node
2. Cleaner, more readable code
3. Fewer edge cases to handle
4. Same time/space complexity

<br>

---

## Edge Cases

1. **Both lists empty:** Return null
2. **One list empty:** Return the other list
3. **Lists of different lengths:** Attach remaining nodes
4. **All elements equal:** Merge maintains order
5. **One element each:** Compare and link

**Examples:**
```
l1 = [], l2 = [1] → Result: [1]
l1 = [1], l2 = [] → Result: [1]
l1 = [1, 2], l2 = [3, 4, 5] → Result: [1, 2, 3, 4, 5]
l1 = [1, 1, 1], l2 = [1, 1, 1] → Result: [1, 1, 1, 1, 1, 1]
```

<br>

---

## Key Techniques

**1. Dummy Node Pattern:**
- Simplifies edge cases
- Avoids null checks for head
- Common in linked list problems

**2. Two Pointer Technique:**
- One pointer for each list
- Advance pointer of smaller element
- Efficient O(N + M) traversal

**3. Remaining Nodes:**
- After loop, one list exhausted
- Other list already sorted
- Just attach remaining nodes: O(1)

<br>

---

## Applications

1. **Merge Sort:** Foundation of merge operation
2. **Merge K Sorted Lists:** Extended version with heap
3. **Database Joins:** Merge sorted result sets
4. **External Sorting:** Merge sorted runs from disk
5. **Priority Queues:** Merge sorted sequences

<br>
<br>

---

```code```
