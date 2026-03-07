// Time: O(1) | Space: O(1)

class Solution {
public:
    bool checkBit(int n, int k) {
        return (n & (1 << k)) != 0;
    }
    
    int setBit(int n, int k) {
        return n | (1 << k);
    }
    
    int unsetBit(int n, int k) {
        return n & ~(1 << k);
    }
    
    int toggleBit(int n, int k) {
        return n ^ (1 << k);
    }
};