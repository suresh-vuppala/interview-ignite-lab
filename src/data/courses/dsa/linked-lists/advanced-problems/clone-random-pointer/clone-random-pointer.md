## Overview
Create a deep copy of a linked list where each node has a next and random pointer.

## Topics Covered
1. **Interweaving Technique**: Insert copies between original nodes
2. **Copy Random Pointers**: Use interweaved structure to set random
3. **Separate Lists**: Extract the copied list
4. **HashMap Alternative**: Map original to copy nodes

## Problem Statement
Given a linked list where each node has:
- `next`: Points to next node
- `random`: Points to any node or null

Create a deep copy of the list.


---

## Constraints

- `0 ≤ n ≤ 1000`
- `-10⁴ ≤ Node.val ≤ 10⁴`

<br>

---

## All Possible Edge Cases

1. **Empty list:** Return null
2. **All random = null:** Simple copy
3. **Random points to self:** Must handle self-reference in clone
4. **Random points to next node:** Straightforward mapping
5. **Interleaving technique:** O(1) space solution weaves cloned nodes

<br>

## Approach

### Method 1: Interweaving (O(1) space)
1. Insert copy nodes: A->A'->B->B'->C->C'
2. Set random pointers: A'.random = A.random.next
3. Separate lists: Extract A'->B'->C'
- Time: O(n), Space: O(1)

### Method 2: HashMap (O(n) space)
1. First pass: Create all nodes, map original to copy
2. Second pass: Set next and random using map
- Time: O(n), Space: O(n)

## Complexity Analysis

### Time Complexity: O(n)
### Space Complexity: O(1) interweaving, O(n) hashmap

## Code

```code```
