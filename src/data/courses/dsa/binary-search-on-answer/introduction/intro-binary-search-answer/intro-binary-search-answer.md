## Binary Search on Answer — Search the Solution Space

Instead of searching an array, binary search on the **answer space** itself. If you can frame a problem as "what is the minimum/maximum X such that some condition holds?", you can binary search on X.

<br>

---

## 🧠 Universal Steps for Binary Search on Answer

Follow these 8 steps to solve any Binary Search on Answer problem:

<br>

### **1️⃣ Check Monotonicity (Can we apply BS?)**

> Can you form `f(x)` that is monotonic?

```text
FFFFFTTTTT   or   TTTTTTFFFF
```

**✅ Works:**
- Koko Bananas → `f(speed)` is monotonic
- Aggressive Cows → `f(distance)` is monotonic
- Allocate Pages → `f(max pages)` is monotonic
- First Bad Version → `f(version)` is monotonic

**❌ Fails:**
- Trinkets problem
Score is non-linear. When frequency crosses S, contribution drops from S to 0. Increasing window size can both increase or decrease score. Not monotonic.

- Maximum subarray sum (Kadane)
No true/false feasibility boundary. It is a direct optimization over structure, not a monotonic decision problem. Binary search is not applicable.

- Sliding window problems
Validity depends on element positions, not just size. Increasing window size can make a valid window invalid again. Not monotonic.

<br>

### **2️⃣ Define Search Space**

> Where can the answer lie?

```text
low  → minimum possible answer
high → maximum possible answer
```

**Examples:**
- Koko Bananas → `[1, max(piles)]`
- Aggressive Cows → `[1, max_distance]`
- Allocate Pages → `[max(arr), sum(arr)]`
- Square Root → `[0, x]`
- Sorted Array Search → `[0, n-1]`

<br>

### **3️⃣ Define Check Function**

> "If answer = x, is it valid?"

```text
f(x) = true/false
```

**Examples:**
- Koko → Can finish eating all bananas in H hours?
- Cows → Can place all cows with distance ≥ x?
- Pages → Can allocate books within x max pages?
- Shipping → Can ship all packages in D days?
- First Bad Version → Is this version bad?

<br>

### **4️⃣ Decide Goal (Boundary)**

| Goal | Meaning | Pattern |
|------|---------|----------|
| **Min valid** | First TRUE | Minimize |
| **Max valid** | Last TRUE | Maximize |

**Examples:**
- Koko → **min speed** → first TRUE
- Cows → **max distance** → last TRUE
- Pages → **min max pages** → first TRUE
- First Bad Version → first TRUE

<br>

### **5️⃣ Calculate Mid Safely**

```cpp
mid = low + (high - low) / 2;
```

**Why?** Avoids integer overflow for large ranges.

**Examples:**
- `[1, 10] → mid = 5`
- `[5, 6] → mid = 5`
- `[1000000000, 2000000000] → safe calculation`

<br>

### **6️⃣ Apply Decision (Shrink Space)**

**If `f(mid) == true`:**
- Store answer
- Move depending on goal (minimize → go left, maximize → go right)

**If `f(mid) == false`:**
- Go opposite side

**Examples:**

**Koko (minimize speed):**
```text
speed works → try smaller → move left (high = mid - 1)
```

**Cows (maximize distance):**
```text
distance works → try bigger → move right (low = mid + 1)
```

**First Bad Version:**
```text
mid is bad → go left to find first bad
```

<br>

### **7️⃣ Loop Until Done**

```cpp
while (low <= high) {
    // binary search logic
}
```

**Example Flow:**
```text
low=1, high=10 → mid=5 → shrink
low=1, high=4  → mid=2 → shrink
low=3, high=4  → mid=3 → shrink
low=4, high=4  → mid=4 → done
```

<br>

### **8️⃣ Return Answer**

```cpp
return ans;
```

**Examples:**
- Koko → minimum speed found
- Cows → maximum distance found
- Pages → minimum max pages found
- Lower Bound → index found
- Square Root → integer value found

<br>

---

## 🔥 Quick Pattern Mapping

| Problem | f(x) Check Function | Goal | Search Space |
|---------|---------------------|------|---------------|
| Koko Bananas | Can finish eating? | **Minimize** speed | `[1, max(piles)]` |
| Aggressive Cows | Can place cows? | **Maximize** distance | `[1, max_distance]` |
| Allocate Pages | Can allocate books? | **Minimize** max pages | `[max(arr), sum(arr)]` |
| Ship Packages | Can ship in D days? | **Minimize** capacity | `[max(weights), sum(weights)]` |
| First Bad Version | Is version bad? | Find **first TRUE** | `[1, n]` |
| Search in Array | arr[mid] vs target | Find **exact match** | `[0, n-1]` |

<br>


## Three Main Categories

| Category | Pattern | Example |
|----------|---------|---------|
| **Minimize Maximum** | "What's the smallest max load?" | Split Array Largest Sum, Allocate Pages |
| **Maximize Minimum** | "What's the largest min distance?" | Aggressive Cows, Magnetic Force |
| **Capacity/Rate** | "What's the min rate to finish in time?" | Koko Bananas, Ship Packages |

<br>

---

## Template

```cpp
int binarySearchOnAnswer(int minPossible, int maxPossible) {
    int low = minPossible;
    int high = maxPossible;
    int ans = -1;
    
    while (low <= high) {
        int mid = low + (high - low) / 2;
        
        if (canAchieve(mid)) {
            ans = mid;           // Store potential answer
            high = mid - 1;      // Try to minimize (for minimize problems)
            // OR
            // low = mid + 1;    // Try to maximize (for maximize problems)
        } else {
            low = mid + 1;       // For minimize problems
            // OR
            // high = mid - 1;   // For maximize problems
        }
    }
    
    return ans;
}

bool canAchieve(int mid) {
    // Check if 'mid' is a valid answer
    // Return true if condition is satisfied
    return true/false;
}
```

<br>

---

## FAANG Frequency

This pattern appears in **~15% of Google interviews** and is a favorite because it tests both binary search mastery and the ability to write a clean feasibility check function.

<br>

---

## All Possible Edge Cases
1. **N/A — introductory overview**
