Compute hash of any substring in O(1) time using polynomial rolling hash technique.

<br>

> Example:
> String s = "abcde"
> Query: hash("bcd") = ?
> 
> Without rolling hash: O(length) to compute
> With rolling hash: O(1) after O(n) preprocessing

> Output:
> Preprocess: O(n) once
> Query: O(1) per substring

> Explanation:
> Rolling hash allows constant-time substring hash queries
> Key for efficient pattern matching and string comparison
> 
> **Key insight:** Polynomial hash with prefix sums enables O(1) range queries.

<br>

---

## Concept: Polynomial Rolling Hash

**What is a hash function?**
Maps string to integer for fast comparison.

**Polynomial Hash Formula:**
```
hash(s) = (s[0]×p^0 + s[1]×p^1 + s[2]×p^2 + ... + s[n-1]×p^(n-1)) mod M
```

Where:
- `p` = prime base (typically 31 for lowercase, 53 for mixed case)
- `M` = large prime modulus (typically 10^9+7 or 10^9+9)
- `s[i]` = character value (e.g., 'a'=1, 'b'=2, ...)

**Example: hash("abc")**
```
s = "abc"
p = 31, M = 10^9+7

hash = (1×31^0 + 2×31^1 + 3×31^2) mod M
     = (1×1 + 2×31 + 3×961) mod M
     = (1 + 62 + 2883) mod M
     = 2946
```

<br>

---

## Technique 1: Prefix Hash Array

**Intuition:**
Precompute hash of all prefixes.
Use prefix difference to get any substring hash.

**Preprocessing:**
```cpp
vector<long long> prefix(n+1), power(n+1);
prefix[0] = 0;
power[0] = 1;

for (int i = 0; i < n; i++) {
    prefix[i+1] = (prefix[i] + (s[i]-'a'+1) * power[i]) % M;
    power[i+1] = (power[i] * p) % M;
}
```

**Example: s = "abcd"**
```
p = 31, M = 10^9+7

prefix[0] = 0
prefix[1] = (0 + 1×31^0) mod M = 1
prefix[2] = (1 + 2×31^1) mod M = 63
prefix[3] = (63 + 3×31^2) mod M = 2946
prefix[4] = (2946 + 4×31^3) mod M = 122110
```

**Query: hash(s[L..R])**
```cpp
long long getHash(int L, int R) {
    long long hash_val = (prefix[R+1] - prefix[L] + M) % M;
    return (hash_val * modInverse(power[L], M)) % M;
}
```

<br>

---

## Technique 2: Rolling Hash (Sliding Window)

**Intuition:**
When sliding window by 1 position, update hash in O(1).

**Formula:**
```
Remove left: hash_new = (hash_old - s[left]) / p
Add right:   hash_new = hash_old + s[right] × p^(window_size-1)
```

**Implementation:**
```cpp
long long hash = 0, pow_val = 1;

// Initial window
for (int i = 0; i < m; i++) {
    hash = (hash + (s[i]-'a'+1) * pow_val) % M;
    if (i < m-1) pow_val = (pow_val * p) % M;
}

// Slide window
for (int i = m; i < n; i++) {
    hash = (hash - (s[i-m]-'a'+1) + M) % M;
    hash = (hash * modInverse(p, M)) % M;
    hash = (hash + (s[i]-'a'+1) * pow_val) % M;
}
```

**Example: Slide "abc" → "bcd" in "abcde"**
```
Initial: hash("abc") = 1×1 + 2×31 + 3×961 = 2946

Remove 'a' (value 1):
  hash = (2946 - 1) / 31 = 95

Add 'd' (value 4):
  hash = 95 + 4×961 = 3939

Result: hash("bcd") = 3939
```

<br>

---

## Modular Arithmetic Essentials

**1. Modular Inverse**
```cpp
// Using Fermat's Little Theorem: a^(p-1) ≡ 1 (mod p)
// a^(-1) ≡ a^(p-2) (mod p)
long long modInverse(long long a, long long m) {
    return power(a, m-2, m);
}

long long power(long long a, long long b, long long m) {
    long long res = 1;
    while (b > 0) {
        if (b & 1) res = (res * a) % m;
        a = (a * a) % m;
        b >>= 1;
    }
    return res;
}
```

**2. Handling Negative Values**
```cpp
// Always add M before mod to avoid negative
hash = (hash - val + M) % M;
```

**3. Overflow Prevention**
```cpp
// Use long long and apply mod at each step
hash = ((hash % M) + (val % M)) % M;
```

<br>

---

## Common Pitfalls & Solutions

**1. Overflow Issues**
```cpp
// Problem: p^k can overflow
// Solution: Apply mod at each step
power[i] = (power[i-1] * p) % M;
```

**2. Negative Hash Values**
```cpp
// Problem: (a - b) mod M can be negative
// Solution: Add M before mod
hash = (prefix[R+1] - prefix[L] + M) % M;
```

**3. Division in Modular Arithmetic**
```cpp
// Problem: Can't directly divide by p
// Solution: Multiply by modular inverse
hash = (hash * modInverse(p, M)) % M;
```

**4. Hash Collisions**
```cpp
// Problem: Different strings same hash
// Solution: Double hashing
struct DoubleHash {
    long long h1, h2;
    static const long long M1 = 1e9+7, M2 = 1e9+9;
    static const int P1 = 31, P2 = 37;
};
```

<br>

---

## Complete Implementation Template

```cpp
class RollingHash {
    int n;
    long long p = 31, M = 1e9+7;
    vector<long long> prefix, power;
    
public:
    RollingHash(string s) {
        n = s.size();
        prefix.resize(n+1);
        power.resize(n+1);
        
        prefix[0] = 0;
        power[0] = 1;
        
        for (int i = 0; i < n; i++) {
            prefix[i+1] = (prefix[i] + (s[i]-'a'+1) * power[i]) % M;
            power[i+1] = (power[i] * p) % M;
        }
    }
    
    long long getHash(int L, int R) {
        long long hash_val = (prefix[R+1] - prefix[L] + M) % M;
        return (hash_val * modInverse(power[L])) % M;
    }
    
    long long modInverse(long long a) {
        return power(a, M-2);
    }
    
    long long power(long long a, long long b) {
        long long res = 1;
        while (b > 0) {
            if (b & 1) res = (res * a) % M;
            a = (a * a) % M;
            b >>= 1;
        }
        return res;
    }
};
```

<br>

---

## Time & Space Complexity

**Preprocessing:**
- Time: O(N) - compute all prefix hashes and powers
- Space: O(N) - store prefix and power arrays

**Query:**
- Time: O(1) - arithmetic operations only
- Space: O(1) - no extra space per query

**Comparison:**

| Operation | Naive | Rolling Hash |
|-----------|-------|--------------|
| Preprocess | - | O(N) |
| Substring hash | O(K) | O(1) |
| Pattern match | O(N×M) | O(N+M) |
| Compare K substrings | O(K×L) | O(K) |

<br>

---

## Key Takeaways

1. **Polynomial hash** maps strings to integers efficiently
2. **Prefix arrays** enable O(1) substring hash queries
3. **Rolling property** allows O(1) hash updates in sliding window
4. **Modular arithmetic** prevents overflow
5. **Double hashing** reduces collision probability
6. **Always verify** hash matches with string comparison

> **Preprocessing:** O(N) time, O(N) space
> **Query:** O(1) time, O(1) space

<br>
<br>

---
