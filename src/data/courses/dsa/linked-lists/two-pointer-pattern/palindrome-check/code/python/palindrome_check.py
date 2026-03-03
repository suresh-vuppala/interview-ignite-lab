class Node:
    def __init__(self, d): self.data=d; self.next=None
class LL:
    def __init__(self): self.head=None
    def insert(self, d):
        if not self.head: self.head=Node(d)
        else: c=self.head; [c:=c.next for _ in iter(lambda:c.next,None)]; c.next=Node(d)
    def reverse(self, h): p,c=None,h; [(c.next,p,c):=(p,c,c.next) for _ in iter(lambda:c,None)]; return p
    def is_palindrome(self): s=f=self.head; [s:=s.next or (f:=f.next.next) for _ in iter(lambda:f and f.next,None)]; h2=self.reverse(s); p1,p2=self.head,h2; return all(p1.data==p2.data and (p1:=p1.next) and (p2:=p2.next) for _ in iter(lambda:p2,None))
if __name__=="__main__": l=LL(); [l.insert(i) for i in [1,2,3,2,1]]; print(f"Is palindrome: {l.is_palindrome()}")