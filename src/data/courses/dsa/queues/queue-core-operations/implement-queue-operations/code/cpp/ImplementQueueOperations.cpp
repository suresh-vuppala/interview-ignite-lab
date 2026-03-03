class Queue {
    int* arr;
    int front, rear, size, capacity;
public:
    Queue(int cap) {
        arr = new int[cap];
        capacity = cap;
        front = 0;
        rear = -1;
        size = 0;
    }
    
    void enqueue(int x) {
        arr[++rear] = x;
        size++;
    }
    
    int dequeue() {
        size--;
        return arr[front++];
    }
    
    int peek() {
        return arr[front];
    }
    
    bool isEmpty() {
        return size == 0;
    }
};