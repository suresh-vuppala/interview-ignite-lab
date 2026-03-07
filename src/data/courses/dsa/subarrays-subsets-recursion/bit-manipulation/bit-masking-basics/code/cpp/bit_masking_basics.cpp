// Time: O(1) per operation | Space: O(1)

#include <vector>
#include <iostream>
using namespace std;

class Solution {
public:
    // Demonstrate all 6 bitwise operators
    void demonstrateOperators(int a, int b) {
        cout << "AND: " << a << " & " << b << " = " << (a & b) << endl;
        cout << "OR: " << a << " | " << b << " = " << (a | b) << endl;
        cout << "XOR: " << a << " ^ " << b << " = " << (a ^ b) << endl;
        cout << "NOT: ~" << a << " = " << (~a) << endl;
        cout << "Left Shift: " << a << " << 2 = " << (a << 2) << endl;
        cout << "Right Shift: " << a << " >> 1 = " << (a >> 1) << endl;
    }
    
    // Basic bit operations
    bool checkBit(int n, int k) {
        return (n & (1 << k)) != 0;
    }
    
    int setBit(int n, int k) {
        return n | (1 << k);
    }
    
    int clearBit(int n, int k) {
        return n & ~(1 << k);
    }
    
    int toggleBit(int n, int k) {
        return n ^ (1 << k);
    }
    
    int rightmostSetBit(int n) {
        return n & -n;
    }
    
    int clearRightmostSetBit(int n) {
        return n & (n - 1);
    }
    
    bool isPowerOf2(int n) {
        return n > 0 && (n & (n - 1)) == 0;
    }
    
    int countSetBits(int n) {
        int count = 0;
        while (n > 0) {
            n &= (n - 1);
            count++;
        }
        return count;
    }
    
    int findSingleNumber(vector<int>& arr) {
        int result = 0;
        for (int num : arr) {
            result ^= num;
        }
        return result;
    }
};