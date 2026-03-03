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
    
    bool searchByValue(int val) {
        Node* curr = head;
        while (curr) {
            if (curr->data == val) return true;
            curr = curr->next;
        }
        return false;
    }
    
    int searchByPosition(int pos) {
        Node* curr = head;
        for (int i = 0; i < pos && curr; i++) curr = curr->next;
        return curr ? curr->data : -1;
    }
    
    void updateByPosition(int pos, int newVal) {
        Node* curr = head;
        for (int i = 0; i < pos && curr; i++) curr = curr->next;
        if (curr) curr->data = newVal;
    }
    
    void updateByValue(int oldVal, int newVal) {
        Node* curr = head;
        while (curr) {
            if (curr->data == oldVal) {
                curr->data = newVal;
                return;
            }
            curr = curr->next;
        }
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
    cout << "Search 3: " << list.searchByValue(3) << endl;
    cout << "Value at pos 2: " << list.searchByPosition(2) << endl;
    list.updateByPosition(1, 10);
    list.updateByValue(5, 50);
    list.display();
    return 0;
}