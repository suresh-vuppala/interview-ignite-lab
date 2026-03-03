class Node:
    def __init__(self, d): self.data=d; self.next=None
class LL:
    def get_mid(self, h): s,f=h,h.next; [s:=s.next or (f:=f.next.next) for _ in iter(lambda:f and f.next,None)]; return s
    def merge(self, l1, l2): d=Node(0); c=d; [(c.next,l1,c):=(l1,l1.next,c.next) if l1.data<l2.data else (c.next,l2,c):=(l2,l2.next,c.next) for _ in iter(lambda:l1 and l2,None)]; c.next=l1 or l2; return d.next
    def sort_list(self, h):
        if not h or not h.next: return h
        m=self.get_mid(h); r=m.next; m.next=None; return self.merge(self.sort_list(h),self.sort_list(r))
    def display(self, h): [print(h.data,end=" ") or (h:=h.next) for _ in iter(lambda:h,None)]; print()
if __name__=="__main__": s=LL(); h=Node(4); h.next=Node(2); h.next.next=Node(1); h.next.next.next=Node(3); s.display(s.sort_list(h))