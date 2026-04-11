Partition string into as many parts as possible so that each letter appears in at most one part. Return list of sizes of these parts.

<br>

---

## Constraints

- `1 ≤ s.length ≤ 500`
- `s consists of lowercase English letters`

<br>

---

## All Possible Edge Cases

1. **All same character:** Single partition of full string
2. **All unique characters:** Each character is its own partition of size 1
3. **Single character:** Return [1]
4. **Two partitions:** Find the split point
5. **Entire string one partition:** Some character appears at start and end
6. **Many small partitions:** Characters are clustered together

<br>

---

```code```
