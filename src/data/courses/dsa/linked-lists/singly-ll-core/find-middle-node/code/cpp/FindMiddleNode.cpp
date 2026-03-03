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
    
    int findMiddleTwoPass() {
        int count = 0;
        Node* curr = head;
        while (curr) {
            count++;
            curr = curr->next;
        }
        curr = head;
        for (int i = 0; i < count / 2; i++) curr = curr->next;
        return curr->data;
    }
    
    int findMiddleSlowFast() {
        Node* slow = head;
        Node* fast = head;
        while (fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;
        }
        return slow->data;
    }
    
    void display() {
        Node* curr = head;
        while (curr) {
            cout << curr->data << " -> ";
            curr = curr->next;
        }
        cout << "null" << endl;
    }
};

int main() {
    LinkedList list;
    for (int i = 1; i <= 5; i++) list.insert(i);
    list.display();
    cout << "Middle (Two-Pass): " << list.findMiddleTwoPass() << endl;
    cout << "Middle (Slow-Fast): " << list.findMiddleSlowFast() << endl;
    return 0;
}