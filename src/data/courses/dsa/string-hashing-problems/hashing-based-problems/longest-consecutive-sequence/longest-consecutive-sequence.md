Given an unsorted array, return the length of the longest consecutive elements sequence. Must solve in O(n) time.

<br>

> Input: [100, 4, 200, 1, 3, 2]
> Output: 4 (sequence: [1, 2, 3, 4])

<br>

---

## Constraints

- `0 ≤ nums.length ≤ 10⁵`
- `-10⁹ ≤ nums[i] ≤ 10⁹`

<br>

---

## All Possible Edge Cases

1. **Empty array:** Return 0
2. **Single element:** Return 1
3. **All same:** Return 1
4. **Duplicates in sequence:** [1,2,2,3] → still length 3
5. **Negative numbers:** [-1,0,1] → length 3

<br>

---

## Solution 1: Sort + Scan

**Intuition:**
Sort the array. Scan for consecutive elements, tracking the longest run.

**Algorithm:**
1. Sort nums
2. Skip duplicates
3. If nums[i] == nums[i-1] + 1 → extend current streak
4. Else reset streak
5. Track max streak

### Time Complexity: O(n log n)
### Space Complexity: O(1)

> **Key Insight:** We only need O(1) lookup to check if num+1 exists. Use a HashSet.

<br>

---

## Solution 2: Hash Set (Optimal)

**Intuition:**
Put all numbers in a HashSet. For each number that is the START of a sequence (num-1 not in set), count consecutive numbers.

**Algorithm:**
1. Add all nums to HashSet
2. For each num where (num - 1) NOT in set → this is a sequence start
3. Count: while (num + 1) in set → extend
4. Track max length

### Time Complexity: O(n)
**Why O(n) and not O(n²)?** Each number is visited at most twice: once in the main loop, once as part of counting a sequence. The "only start from beginnings" trick ensures no element is counted multiple times.

### Space Complexity: O(n)

<br>

---

## Complexity Progression Summary

| Solution | Time | Space | Key Improvement |
|----------|------|-------|----------------|
| Sort + Scan | O(n log n) | O(1) | Consecutive after sorting |
| Hash Set | O(n) | O(n) | Only count from sequence starts |

**Recommended:** Hash Set — O(n) time.

<br>
<br>

---

```code```
