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
    
    Node* detectCycleStart() {
        if (!head) return nullptr;
        Node *slow = head, *fast = head;
        while (fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;
            if (slow == fast) {
                slow = head;
                while (slow != fast) {
                    slow = slow->next;
                    fast = fast->next;
                }
                return slow;
            }
        }
        return nullptr;
    }
};

int main() {
    LinkedList list;
    for (int i = 1; i <= 5; i++) list.insert(i);
    list.createCycle(2);
    Node* start = list.detectCycleStart();
    cout << "Cycle starts at: " << (start ? to_string(start->data) : "No cycle") << endl;
    return 0;
}