Rotate linked list right by k positions.

<br>

---

## Solution 1: Make Circular + Break

**Algorithm:**
1. Count length n, connect tail → head (circular)
2. New tail is at position (n - k % n - 1) from head
3. Break circle at new tail

### Time: O(n) | Space: O(1)

<br>

---

## Complexity Progression Summary

| Solution | Time | Space | Key Improvement |
|----------|------|-------|----------------|
| Circular + Break | O(n) | O(1) | Connect then break at new position |

<br>
<br>

---

```code```
