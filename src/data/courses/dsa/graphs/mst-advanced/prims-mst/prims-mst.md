Find MST using Prim's algorithm (grow from a single vertex).

<br>

---

## Solution 1: Prim's with Min-Heap

**Intuition:** Start from any vertex. Always add the cheapest edge connecting MST to non-MST vertex.

**Algorithm:**
1. Min-heap: (weight, vertex). Start with (0, source)
2. While heap not empty:
   - Pop (w, u). Skip if already in MST
   - Add to MST, total += w
   - Push all edges from u to non-MST neighbors

### Time: O(E log V) | Space: O(V)

<br>

---

## Complexity Progression Summary

| Solution | Time | Space | Key Improvement |
|----------|------|-------|----------------|
| Prim's + Heap | O(E log V) | O(V) | Greedy edge selection |

<br>
<br>

---

```code```
