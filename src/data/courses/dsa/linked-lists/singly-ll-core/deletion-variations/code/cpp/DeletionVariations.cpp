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
    
    void deleteFromBeginning() {
        if (head) head = head->next;
    }
    
    void deleteFromEnd() {
        if (!head || !head->next) {
            head = nullptr;
            return;
        }
        Node* curr = head;
        while (curr->next->next) curr = curr->next;
        curr->next = nullptr;
    }
    
    void deleteAtPosition(int pos) {
        if (!head) return;
        if (pos == 0) {
            head = head->next;
            return;
        }
        Node* curr = head;
        for (int i = 0; i < pos - 1 && curr; i++) curr = curr->next;
        if (curr && curr->next) curr->next = curr->next->next;
    }
    
    void deleteByValue(int val) {
        if (!head) return;
        if (head->data == val) {
            head = head->next;
            return;
        }
        Node* curr = head;
        while (curr->next && curr->next->data != val) curr = curr->next;
        if (curr->next) curr->next = curr->next->next;
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
    list.deleteFromBeginning();
    list.deleteFromEnd();
    list.deleteAtPosition(1);
    list.deleteByValue(3);
    list.display();
    return 0;
}