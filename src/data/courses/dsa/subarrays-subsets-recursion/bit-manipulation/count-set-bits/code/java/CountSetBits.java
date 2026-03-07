// Time: O(log N) naive, O(K) Brian Kernighan | Space: O(1)

class Solution {
    public int countSetBitsNaive(int n) {
        int count = 0;
        while (n > 0) {
            count += n & 1;
            n >>= 1;
        }
        return count;
    }
    
    public int countSetBitsOptimal(int n) {
        int count = 0;
        while (n > 0) {
            n &= (n - 1);
            count++;
        }
        return count;
    }
}