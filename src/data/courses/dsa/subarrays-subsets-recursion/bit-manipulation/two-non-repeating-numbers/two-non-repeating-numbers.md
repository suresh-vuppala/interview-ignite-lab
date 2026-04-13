Every element appears twice except two. Find both unique numbers.

<br>

> nums=[1,2,1,3,2,5] → [3,5]
>
> **Key insight:** XOR all → x^y (both uniques XORed). Find a set bit (differentiator). Split array by that bit. XOR each group → get x and y separately.

<br>

---

## Constraints
- Typical problem constraints

<br>

---

## All Possible Edge Cases
1. **Empty/single element input**
2. **Boundary values** (min/max of range)
3. **All elements same / sorted / reverse sorted**

<br>

---

## Solution 1: Hash map counting

### Time Complexity: O(N) time, O(N) space

> **Drawback:**
> Extra space.

> **Key Insight for Improvement:**
> XOR all gives x^y. A set bit in x^y means x and y differ at that position. Split and XOR each group.

<br>

---

## Solution 2: XOR + Bit Split (Optimal)

**Intuition:** XOR all → x^y (both uniques XORed). Find a set bit (differentiator). Split array by that bit. XOR each group → get x and y separately.

**Algorithm:**
1. XOR all → xorAll = x^y
2. Find any set bit: diff = xorAll & (-xorAll) (lowest set bit)
3. Group 1: elements with that bit set → XOR gives x
4. Group 2: elements without → XOR gives y

### Time Complexity: O(N)
**Why?**
Each element/state processed efficiently via the core technique.

**Detailed breakdown:**
Operations scale with input size as described by the complexity.

**Example walkthrough:**
```
[1,2,1,3,2,5]: xorAll=3^5=6=110
Lowest set bit: 110&010=010
Group(bit set): [2,2,3]→XOR=3. Group(not set): [1,1,5]→XOR=5. Result=[3,5] ✓
```

### Space Complexity: O(1)

<br>

---

## Complexity Progression Summary

| Solution | Time | Space | Key Improvement |
|----------|------|-------|----------------|
| Hash map counting | O(N) time, O(N) space | Varies | Baseline |
| XOR + Bit Split | O(N) | O(1) | Optimal approach |

**Recommended Solution:** XOR + Bit Split — O(N) time.

**Key Insights:**
1. **XOR all gives x^y:** But can't separate them directly
2. **Differentiating bit:** x and y differ at this bit position
3. **Split into groups:** Each group has one unique + pairs that cancel

<br><br>

---

```code```
