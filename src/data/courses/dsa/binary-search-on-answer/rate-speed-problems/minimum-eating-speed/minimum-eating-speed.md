# Minimum Eating Speed (Koko Bananas)

## Problem Statement

Koko loves to eat bananas. There are `n` piles of bananas, where the `i-th` pile has `piles[i]` bananas. The guards have gone and will come back in `h` hours.

Koko can decide her bananas-per-hour eating speed `k`. Each hour, she chooses some pile of bananas and eats `k` bananas from that pile. If the pile has less than `k` bananas, she eats all of them instead and will not eat any more bananas during that hour.

Koko likes to eat slowly but still wants to finish eating all the bananas before the guards return.

Return the minimum integer `k` such that she can eat all the bananas within `h` hours.

## Visual Example

```
Input: piles = [3, 6, 7, 11], h = 8

Visualization of eating at different speeds:

Speed k = 4:
Hour 1: Pile 0 [3] → eat 3 (1 hour)
Hour 2: Pile 1 [6] → eat 4 (1 hour)
Hour 3: Pile 1 [2] → eat 2 (1 hour)
Hour 4: Pile 2 [7] → eat 4 (1 hour)
Hour 5: Pile 2 [3] → eat 3 (1 hour)
Hour 6: Pile 3 [11] → eat 4 (1 hour)
Hour 7: Pile 3 [7] → eat 4 (1 hour)
Hour 8: Pile 3 [3] → eat 3 (1 hour)
Total: 8 hours ✓

Speed k = 3:
Would take more than 8 hours ✗

Answer: k = 4
```

## Algorithm Explanation

### Approach: Binary Search on Answer

The key insight is that if Koko can finish eating at speed `k`, she can also finish at any speed greater than `k`. This monotonic property allows us to use binary search.

**Search Space:**
- Minimum speed: 1 banana/hour
- Maximum speed: max(piles) bananas/hour (eating the largest pile in 1 hour)

**Binary Search Logic:**
1. For each candidate speed `mid`, calculate total hours needed
2. For each pile, hours needed = ⌈pile / mid⌉ = (pile + mid - 1) / mid
3. If total hours ≤ h, try smaller speed (search left)
4. If total hours > h, need faster speed (search right)

### Step-by-Step Process

```
piles = [3, 6, 7, 11], h = 8

Initial: left = 1, right = 11

Iteration 1: mid = 6
  Hours: ⌈3/6⌉ + ⌈6/6⌉ + ⌈7/6⌉ + ⌈11/6⌉ = 1 + 1 + 2 + 2 = 6 ≤ 8 ✓
  Can finish! Try slower: right = 5

Iteration 2: mid = 3
  Hours: ⌈3/3⌉ + ⌈6/3⌉ + ⌈7/3⌉ + ⌈11/3⌉ = 1 + 2 + 3 + 4 = 10 > 8 ✗
  Too slow! Need faster: left = 4

Iteration 3: mid = 4
  Hours: ⌈3/4⌉ + ⌈6/4⌉ + ⌈7/4⌉ + ⌈11/4⌉ = 1 + 2 + 2 + 3 = 8 ≤ 8 ✓
  Can finish! Try slower: right = 3

left > right, stop
Answer: 4
```


---

## Constraints

- `1 ≤ n ≤ 10⁵`
- `Input array elements ≥ 1`
- `Answer is monotonic — if X works, X+1 also works (or vice versa)`

<br>

---

## All Possible Edge Cases

1. **Minimum possible answer:** Binary search low boundary
2. **Maximum possible answer:** Binary search high boundary
3. **Single element array:** Answer is trivially that element
4. **All elements same:** Answer may be the element or a function of it
5. **Large range:** Binary search on answer space O(log(range))

<br>

## Complexity Analysis

**Time Complexity:** O(n log m)
- **Why?** Binary search runs log(max_pile) iterations, and each iteration checks all n piles
- n = number of piles, m = maximum pile size

**Space Complexity:** O(1)
- **Why?** Only using constant extra space for variables

## Edge Cases

1. **h equals number of piles:** Must eat fastest pile in one hour → answer = max(piles)
2. **h much larger than n:** Can eat very slowly → answer = 1 or close to 1
3. **Single pile:** Simple case → answer = ⌈pile / h⌉
4. **All piles equal:** Uniform distribution of eating time
5. **One very large pile:** Dominates the minimum speed calculation

## Common Mistakes

1. Using `pile / mid` instead of ceiling division
2. Setting right = sum(piles) instead of max(piles)
3. Not handling integer overflow in hours calculation
4. Wrong binary search boundary updates

```code```
