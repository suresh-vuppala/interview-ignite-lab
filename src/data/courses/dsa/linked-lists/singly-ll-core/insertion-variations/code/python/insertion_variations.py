class Node:
    def __init__(self, data):
        self.data = data
        self.next = None

class LinkedList:
    def __init__(self):
        self.head = None
    
    def insert_at_beginning(self, data):
        new_node = Node(data)
        new_node.next = self.head
        self.head = new_node
    
    def insert_at_end(self, data):
        new_node = Node(data)
        if not self.head:
            self.head = new_node
            return
        current = self.head
        while current.next:
            current = current.next
        current.next = new_node
    
    def insert_at_position(self, data, position):
        if position == 0:
            self.insert_at_beginning(data)
            return
        new_node = Node(data)
        current = self.head
        for _ in range(position - 1):
            if not current:
                print("Invalid position")
                return
            current = current.next
        if not current:
            print("Invalid position")
            return
        new_node.next = current.next
        current.next = new_node
    
    def insert_after_node(self, target_data, new_data):
        current = self.head
        while current and current.data != target_data:
            current = current.next
        if not current:
            print("Node not found")
            return
        new_node = Node(new_data)
        new_node.next = current.next
        current.next = new_node
    
    def display(self):
        current = self.head
        while current:
            print(current.data, end=" -> ")
            current = current.next
        print("None")

if __name__ == "__main__":
    ll = LinkedList()
    ll.insert_at_end(3)
    ll.insert_at_end(5)
    ll.insert_at_beginning(1)
    ll.insert_at_position(2, 1)
    ll.insert_after_node(3, 4)
    ll.display()