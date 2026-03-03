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
        if (size == capacity) return false;
        if (front == -1) front = 0;
        rear = (rear + 1) % capacity;
        arr[rear] = x;
        size++;
        return true;
    }
    
    boolean dequeue() {
        if (size == 0) return false;
        front = (front + 1) % capacity;
        size--;
        return true;
    }
}