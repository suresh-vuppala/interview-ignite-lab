Given an array of integers where each integer represents a card value, find the minimum number of consecutive cards to pick up to have a pair of matching cards. Return -1 if impossible.

<br>

> Input:
> cards = [3, 4, 2, 3, 4, 7]

> Output:
> 4

> Explanation:
> Pick cards [3, 4, 2, 3] — indices 0 to 3. Card 3 appears twice. Length = 4 is the minimum.
> 
> **Key insight:** For each value, track the last seen index. When we see a value again, the window from lastSeen+1 to current is a candidate. Minimum across all such windows.

<br>



---

## Constraints

- `1 ≤ cards.length ≤ 10⁵`
- `0 ≤ cards[i] ≤ 10⁶`

<br>

---

## All Possible Edge Cases

1. **No duplicates:** Return -1
2. **All same:** Return 2 (adjacent pair)
3. **Pair at extremes:** [1,2,3,1] → length 4

<br>

---

## Solution 1: Brute Force — Check All Pairs

### Time Complexity: O(N²)

> **Drawback:**
> Checking all pairs. We only need the CLOSEST pair of matching values — not all pairs.

> **Key Insight for Improvement:**
> Use a hash map storing the last index of each value. When we encounter a value again, the distance from lastSeen to current = window size containing a pair. Track minimum.

<br>

---

## Solution 2: Hash Map — Track Last Seen (Optimal)

**Algorithm:**
1. lastSeen = {}, minLen = ∞
2. For each i:
   - If cards[i] in lastSeen: minLen = min(minLen, i - lastSeen[cards[i]] + 1)
   - lastSeen[cards[i]] = i
3. Return minLen == ∞ ? -1 : minLen

### Time Complexity: O(N)
**Why?**
- Single pass with O(1) map operations

**Detailed breakdown:**
- N = 100,000 → 100,000 operations

**Example walkthrough:**
```
cards = [3, 4, 2, 3, 4, 7]

i=0: cards[0]=3, lastSeen={3:0}
i=1: cards[1]=4, lastSeen={3:0, 4:1}
i=2: cards[2]=2, lastSeen={3:0, 4:1, 2:2}
i=3: cards[3]=3, seen at 0 → len=3-0+1=4, lastSeen={3:3, 4:1, 2:2}
i=4: cards[4]=4, seen at 1 → len=4-1+1=4, lastSeen={3:3, 4:4, 2:2}
i=5: cards[5]=7, lastSeen={3:3, 4:4, 2:2, 7:5}

minLen = 4 ✓
```

### Space Complexity: O(N)

<br>

---

## Complexity Progression Summary

| Solution | Time | Space | Key Improvement |
|----------|------|-------|----------------|
| Brute Force | O(N²) | O(1) | All pairs |
| Hash Map | O(N) | O(N) | Track last seen index per value |

**Recommended Solution:** Hash Map (Solution 2) — O(N) time.

**Key Insights:**
1. **Last seen index:** Only the most recent occurrence matters (gives shortest window)
2. **Single pass:** Check distance to last seen on each encounter
3. **Update after check:** Update lastSeen AFTER computing the window length


<br>
<br>

---

```code```
