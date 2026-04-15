// ============================================================
// Solution 1: Evaluate recurrence by expansion — O(N) or O(2^N)
// ============================================================
class Solution1 {
public:
    // T(n) = T(n-1) + O(1) → O(N) linear
    int linearRecurrence(int n) {
        if (n <= 0) return 1;
        return linearRecurrence(n - 1) + 1; // Each call does O(1) work
    }
    // T(n) = 2*T(n-1) + O(1) → O(2^N) exponential
    int exponentialRecurrence(int n) {
        if (n <= 0) return 1;
        return exponentialRecurrence(n - 1) + exponentialRecurrence(n - 1) + 1;
    }
};

// ============================================================
// Solution 2: Master Theorem application — O(1) analysis
// ============================================================
class Solution2 {
public:
    // T(n) = a*T(n/b) + O(n^d)
    // Case 1: d < log_b(a) → O(n^log_b(a))
    // Case 2: d == log_b(a) → O(n^d * log n)
    // Case 3: d > log_b(a) → O(n^d)
    //
    // Example: Merge Sort T(n) = 2T(n/2) + O(n)
    // a=2, b=2, d=1 → log_2(2)=1=d → Case 2 → O(n log n)
    int mergeSort(int* arr, int n) { return 0; /* O(n log n) by Master Theorem */ }
};
