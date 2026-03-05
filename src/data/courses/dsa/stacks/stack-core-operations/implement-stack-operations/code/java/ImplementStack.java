class Stack {
    private int[] arr;
    private int top;
    
    public Stack(int size) {
        arr = new int[size];
        top = -1;
    }
    
    public void push(int val) {
        arr[++top] = val;
    }
    
    public int pop() {
        return arr[top--];
    }
    
    public int peek() {
        return arr[top];
    }
    
    public boolean isEmpty() {
        return top == -1;
    }
    
    public int size() {
        return top + 1;
    }
}
