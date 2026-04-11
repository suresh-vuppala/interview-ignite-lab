Given an unsorted array of integers, return the length of the longest consecutive elements sequence. Must run in O(n) time using HashSet.

<br>

---

## Constraints

- `0 ≤ nums.length ≤ 10⁵`
- `-10⁹ ≤ nums[i] ≤ 10⁹`
- `Must solve in O(n) time`

<br>

---

## All Possible Edge Cases

1. **Empty array:** Return 0
2. **Single element:** Return 1
3. **All same elements:** Return 1
4. **Already sorted consecutive:** Return n
5. **Duplicates in sequence:** [1,2,2,3] → still length 3
6. **Disjoint sequences:** Return longest one
7. **Negative numbers:** [-1,0,1] → length 3
8. **Large gaps:** [100, 4, 200, 1, 3, 2] → 4 (sequence: 1,2,3,4)

<br>

---

```code```
