class BitOps {
    boolean checkBit(int n, int i) {
        return (n & (1 << i)) != 0;
    }
    
    int setBit(int n, int i) {
        return n | (1 << i);
    }
    
    int unsetBit(int n, int i) {
        return n & ~(1 << i);
    }
    
    int toggleBit(int n, int i) {
        return n ^ (1 << i);
    }
}