class CircularQueue {
    int[] arr;
    int front, rear, size, capacity;
    
    CircularQueue(int k) {
        arr = new int[k];
        capacity = k;
        front = rear = -1;
        size = 0;
    }
    
    boolean enqueue(int x) {
        if (isFull()) return false;
        if (isEmpty()) front = 0;
        rear = (rear + 1) % capacity;
        arr[rear] = x;
        size++;
        return true;
    }
    
    boolean dequeue() {
        if (isEmpty()) return false;
        if (front == rear) front = rear = -1;
        else front = (front + 1) % capacity;
        size--;
        return true;
    }
    
    boolean isEmpty() { return size == 0; }
    boolean isFull() { return size == capacity; }
}