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
    
    // 1. Create linked list from array
    void create(int arr[], int n) {
        if (n == 0) return;
        
        head = new Node(arr[0]);
        Node* current = head;
        
        for (int i = 1; i < n; i++) {
            current->next = new Node(arr[i]);
            current = current->next;
        }
    }
    
    // 2. Traverse and print
    void traverse() {
        Node* current = head;
        while (current != nullptr) {
            cout << current->data << " -> ";
            current = current->next;
        }
        cout << "null" << endl;
    }
    
    // 3. Count nodes
    int countNodes() {
        int count = 0;
        Node* current = head;
        while (current != nullptr) {
            count++;
            current = current->next;
        }
        return count;
    }
};

int main() {
    LinkedList list;
    int arr[] = {1, 2, 3, 4, 5};
    
    // Create linked list
    list.create(arr, 5);
    
    // Traverse and print
    cout << "List: ";
    list.traverse();
    
    // Count nodes
    cout << "Total nodes: " << list.countNodes() << endl;
    
    return 0;
}