#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
    Node(int val) : data(val), next(nullptr) {}
};

class LinkedList {
    Node* head;
    
    Node* reverseKHelper(Node* head, int k) {
        Node* curr = head;
        int count = 0;
        while (curr && count < k) {
            curr = curr->next;
            count++;
        }
        if (count == k) {
            curr = reverseKHelper(curr, k);
            while (count-- > 0) {
                Node* tmp = head->next;
                head->next = curr;
                curr = head;
                head = tmp;
            }
            head = curr;
        }
        return head;
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
    
    void reverseKGroups(int k) {
        head = reverseKHelper(head, k);
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
    for (int i = 1; i <= 8; i++) list.insert(i);
    cout << "Original: ";
    list.display();
    list.reverseKGroups(3);
    cout << "After reversing in groups of 3: ";
    list.display();
    return 0;
}