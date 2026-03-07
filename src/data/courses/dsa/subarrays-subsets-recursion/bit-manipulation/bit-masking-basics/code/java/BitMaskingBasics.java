// Time: O(1) per operation | Space: O(1)

class Solution {
    // Demonstrate all 6 bitwise operators
    public void demonstrateOperators(int a, int b) {
        System.out.println("AND: " + a + " & " + b + " = " + (a & b));
        System.out.println("OR: " + a + " | " + b + " = " + (a | b));
        System.out.println("XOR: " + a + " ^ " + b + " = " + (a ^ b));
        System.out.println("NOT: ~" + a + " = " + (~a));
        System.out.println("Left Shift: " + a + " << 2 = " + (a << 2));
        System.out.println("Right Shift: " + a + " >> 1 = " + (a >> 1));
    }
    
    // Basic bit operations
    public boolean checkBit(int n, int k) {
        return (n & (1 << k)) != 0;
    }
    
    public int setBit(int n, int k) {
        return n | (1 << k);
    }
    
    public int clearBit(int n, int k) {
        return n & ~(1 << k);
    }
    
    public int toggleBit(int n, int k) {
        return n ^ (1 << k);
    }
    
    public int rightmostSetBit(int n) {
        return n & -n;
    }
    
    public int clearRightmostSetBit(int n) {
        return n & (n - 1);
    }
    
    public boolean isPowerOf2(int n) {
        return n > 0 && (n & (n - 1)) == 0;
    }
    
    public int countSetBits(int n) {
        int count = 0;
        while (n > 0) {
            n &= (n - 1);
            count++;
        }
        return count;
    }
    
    public int findSingleNumber(int[] arr) {
        int result = 0;
        for (int num : arr) {
            result ^= num;
        }
        return result;
    }
}