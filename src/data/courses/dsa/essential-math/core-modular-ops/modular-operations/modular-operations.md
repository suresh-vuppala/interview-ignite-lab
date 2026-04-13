Modular arithmetic: addition, subtraction, multiplication.

<br>

> (a+b)%m, (a-b+m)%m, (a*b)%m
>
> **Key insight:** Distribute mod over +, -, ×. Subtraction: add m before mod to handle negatives.

<br>

---

## Constraints
- Typical problem constraints

<br>

---

## Solution 1: Direct computation

### Time Complexity: Overflow risk

> **Drawback:**
> Large numbers can overflow before taking mod.

> **Key Insight for Improvement:**
> Apply mod at each step to prevent overflow.

<br>

---

## Solution 2: Modular Properties (Optimal)

**Intuition:** Distribute mod over +, -, ×. Subtraction: add m before mod to handle negatives.

**Algorithm:**
(a+b)%m = ((a%m)+(b%m))%m
(a-b)%m = ((a%m)-(b%m)+m)%m
(a*b)%m = ((a%m)*(b%m))%m

### Time Complexity: O(1)
**Why?**
Each element/state processed efficiently.

**Detailed breakdown:**
Operations scale as described by the complexity.

**Example walkthrough:**
```
(7+5)%3 = ((7%3)+(5%3))%3 = (1+2)%3 = 0 ✓
```

### Space Complexity: O(1)

<br>

---

## Complexity Progression Summary

| Solution | Time | Space | Key Improvement |
|----------|------|-------|----------------|
| Direct computation | Overflow risk | Varies | Baseline |
| Modular Properties | O(1) | O(1) | Optimal |

**Recommended Solution:** Modular Properties

**Key Insights:**
1. **Distribute mod:** Apply to each operand first
2. **Add m for subtraction:** Prevents negative results
3. **Overflow prevention:** Mod after each multiplication

<br><br>

---

```code```
