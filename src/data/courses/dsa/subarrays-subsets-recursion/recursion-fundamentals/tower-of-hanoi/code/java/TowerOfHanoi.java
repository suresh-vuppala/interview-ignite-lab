// Time: O(2^N), Space: O(N)

class Solution {
    public void towerOfHanoi(int n, char source, char destination, char auxiliary) {
        if (n == 1) {
            System.out.println("Move disk 1 from " + source + " to " + destination);
            return;
        }
        towerOfHanoi(n - 1, source, auxiliary, destination);
        System.out.println("Move disk " + n + " from " + source + " to " + destination);
        towerOfHanoi(n - 1, auxiliary, destination, source);
    }
}

public class TowerOfHanoi {
    public static void main(String[] args) {
        Solution sol = new Solution();
        int n = 3;
        sol.towerOfHanoi(n, 'A', 'C', 'B');
    }
}
