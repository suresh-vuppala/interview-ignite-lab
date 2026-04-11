Assign + or - to each element to reach target sum.

<br>

---

## Solution 1: Recursion — Try +/- for each element O(2^n)
## Solution 2: DP — Transform to subset sum: find count of subsets with sum = (total + target) / 2

### Time: O(n × sum) | Space: O(sum)

<br>

---

## Complexity Progression Summary

| Solution | Time | Space | Key Improvement |
|----------|------|-------|----------------|
| Recursion | O(2^n) | O(n) | Try all assignments |
| Subset Sum DP | O(n × sum) | O(sum) | Reduce to subset sum |

<br>
<br>

---

```code```
