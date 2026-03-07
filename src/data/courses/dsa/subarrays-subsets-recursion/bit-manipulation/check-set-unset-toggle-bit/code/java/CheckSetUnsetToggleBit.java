// Time: O(1) | Space: O(1)

class Solution {
    public boolean checkBit(int n, int k) {
        return (n & (1 << k)) != 0;
    }
    
    public int setBit(int n, int k) {
        return n | (1 << k);
    }
    
    public int unsetBit(int n, int k) {
        return n & ~(1 << k);
    }
    
    public int toggleBit(int n, int k) {
        return n ^ (1 << k);
    }
}