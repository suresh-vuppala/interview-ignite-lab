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
    
    def find_middle_two_pass(self):
        count = 0
        curr = self.head
        while curr:
            count += 1
            curr = curr.next
        curr = self.head
        for _ in range(count // 2):
            curr = curr.next
        return curr.data
    
    def find_middle_slow_fast(self):
        slow = fast = self.head
        while fast and fast.next:
            slow = slow.next
            fast = fast.next.next
        return slow.data
    
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
    print(f"Middle (Two-Pass): {ll.find_middle_two_pass()}")
    print(f"Middle (Slow-Fast): {ll.find_middle_slow_fast()}")