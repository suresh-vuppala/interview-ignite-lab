#include <vector>
using namespace std;

class CircularQueue {
private:
    vector<int> queue;
    int front, rear, size;
    
public:
    CircularQueue(int capacity) : queue(capacity), front(-1), rear(-1), size(capacity) {}
    
    bool enqueue(int value) {
        if ((rear + 1) % size == front) return false; // Full
        if (front == -1) front = 0;
        rear = (rear + 1) % size;
        queue[rear] = value;
        return true;
    }
    
    int dequeue() {
        if (front == -1) return -1; // Empty
        int value = queue[front];
        if (front == rear) front = rear = -1; // Last element
        else front = (front + 1) % size;
        return value;
    }
    
    int peek() {
        return front == -1 ? -1 : queue[front];
    }
};
