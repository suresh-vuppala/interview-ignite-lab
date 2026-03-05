class CircularQueue {
    private int[] queue;
    private int front, rear, size;
    
    public CircularQueue(int capacity) {
        queue = new int[capacity];
        front = rear = -1;
        size = capacity;
    }
    
    public boolean enqueue(int value) {
        if ((rear + 1) % size == front) return false; // Full
        if (front == -1) front = 0;
        rear = (rear + 1) % size;
        queue[rear] = value;
        return true;
    }
    
    public int dequeue() {
        if (front == -1) return -1; // Empty
        int value = queue[front];
        if (front == rear) front = rear = -1; // Last element
        else front = (front + 1) % size;
        return value;
    }
    
    public int peek() {
        return front == -1 ? -1 : queue[front];
    }
}
