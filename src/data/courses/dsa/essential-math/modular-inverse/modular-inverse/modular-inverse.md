Find modular multiplicative inverse: a⁻¹ mod m.

<br>

---

## Solution 1: Extended Euclidean Algorithm — Find x where ax ≡ 1 (mod m)
## Solution 2: Fermat's Little Theorem — If m is prime: a⁻¹ = a^(m-2) mod m (use fast exponentiation)

### Time: O(log m) | Space: O(1)

<br>

---

## Complexity Progression Summary

| Solution | Time | Space | Key Improvement |
|----------|------|-------|----------------|
| Extended GCD | O(log m) | O(1) | Works for any coprime a,m |
| Fermat's | O(log m) | O(1) | Simpler when m is prime |

<br>
<br>

---

```code```
