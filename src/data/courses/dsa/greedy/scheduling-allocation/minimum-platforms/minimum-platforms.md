Given arrival and departure times of all trains at a railway station, find the minimum number of platforms required.

<br>

---

## Constraints

- `1 ≤ n ≤ 10⁵`
- `0 ≤ arrival[i] < departure[i] ≤ 2359`

<br>

---

## All Possible Edge Cases

1. **No overlaps:** 1 platform needed
2. **All overlap:** n platforms needed
3. **Single train:** 1 platform
4. **Back-to-back arrivals:** Departure before next arrival → reuse platform
5. **All arrive same time:** n platforms

<br>

---

```code```
