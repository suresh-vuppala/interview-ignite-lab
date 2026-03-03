#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
    Node(int val) : data(val), next(nullptr) {}
};

class LinkedList {
    Node* head;
    
    Node* reverseHelper(Node* node) {
        if (!node || !node->next) return node;
        Node* newHead = reverseHelper(node->next);
        node->next->next = node;
        node->next = nullptr;
        return newHead;
    }
    
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
    
    void reverse() {
        head = reverseHelper(head);
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
    cout << "Original: ";
    list.display();
    list.reverse();
    cout << "Reversed: ";
    list.display();
    return 0;
}