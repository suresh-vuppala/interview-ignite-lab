class CircularQueue {
    int* arr;
    int front, rear, size, capacity;
public:
    CircularQueue(int k) {
        arr = new int[k];
        capacity = k;
        front = rear = -1;
        size = 0;
    }
    
    bool enqueue(int x) {
        if (isFull()) return false;
        if (isEmpty()) front = 0;
        rear = (rear + 1) % capacity;
        arr[rear] = x;
        size++;
        return true;
    }
    
    bool dequeue() {
        if (isEmpty()) return false;
        if (front == rear) front = rear = -1;
        else front = (front + 1) % capacity;
        size--;
        return true;
    }
    
    bool isEmpty() { return size == 0; }
    bool isFull() { return size == capacity; }
};