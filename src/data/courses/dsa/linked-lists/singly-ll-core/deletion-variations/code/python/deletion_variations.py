class Node:
    def __init__(self, data):
        self.data = data
        self.next = None

class LinkedList:
    def __init__(self):
        self.head = None
    
    def insert(self, data):
        if not self.head:
            self.head = Node(data)
        else:
            curr = self.head
            while curr.next:
                curr = curr.next
            curr.next = Node(data)
    
    def delete_from_beginning(self):
        if self.head:
            self.head = self.head.next
    
    def delete_from_end(self):
        if not self.head or not self.head.next:
            self.head = None
            return
        curr = self.head
        while curr.next.next:
            curr = curr.next
        curr.next = None
    
    def delete_at_position(self, pos):
        if not self.head:
            return
        if pos == 0:
            self.head = self.head.next
            return
        curr = self.head
        for _ in range(pos - 1):
            if not curr:
                return
            curr = curr.next
        if curr and curr.next:
            curr.next = curr.next.next
    
    def delete_by_value(self, val):
        if not self.head:
            return
        if self.head.data == val:
            self.head = self.head.next
            return
        curr = self.head
        while curr.next and curr.next.data != val:
            curr = curr.next
        if curr.next:
            curr.next = curr.next.next
    
    def display(self):
        curr = self.head
        while curr:
            print(curr.data, end=" -> ")
            curr = curr.next
        print("None")

if __name__ == "__main__":
    ll = LinkedList()
    for i in range(1, 6):
        ll.insert(i)
    ll.display()
    ll.delete_from_beginning()
    ll.delete_from_end()
    ll.delete_at_position(1)
    ll.delete_by_value(3)
    ll.display()