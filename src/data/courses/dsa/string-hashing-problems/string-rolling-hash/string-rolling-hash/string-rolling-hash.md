Rolling hash computes hash of substring in O(1) after O(n) preprocessing.

## Formula
hash(s[i..j]) = (s[i]*p^0 + s[i+1]*p^1 + ... + s[j]*p^(j-i)) % mod

## Rolling Property
hash(s[i+1..j+1]) = (hash(s[i..j]) - s[i] + s[j+1]*p^(j-i)) % mod

## Applications
- Pattern matching
- Substring comparison
- Duplicate detection

## Code
```code```