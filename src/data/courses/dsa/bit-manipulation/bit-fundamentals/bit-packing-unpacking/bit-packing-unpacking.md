**Bit packing** is a technique to store multiple integers inside a single integer by using different bit positions.

<br>

## Core Idea

Instead of storing two integers separately:
```cpp
int i = 12345;
int j = 54321;
// Uses 8 bytes (2 × 4 bytes)
```

Pack them into one integer:
```cpp
long long packed = (i << BITS) | j;
// Uses 8 bytes total
```

**Benefits:**
- Single hash key instead of pair
- Faster comparisons
- Reduced memory in some cases
- Useful in priority queues and graphs

<br>

---

## Basic 2-Number Packing

### Formula

```cpp
// Pack
packed = (i << BITS) | j;

// Unpack
i = packed >> BITS;
j = packed & ((1 << BITS) - 1);
```

Where `BITS` = number of bits needed to store `j`

<br>

### How It Works

**Visual Representation:**

```
Original:
i = 5 (binary: 101)
j = 3 (binary: 011)

Packed (BITS = 3):
packed = (5 << 3) | 3
       = 101000 | 000011
       = 101011 (decimal: 43)

Unpacking:
i = 101011 >> 3 = 101 (5) ✓
j = 101011 & 111 = 011 (3) ✓
```

<br>

### Step-by-Step Example

**Given:** `i ≤ 10^5`, `j ≤ 10^5`

**Step 1: Calculate BITS needed**
```
max(j) = 10^5 = 100,000
log₂(100,000) ≈ 16.6
BITS = 17 (need ceiling)
```

**Step 2: Pack**
```cpp
int i = 12345;
int j = 54321;
int BITS = 17;

long long packed = ((long long)i << BITS) | j;
```

**Step 3: Unpack**
```cpp
int i_unpacked = packed >> BITS;
int j_unpacked = packed & ((1LL << BITS) - 1);
```

<br>

### Complete Code

```cpp
#include <bits/stdc++.h>
using namespace std;

int main() {
    int i = 12345;
    int j = 54321;
    
    int BITS = 17;  // Enough for values up to 2^17 = 131,072
    
    // Pack
    long long packed = ((long long)i << BITS) | j;
    
    cout << "Packed value: " << packed << endl;
    
    // Unpack
    int i_unpacked = packed >> BITS;
    int j_unpacked = packed & ((1LL << BITS) - 1);
    
    cout << "i: " << i_unpacked << endl;  // 12345
    cout << "j: " << j_unpacked << endl;  // 54321
    
    return 0;
}
```

<br>

---

## 32-Bit Split (Common Shortcut)

When both values fit in 32 bits, use a simple split:

```cpp
// Pack: Store i in upper 32 bits, j in lower 32 bits
long long packed = ((long long)i << 32) | j;

// Unpack
int i = packed >> 32;
int j = packed & 0xFFFFFFFF;  // Mask for lower 32 bits
```

**Visual:**
```
64-bit long long:
[---- 32 bits for i ----][---- 32 bits for j ----]
```

**Example:**
```cpp
int i = 100000;
int j = 200000;

long long packed = ((long long)i << 32) | j;

int i_unpacked = packed >> 32;           // 100000
int j_unpacked = packed & 0xFFFFFFFF;    // 200000
```

<br>

---

## 3-Number Packing

Pack three integers into one `long long` (64 bits).

### Formula

```cpp
// Pack
packed = ((long long)a << (BITS_B + BITS_C)) | 
         ((long long)b << BITS_C) | 
         c;

// Unpack
a = packed >> (BITS_B + BITS_C);
b = (packed >> BITS_C) & ((1LL << BITS_B) - 1);
c = packed & ((1LL << BITS_C) - 1);
```

<br>

### Example: Pack (row, col, distance)

**Given:** 
- `row ≤ 1000` (needs 10 bits)
- `col ≤ 1000` (needs 10 bits)
- `distance ≤ 10^6` (needs 20 bits)
- Total: 10 + 10 + 20 = 40 bits (fits in 64-bit long long)

```cpp
#include <bits/stdc++.h>
using namespace std;

int main() {
    int row = 500;
    int col = 750;
    int distance = 123456;
    
    int BITS_COL = 10;
    int BITS_DIST = 20;
    
    // Pack
    long long packed = ((long long)row << (BITS_COL + BITS_DIST)) |
                       ((long long)col << BITS_DIST) |
                       distance;
    
    cout << "Packed: " << packed << endl;
    
    // Unpack
    int row_unpacked = packed >> (BITS_COL + BITS_DIST);
    int col_unpacked = (packed >> BITS_DIST) & ((1LL << BITS_COL) - 1);
    int dist_unpacked = packed & ((1LL << BITS_DIST) - 1);
    
    cout << "Row: " << row_unpacked << endl;      // 500
    cout << "Col: " << col_unpacked << endl;      // 750
    cout << "Distance: " << dist_unpacked << endl; // 123456
    
    return 0;
}
```

