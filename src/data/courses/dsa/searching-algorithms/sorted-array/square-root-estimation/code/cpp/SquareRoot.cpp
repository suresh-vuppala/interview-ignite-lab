#include <iostream>
using namespace std;

/**
 * Find integer square root (floor of sqrt)
 * Time: O(log n), Space: O(1)
 */
int squareRoot(int n) {
    if (n < 2) return n;
    
    int left = 0, right = n;
    
    while (left <= right) {
        int mid = left + (right - left) / 2;
        long long square = (long long) mid * mid;
        
        if (square == n) {
            return mid;
        } else if (square < n) {
            left = mid + 1;  // Answer is larger
        } else {
            right = mid - 1; // Answer is smaller
        }
    }
    
    return right;  // Largest integer whose square <= n
}

int main() {
    cout << squareRoot(16) << endl;   // Output: 4
    cout << squareRoot(17) << endl;   // Output: 4
    cout << squareRoot(25) << endl;   // Output: 5
    
    return 0;
}
