class Node:
    def __init__(self, d): self.data=d; self.next=None
class LL:
    def reverse(self, h): p,c=None,h; [(c.next,p,c):=(p,c,c.next) for _ in iter(lambda:c,None)]; return p
    def merge(self, l1, l2): [(l1.next,l2.next,l1,l2):=(l2,l1.next,l1.next,l2.next) for _ in iter(lambda:l2,None)]
    def reorder(self, h):
        if not h or not h.next: return
        s,f=h,h; [s:=s.next or (f:=f.next.next) for _ in iter(lambda:f.next and f.next.next,None)]; h2=self.reverse(s.next); s.next=None; self.merge(h,h2)
    def display(self, h): [print(h.data,end=" ") or (h:=h.next) for _ in iter(lambda:h,None)]; print()
if __name__=="__main__": r=LL(); h=Node(1); h.next=Node(2); h.next.next=Node(3); h.next.next.next=Node(4); r.reorder(h); r.display(h)