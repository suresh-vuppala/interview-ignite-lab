#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
    Node(int val) : data(val), next(nullptr) {}
};

class LinkedList {
    Node* head;
public:
    LinkedList() : head(nullptr) {}
    
    void insert(int data) {
        if (!head) head = new Node(data);
        else {
            Node* curr = head;
            while (curr->next) curr = curr->next;
            curr->next = new Node(data);
        }
    }
    
    void createCycle(int pos) {
        if (!head) return;
        Node *tail = head, *cycleNode = nullptr;
        int index = 0;
        while (tail->next) {
            if (index == pos) cycleNode = tail;
            tail = tail->next;
            index++;
        }
        if (cycleNode) tail->next = cycleNode;
    }
    
    bool hasCycle() {
        if (!head) return false;
        Node *slow = head, *fast = head;
        while (fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;
            if (slow == fast) return true;
        }
        return false;
    }
};

int main() {
    LinkedList list;
    for (int i = 1; i <= 5; i++) list.insert(i);
    cout << "Has cycle: " << list.hasCycle() << endl;
    list.createCycle(2);
    cout << "Has cycle after creating: " << list.hasCycle() << endl;
    return 0;
}