#include <vector>
using namespace std;
// ============================================================
// Solution 1: Check each number individually — O(N√N)
// ============================================================
class Solution1 {
    bool isPrime(int n) {
        if (n <= 1) return false;
        for (int i = 2; (long long)i * i <= n; i++) if (n % i == 0) return false;
        return true;
    }
public:
    vector<int> allPrimes(int n) {
        vector<int> primes;
        for (int i = 2; i <= n; i++) if (isPrime(i)) primes.push_back(i);
        return primes; // O(N * √N)
    }
};

// ============================================================
// Solution 2: Sieve of Eratosthenes — O(N log log N)
// ============================================================
class Solution2 {
public:
    vector<int> allPrimes(int n) {
        vector<bool> is_prime(n + 1, true);
        is_prime[0] = is_prime[1] = false;
        for (int i = 2; (long long)i * i <= n; i++)
            if (is_prime[i])
                for (int j = i * i; j <= n; j += i) is_prime[j] = false; // Mark multiples
        vector<int> primes;
        for (int i = 2; i <= n; i++) if (is_prime[i]) primes.push_back(i);
        return primes; // O(N log log N) — near-linear!
    }
};