**Visual:**
```
64-bit long long:
[unused][-- 10 bits row --][-- 10 bits col --][-- 20 bits distance --]
```

<br>

---

## Handling Negative Numbers

### Problem

Negative numbers use **two's complement** representation, which causes issues with bit packing.

```cpp
int i = -5;  // Binary: 11111111111111111111111111111011 (32 bits)
```

If you shift this, the sign bit propagates.

<br>

### Solution 1: Offset to Make Positive

```cpp
// If range is [-1000, 1000]
int OFFSET = 1000;

// Pack
int i_positive = i + OFFSET;  // Convert to [0, 2000]
int j_positive = j + OFFSET;

long long packed = ((long long)i_positive << BITS) | j_positive;

// Unpack
int i = (packed >> BITS) - OFFSET;
int j = (packed & ((1LL << BITS) - 1)) - OFFSET;
```

<br>

### Solution 2: Use Unsigned Integers

```cpp
// Cast to unsigned to avoid sign extension
unsigned int i_unsigned = (unsigned int)i;
unsigned int j_unsigned = (unsigned int)j;

long long packed = ((long long)i_unsigned << 32) | j_unsigned;

// Unpack
int i = (int)(packed >> 32);
int j = (int)(packed & 0xFFFFFFFF);
```

<br>

### Example: Negative Number Packing

```cpp
#include <bits/stdc++.h>
using namespace std;

int main() {
    int i = -500;
    int j = 750;
    
    int OFFSET = 1000;  // Range: [-1000, 1000]
    int BITS = 11;      // 2^11 = 2048 > 2000
    
    // Pack (with offset)
    int i_pos = i + OFFSET;  // -500 + 1000 = 500
    int j_pos = j + OFFSET;  // 750 + 1000 = 1750
    
    long long packed = ((long long)i_pos << BITS) | j_pos;
    
    // Unpack
    int i_unpacked = (packed >> BITS) - OFFSET;
    int j_unpacked = (packed & ((1LL << BITS) - 1)) - OFFSET;
    
    cout << "i: " << i_unpacked << endl;  // -500
    cout << "j: " << j_unpacked << endl;  // 750
    
    return 0;
}
```

<br>

---

## Calculating Required Bits

### Formula

```
BITS = ⌈log₂(max_value + 1)⌉
```

### Quick Reference

| Max Value | BITS Needed | Range |
|-----------|-------------|-------|
| 1 | 1 | [0, 1] |
| 3 | 2 | [0, 3] |
| 7 | 3 | [0, 7] |
| 15 | 4 | [0, 15] |
| 31 | 5 | [0, 31] |
| 63 | 6 | [0, 63] |
| 127 | 7 | [0, 127] |
| 255 | 8 | [0, 255] |
| 511 | 9 | [0, 511] |
| 1,023 | 10 | [0, 1,023] |
| 10^3 | 10 | [0, 1,023] |
| 10^4 | 14 | [0, 16,383] |
| 10^5 | 17 | [0, 131,071] |
| 10^6 | 20 | [0, 1,048,575] |
| 10^9 | 30 | [0, 1,073,741,823] |

<br>

### Code to Calculate

```cpp
int calculateBits(int maxValue) {
    return (int)ceil(log2(maxValue + 1));
}

// Or using bit manipulation
int calculateBits(int maxValue) {
    int bits = 0;
    while ((1 << bits) <= maxValue) {
        bits++;
    }
    return bits;
}
```

<br>

---

## Common Use Cases

### 1. Hash Map Key (Pair → Single Key)

**Without packing:**
```cpp
map<pair<int, int>, int> mp;
mp[{i, j}] = value;
```

**With packing:**
```cpp
map<long long, int> mp;
long long key = ((long long)i << 32) | j;
mp[key] = value;
```

**Benefits:** Faster hashing, simpler key comparison

<br>

### 2. Priority Queue (Dijkstra's Algorithm)

**Without packing:**
```cpp
priority_queue<pair<int, int>> pq;
pq.push({distance, node});
```

**With packing:**
```cpp
priority_queue<long long> pq;
long long packed = ((long long)distance << 32) | node;
pq.push(packed);
```

<br>

### 3. Graph Edge Encoding

**Without packing:**
```cpp
struct Edge {
    int u, v, weight;
};
```

