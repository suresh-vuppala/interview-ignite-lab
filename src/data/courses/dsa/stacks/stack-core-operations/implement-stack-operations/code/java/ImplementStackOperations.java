class Stack {
    int[] arr;
    int top;
    
    Stack(int size) {
        arr = new int[size];
        top = -1;
    }
    
    void push(int x) {
        arr[++top] = x;
    }
    
    int pop() {
        return arr[top--];
    }
    
    int peek() {
        return arr[top];
    }
    
    boolean isEmpty() {
        return top == -1;
    }
}