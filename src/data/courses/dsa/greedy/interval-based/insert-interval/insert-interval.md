Given a sorted list of non-overlapping intervals and a new interval, insert the new interval and merge if necessary. Return the result sorted and non-overlapping.

<br>

---

## Constraints

- `0 ≤ intervals.length ≤ 10⁴`
- `intervals[i].length == 2`
- `0 ≤ start ≤ end ≤ 10⁵`
- `intervals sorted by start`
- `newInterval.length == 2`

<br>

---

## All Possible Edge Cases

1. **Empty intervals:** Just return [newInterval]
2. **No overlap:** Insert at correct position
3. **New interval covers all:** Return [newInterval]
4. **New interval at start:** Prepend or merge with first
5. **New interval at end:** Append or merge with last
6. **New interval between two:** Insert in the gap
7. **Overlap with multiple intervals:** Merge all overlapping into one

<br>

---

```code```
