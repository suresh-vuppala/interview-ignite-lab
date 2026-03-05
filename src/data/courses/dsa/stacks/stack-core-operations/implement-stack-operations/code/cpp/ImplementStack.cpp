class Stack {
    int* arr;
    int top;
    int capacity;
public:
    Stack(int size) {
        arr = new int[size];
        capacity = size;
        top = -1;
    }
    
    void push(int val) {
        arr[++top] = val;
    }
    
    int pop() {
        return arr[top--];
    }
    
    int peek() {
        return arr[top];
    }
    
    bool isEmpty() {
        return top == -1;
    }
    
    int size() {
        return top + 1;
    }
};
