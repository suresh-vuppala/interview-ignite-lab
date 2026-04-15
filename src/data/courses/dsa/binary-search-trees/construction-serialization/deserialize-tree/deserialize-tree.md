Deserialize a string back to a binary tree.

<br>

> Input: "1,2,3,null,null,4,5"
> Output: tree [1,2,3,null,null,4,5]
> **Key insight:** Reverse of serialization. BFS: parse values, use queue of parents. Each parent gets next two values as children.

<br>

---

## Constraints
- `0 ≤ N ≤ 10⁴`

<br>

---

## All Possible Edge Cases
1. **Empty/null input**
2. **Malformed input string**
3. **Very deep tree (stack depth)**

<br>

---

## Solution 1: Parse preorder string recursively

**Intuition:**
The most straightforward approach — both approaches work.

**Algorithm:**
1. Apply the naive/brute approach as described
2. Check all possibilities or use a simpler data structure
3. Return the result

### Time Complexity: O(N)
**Why?**
The brute approach doesn't exploit the problem's structure efficiently, leading to redundant work.

**Detailed breakdown:**
For typical constraint sizes, this approach may be too slow or use too much space.

### Space Complexity: O(1) or O(N) depending on approach

> **Drawback:**
> Both approaches work. Must match serialization format.

> **Key Insight for Improvement:**
> Use BFS Deserialization (Optimal) for O(N) time.

<br>

---

## Solution 2: BFS Deserialization (Optimal)

### Time Complexity: O(N)
### Space Complexity: O(N)

> **Drawback:** None.

> **Key Insight for Improvement:** Must match serialization format exactly. BFS serialize → BFS deserialize. Preorder serialize → preorder deserialize.

<br>

---

**Key Insights:**
1. **Queue mirrors serialization:** Parents processed in same order
2. **Two values per parent:** Left child, then right child
3. **"null" = no child:** Skip node creation

<br><br>

---

```code```
