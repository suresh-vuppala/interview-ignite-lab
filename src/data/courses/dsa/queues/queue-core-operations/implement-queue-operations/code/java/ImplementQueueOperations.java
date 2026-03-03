class Queue {
    int[] arr;
    int front, rear, size;
    
    Queue(int capacity) {
        arr = new int[capacity];
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
    
    boolean isEmpty() {
        return size == 0;
    }
}