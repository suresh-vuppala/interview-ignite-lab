Given a string s and integer k, find the length of the longest substring that contains at most k distinct characters.

<br>

> Input:
> s = "eceba", k = 2

> Output:
> 3

> Explanation:
> "ece" has 2 distinct characters (e, c) and length 3.
> 
> **Key insight:** Generalized version of "Fruits into Baskets" (where k=2). Sliding window with frequency map, shrink when distinct > k.

<br>



---

## Constraints

- `1 ≤ s.length ≤ 5 × 10⁴`
- `0 ≤ k ≤ 50`

<br>

---

## All Possible Edge Cases

1. **k = 0:** Return 0 (no characters allowed)
2. **k ≥ unique chars:** Return entire string length
3. **All same chars:** Return n for any k ≥ 1

<br>

---

## Solution 1: Brute Force

**Intuition:**
The most straightforward approach. Checking each substring independently.

**Algorithm:**
1. For each element i (outer loop):
   - For each element j (inner loop):
     - Check if the pair/condition is satisfied
2. Return the best result found

### Time Complexity: O(N²)
**Why?**
Two nested loops each running up to N iterations.
Outer loop: N iterations × Inner loop: up to N iterations = N² total operations.

**Detailed breakdown:**
For N=1,000: ~1 million operations (OK). For N=10,000: ~100 million (borderline TLE).

### Space Complexity: O(1) extra (or O(N) if using auxiliary structures)
**Why?**
Depends on whether auxiliary data structures are used. Pure brute force typically uses O(1) extra space beyond the input.

> **Drawback:**
> Checking each substring independently. Same overhead as fruits/character-replacement.

> **Key Insight for Improvement:**
> Sliding window + frequency map. Shrink left when distinct count > k. Map size = distinct count.

<br>

---

## Solution 2: Sliding Window + Frequency Map (Optimal)

**Algorithm:**
1. left = 0, freq = {}, maxLen = 0
2. For right = 0 to n-1:
   - freq[s[right]]++
   - While len(freq) > k: freq[s[left]]--, if 0 → delete; left++
   - maxLen = max(maxLen, right - left + 1)

### Time Complexity: O(N)
**Why?**
- Each char added/removed at most once
- Total: 2N = O(N)

**Detailed breakdown:**
- N = 50,000 → at most 100,000 operations

**Example walkthrough:**
```
s = "eceba", k = 2

right=0('e'): freq={e:1}, distinct=1 ≤ 2 → len=1
right=1('c'): freq={e:1,c:1}, distinct=2 ≤ 2 → len=2
right=2('e'): freq={e:2,c:1}, distinct=2 ≤ 2 → len=3 ★
right=3('b'): freq={e:2,c:1,b:1}, distinct=3 > 2 → shrink:
  remove 'e': freq={e:1,c:1,b:1}, still 3 > 2
  remove 'c': freq={e:1,c:0→del,b:1}, distinct=2 ≤ 2. left=2
  len=3-2+1=2
right=4('a'): freq={e:1,b:1,a:1}, 3>2 → shrink:
  remove 'e': freq={b:1,a:1}, 2≤2. left=3. len=4-3+1=2

maxLen = 3 ✓
```

### Space Complexity: O(K)

<br>

---

## Complexity Progression Summary

| Solution | Time | Space | Key Improvement |
|----------|------|-------|----------------|
| Brute Force | O(N²) | O(N) | All substrings |
| Sliding Window | O(N) | O(K) | Freq map, shrink when distinct > k |

**Recommended Solution:** Sliding Window (Solution 2) — O(N) time.

**Key Insights:**
1. **Generalization of Fruits:** Fruits = k=2, this is any k
2. **Delete keys at count 0:** Essential for correct distinct count via map.size()
3. **Pattern template:** This template works for many "at most K distinct" problems


<br>
<br>

---

```code```
