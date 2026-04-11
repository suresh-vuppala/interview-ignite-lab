class Solution {
public:
    // O(32) — XOR for addition without carry, AND+shift for carry
    int getSum(int a, int b) {
        while (b != 0) {
            int carry = a & b;     // Carry: both bits are 1
            a = a ^ b;             // Sum without carry
            b = carry << 1;        // Carry shifted left
        }
        return a;
    }
};