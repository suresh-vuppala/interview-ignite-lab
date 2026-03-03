class Deque {
    int* arr;
    int front, rear, size, capacity;
public:
    Deque(int k) {
        arr = new int[k];
        capacity = k;
        front = rear = -1;
        size = 0;
    }
    
    bool insertFront(int x) {
        if (size == capacity) return false;
        if (front == -1) front = rear = 0;
        else front = (front - 1 + capacity) % capacity;
        arr[front] = x;
        size++;
        return true;
    }
    
    bool insertRear(int x) {
        if (size == capacity) return false;
        if (rear == -1) front = rear = 0;
        else rear = (rear + 1) % capacity;
        arr[rear] = x;
        size++;
        return true;
    }
    
    bool deleteFront() {
        if (size == 0) return false;
        front = (front + 1) % capacity;
        size--;
        return true;
    }
    
    bool deleteRear() {
        if (size == 0) return false;
        rear = (rear - 1 + capacity) % capacity;
        size--;
        return true;
    }
};