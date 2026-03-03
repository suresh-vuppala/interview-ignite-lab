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
    
    def reverse_between(self, m, n):
        if not self.head or m == n:
            return
        dummy = Node(0)
        dummy.next = self.head
        pre = dummy
        for _ in range(m - 1):
            pre = pre.next
        start = pre.next
        then = start.next
        for _ in range(n - m):
            start.next = then.next
            then.next = pre.next
            pre.next = then
            then = start.next
        self.head = dummy.next
    
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
    print("Original: ", end="")
    ll.display()
    ll.reverse_between(2, 4)
    print("After reversing 2 to 4: ", end="")
    ll.display()