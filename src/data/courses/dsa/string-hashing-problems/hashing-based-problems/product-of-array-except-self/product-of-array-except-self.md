Given an integer array, return array where answer[i] = product of all elements except nums[i]. Must solve in O(n) without division.

<br>

> Input: [1,2,3,4] → Output: [24,12,8,6]

<br>

---

## Constraints

- `2 ≤ nums.length ≤ 10⁵`
- `-30 ≤ nums[i] ≤ 30`
- O(n) without division

<br>

---

## All Possible Edge Cases

1. **Contains zero:** All products 0 except at zero's position
2. **Multiple zeros:** All products are 0
3. **Two elements:** [a,b] → [b,a]

<br>

---

## Solution 1: Brute Force

**Intuition:** For each index, multiply all other elements.

### Time Complexity: O(n²)
### Space Complexity: O(1)

```code```

> **Key Insight for Improvement:**
>
> **Drawback of current approach:** For each element, we iterate through the entire array to compute the product — n multiplications per element × n elements = O(n²). We're recomputing overlapping products from scratch every time.
>
> **Insight:** result[i] = (product of everything LEFT of i) × (product of everything RIGHT of i). We can precompute prefix and suffix product arrays in O(n) each.

<br>

---

## Solution 2: Prefix + Suffix Arrays

**Intuition:** Build left prefix products and right suffix products. result[i] = prefix[i] × suffix[i].

### Time Complexity: O(n)
### Space Complexity: O(n)

```code```

> **Key Insight for Improvement:**
>
> **Drawback of current approach:** We use two extra arrays (prefix and suffix) — O(n) extra space. Can we do it with O(1) extra space?
>
> **Insight:** Use the result array itself for prefix products (left pass), then multiply in the suffix products using a single running variable (right pass). No extra arrays needed.

<br>

---

## Solution 3: Two-Pass with Running Variable (Optimal)

**Intuition:** Pass 1: Fill result with left prefix products. Pass 2: Multiply by right suffix using a running variable.

### Time Complexity: O(n)
### Space Complexity: O(1) extra

```code```

<br>

---

## Complexity Progression Summary

| Solution | Time | Space | Key Improvement |
|----------|------|-------|----------------|
| Brute Force | O(n²) | O(1) | Recompute per element |
| Prefix + Suffix | O(n) | O(n) | Precompute left/right products |
| Two-Pass | O(n) | O(1) | Running variable replaces suffix array |

<br>
<br>
