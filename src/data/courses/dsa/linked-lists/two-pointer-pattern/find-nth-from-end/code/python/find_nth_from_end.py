class Node:
    def __init__(self, d): self.data=d; self.next=None
class LL:
    def __init__(self): self.head=None
    def insert(self, d):
        if not self.head: self.head=Node(d)
        else: c=self.head; [c:=c.next for _ in iter(lambda:c.next,None)]; c.next=Node(d)
    def find_nth(self, n): f=s=self.head; [f:=f.next for _ in range(n) if f]; [s:=s.next or (f:=f.next) for _ in iter(lambda:f,None)]; return s
if __name__=="__main__": l=LL(); [l.insert(i) for i in range(1,6)]; print(f"2nd from end: {l.find_nth(2).data}")