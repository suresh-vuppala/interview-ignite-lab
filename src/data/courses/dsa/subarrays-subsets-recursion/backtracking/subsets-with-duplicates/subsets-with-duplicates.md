Given an integer array nums that may contain duplicates, return all possible subsets. The solution set must not contain duplicate subsets. Sort the array first, then skip duplicate elements at each recursion level.

<br>

---

## Constraints

- `1 ≤ nums.length ≤ 10`
- `-10 ≤ nums[i] ≤ 10`
- `Array may contain duplicates`

<br>

---

## All Possible Edge Cases

1. **No duplicates:** Same as Subsets I
2. **All duplicates:** [1,1,1] → [],[1],[1,1],[1,1,1]
3. **Single element:** [[],[nums[0]]]
4. **Empty array:** [[]]
5. **Mix of duplicates:** [1,2,2] → [],[1],[1,2],[1,2,2],[2],[2,2]
6. **Must sort first:** Sorting ensures duplicates are adjacent for skip logic

<br>

---

```code```
