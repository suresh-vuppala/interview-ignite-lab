class Recursion {
    // Fibonacci recursion tree
    int fib(int n) {
        if (n <= 1) return n;
        return fib(n-1) + fib(n-2);
    }
    
    // Print recursion tree
    void printTree(int n, String indent) {
        System.out.println(indent + "fib(" + n + ")");
        if (n > 1) {
            printTree(n-1, indent + "  ");
            printTree(n-2, indent + "  ");
        }
    }
}