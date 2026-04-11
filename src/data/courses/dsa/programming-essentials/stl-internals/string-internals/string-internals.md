## String Internals — What Every Interviewer Expects You to Know

Strings are the second most common data type in interviews after arrays. Understanding immutability, complexity of operations, and language-specific behavior is critical.

<br>

## C++ `std::string`

- **Mutable** — Can modify characters in-place
- **Dynamic array** of `char` — similar internals to `vector<char>`
- **Small String Optimization (SSO)** — Short strings (typically ≤ 15-22 chars) are stored inline on the stack, no heap allocation

| Operation | Time | Notes |
|-----------|------|-------|
| `s[i]` | O(1) | Direct access |
| `s += c` | O(1) amortized | Like vector push_back |
| `s + t` | O(n + m) | Creates new string |
| `s.substr(pos, len)` | O(len) | Copies characters |
| `s.find(t)` | O(n × m) worst | Usually faster in practice |
| `s.compare(t)` | O(min(n, m)) | Lexicographic |
| `s.size()` | O(1) | Stored |

<br>

## Java `String`

- **Immutable** — Every modification creates a **new** String object
- **String Pool** — Literal strings are interned (shared)
- `s + t` → creates new String → **O(n)** per concatenation
- **In a loop, use `StringBuilder`** — otherwise O(n²) total

```java
// ❌ BAD — O(n²) due to immutability
String result = "";
for (int i = 0; i < n; i++) result += "a";

// ✅ GOOD — O(n)
StringBuilder sb = new StringBuilder();
for (int i = 0; i < n; i++) sb.append("a");
String result = sb.toString();
```

<br>

## Python `str`

- **Immutable** (like Java)
- `s + t` creates new string → use `"".join(list)` for building
- Slicing `s[i:j]` → O(j - i), creates a copy

<br>

## Common Interview Operations

| Need | C++ | Java | Python |
|------|-----|------|--------|
| Reverse | `reverse(s.begin(), s.end())` | `new StringBuilder(s).reverse().toString()` | `s[::-1]` |
| Sort chars | `sort(s.begin(), s.end())` | `char[] a = s.toCharArray(); Arrays.sort(a);` | `sorted(s)` |
| Check digit | `isdigit(c)` | `Character.isDigit(c)` | `c.isdigit()` |
| To lowercase | `tolower(c)` | `Character.toLowerCase(c)` | `c.lower()` |
| Substring | `s.substr(i, len)` | `s.substring(i, j)` | `s[i:j]` |

<br>
