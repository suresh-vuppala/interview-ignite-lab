class Stack {
    int* arr;
    int top, capacity;
public:
    Stack(int size) {
        arr = new int[size];
        capacity = size;
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
    
    bool isEmpty() {
        return top == -1;
    }
};