**With packing:**
```cpp
// Pack (u, v, weight) into one long long
long long edge = ((long long)u << 40) | ((long long)v << 20) | weight;
```

<br>

### 4. BFS State Encoding

**Problem:** Store (row, col, steps) in BFS

**Without packing:**
```cpp
queue<tuple<int, int, int>> q;
q.push({row, col, steps});
```

**With packing:**
```cpp
queue<long long> q;
long long state = ((long long)row << 40) | ((long long)col << 20) | steps;
q.push(state);
```

<br>

---

## Performance Comparison: Packed vs Pair

### Memory Usage

```cpp
// Using pair
pair<int, int> p = {12345, 54321};
// Size: sizeof(pair<int,int>) = 8 bytes

// Using packed
long long packed = ((long long)12345 << 32) | 54321;
// Size: sizeof(long long) = 8 bytes
```

**Memory:** Same (8 bytes)

<br>

### Speed Comparison

```cpp
#include <bits/stdc++.h>
using namespace std;

int main() {
    int n = 10000000;
    
    // Test 1: Using pair
    auto start = chrono::high_resolution_clock::now();
    
    map<pair<int, int>, int> mp1;
    for (int i = 0; i < n; i++) {
        mp1[{i, i + 1}] = i;
    }
    
    auto end = chrono::high_resolution_clock::now();
    auto duration1 = chrono::duration_cast<chrono::milliseconds>(end - start);
    
    // Test 2: Using packed
    start = chrono::high_resolution_clock::now();
    
    map<long long, int> mp2;
    for (int i = 0; i < n; i++) {
        long long key = ((long long)i << 32) | (i + 1);
        mp2[key] = i;
    }
    
    end = chrono::high_resolution_clock::now();
    auto duration2 = chrono::duration_cast<chrono::milliseconds>(end - start);
    
    cout << "Pair: " << duration1.count() << " ms" << endl;
    cout << "Packed: " << duration2.count() << " ms" << endl;
    
    return 0;
}
```

**Typical Results:**
```
Pair: 3500 ms
Packed: 2800 ms
```

**Packed is ~20-25% faster** due to:
- Simpler hash function
- Single comparison instead of two
- Better cache locality

<br>

---

## Important Rules & Pitfalls

### 1. Ensure Enough Bits

```cpp
// ❌ Wrong: j can be up to 10^5, but only 16 bits allocated
int BITS = 16;  // 2^16 = 65,536 < 100,000
long long packed = ((long long)i << BITS) | j;  // Data loss!

// ✓ Correct: Use 17 bits
int BITS = 17;  // 2^17 = 131,072 > 100,000
```

<br>

### 2. Use long long for Packing

```cpp
// ❌ Wrong: Overflow when shifting
int packed = (i << 32) | j;  // i << 32 overflows int

// ✓ Correct: Cast to long long
long long packed = ((long long)i << 32) | j;
```

<br>

### 3. Mask When Unpacking

```cpp
// ❌ Wrong: May get extra bits
int j = packed;  // If packed has bits beyond j's range

// ✓ Correct: Use mask
int j = packed & ((1LL << BITS) - 1);
```

<br>

### 4. Watch for Negative Numbers

```cpp
// ❌ Wrong: Negative numbers cause issues
int i = -5;
long long packed = ((long long)i << 32) | j;  // Sign extension!

// ✓ Correct: Add offset or use unsigned
int i_positive = i + OFFSET;
long long packed = ((long long)i_positive << 32) | j;
```

<br>

---

## When to Use Bit Packing

### ✓ Use When:
- Need single hash key for multiple values
- Working with priority queues (faster comparisons)
- Encoding graph edges or states
- Memory is tight and values are small
- Performance matters (competitive programming)

### ✗ Avoid When:
- Code readability is priority
- Values don't fit in available bits
- Debugging is difficult
- Team members unfamiliar with technique
- Using modern C++ with good pair/tuple optimization

<br>

---

## Summary Table

| Scenario | Bits Needed | Pack Formula | Unpack Formula |
|----------|-------------|--------------|----------------|
| 2 numbers (custom) | BITS | `(i << BITS) \| j` | `i = x >> BITS`<br>`j = x & mask` |
| 2 numbers (32-bit) | 32 | `(i << 32) \| j` | `i = x >> 32`<br>`j = x & 0xFFFFFFFF` |
| 3 numbers | B1, B2, B3 | `(a << (B2+B3)) \| (b << B3) \| c` | Extract with shifts & masks |
| Negative numbers | - | Add offset first | Subtract offset after |

<br>
<br>

---

```code```
