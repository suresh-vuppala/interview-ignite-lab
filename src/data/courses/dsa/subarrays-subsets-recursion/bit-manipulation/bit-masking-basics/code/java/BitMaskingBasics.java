class BitMask {
    void basics() {
        int a = 5, b = 3;
        System.out.println(a & b);  // AND
        System.out.println(a | b);  // OR
        System.out.println(a ^ b);  // XOR
        System.out.println(~a);     // NOT
        System.out.println(a << 1); // Left shift
        System.out.println(a >> 1); // Right shift
    }
}