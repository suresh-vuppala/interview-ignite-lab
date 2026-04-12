Flatten a multilevel doubly linked list. Nodes may have a child pointer to another doubly linked list.

<br>

> Input: 1↔2↔3↔4↔5↔6 with 3.child = 7↔8↔9↔10 and 8.child = 11↔12
> Output: 1↔2↔3↔7↔8↔11↔12↔9↔10↔4↔5↔6
> **Key insight:** DFS: when a child exists, insert the child list between current and next. Find the tail of the child list, connect it to current.next.

<br>

---

## Constraints
- `0 ≤ N ≤ 1000`

<br>

---

## Solution: Iterative DFS (Optimal)

**Algorithm:** For each node with a child: find tail of child list, connect tail.next = curr.next, curr.next.prev = tail (if exists), curr.next = child, child.prev = curr, child = null.

### Time Complexity: O(N)
### Space Complexity: O(1)

> **Drawback:** None.

> **Key Insight for Improvement:** Process children immediately when encountered — like DFS. Each node visited at most twice (once to find, once when it's part of main chain).

<br>

---

**Key Insights:**
1. **DFS order:** Children inserted before siblings (like preorder)
2. **Find child tail:** Traverse to end of child list before connecting
3. **Set child to null:** After flattening, clear the child pointer

<br><br>

---

```code```
