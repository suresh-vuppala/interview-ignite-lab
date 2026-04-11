Minimum trials to find critical floor with k eggs and n floors.

<br>

---

## Solution 1: Recursion — For each floor, try dropping: max(breaks, doesn't break). Take min over all floors.

### Time: O(n × 2^k) | Space: O(nk)

<br>

---

## Solution 2: DP + Binary Search

dp[k][n] = min trials. Binary search for optimal floor.

### Time: O(k × n × log n) | Space: O(k × n)

<br>

---

## Solution 3: Reverse DP (Optimal)

dp[t][k] = max floors testable with t trials and k eggs. Increment t until dp[t][k] >= n.

### Time: O(k × log n) | Space: O(k)

<br>

---

## Complexity Progression Summary

| Solution | Time | Space | Key Improvement |
|----------|------|-------|----------------|
| Recursion | O(n × 2^k) | O(nk) | Try all floors |
| DP + Binary Search | O(kn log n) | O(kn) | Binary search for opt floor |
| Reverse DP | O(k log n) | O(k) | Ask "how many floors?" instead |

<br>
<br>

---

```code```
