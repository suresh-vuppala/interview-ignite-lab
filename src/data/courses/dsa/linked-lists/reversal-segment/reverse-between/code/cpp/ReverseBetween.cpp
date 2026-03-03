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
    
    void reverseBetween(int m, int n) {
        if (!head || m == n) return;
        Node* dummy = new Node(0);
        dummy->next = head;
        Node* pre = dummy;
        for (int i = 1; i < m; i++) pre = pre->next;
        Node* start = pre->next;
        Node* then = start->next;
        for (int i = 0; i < n - m; i++) {
            start->next = then->next;
            then->next = pre->next;
            pre->next = then;
            then = start->next;
        }
        head = dummy->next;
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
    list.reverseBetween(2, 4);
    cout << "After reversing 2 to 4: ";
    list.display();
    return 0;
}