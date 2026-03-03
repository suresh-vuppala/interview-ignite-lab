#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
    Node(int val) : data(val), next(nullptr) {}
};

class LinkedList {
private:
    Node* head;
public:
    LinkedList() : head(nullptr) {}
    
    void insertAtBeginning(int data) {
        Node* newNode = new Node(data);
        newNode->next = head;
        head = newNode;
    }
    
    void insertAtEnd(int data) {
        Node* newNode = new Node(data);
        if (!head) {
            head = newNode;
            return;
        }
        Node* current = head;
        while (current->next) current = current->next;
        current->next = newNode;
    }
    
    void insertAtPosition(int data, int position) {
        if (position == 0) {
            insertAtBeginning(data);
            return;
        }
        Node* newNode = new Node(data);
        Node* current = head;
        for (int i = 0; i < position - 1 && current; i++) {
            current = current->next;
        }
        if (!current) {
            cout << "Invalid position" << endl;
            return;
        }
        newNode->next = current->next;
        current->next = newNode;
    }
    
    void insertAfterNode(int targetData, int newData) {
        Node* current = head;
        while (current && current->data != targetData) {
            current = current->next;
        }
        if (!current) {
            cout << "Node not found" << endl;
            return;
        }
        Node* newNode = new Node(newData);
        newNode->next = current->next;
        current->next = newNode;
    }
    
    void display() {
        Node* current = head;
        while (current) {
            cout << current->data << " -> ";
            current = current->next;
        }
        cout << "null" << endl;
    }
};

int main() {
    LinkedList list;
    list.insertAtEnd(3);
    list.insertAtEnd(5);
    list.insertAtBeginning(1);
    list.insertAtPosition(2, 1);
    list.insertAfterNode(3, 4);
    list.display();
    return 0;
}