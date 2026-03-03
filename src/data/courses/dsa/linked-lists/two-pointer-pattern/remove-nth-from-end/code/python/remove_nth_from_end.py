class Node:
    def __init__(self, d): self.data=d; self.next=None
class LL:
    def __init__(self): self.head=None
    def insert(self, d):
        if not self.head: self.head=Node(d)
        else: c=self.head; [c:=c.next for _ in iter(lambda:c.next,None)]; c.next=Node(d)
    def remove_nth(self, n): d=Node(0); d.next=self.head; f=s=d; [f:=f.next for _ in range(n+1)]; [s:=s.next or (f:=f.next) for _ in iter(lambda:f,None)]; s.next=s.next.next; self.head=d.next
    def display(self): c=self.head; [print(c.data,end=" ") or (c:=c.next) for _ in iter(lambda:c,None)]; print()
if __name__=="__main__": l=LL(); [l.insert(i) for i in range(1,6)]; l.remove_nth(2); l.display()