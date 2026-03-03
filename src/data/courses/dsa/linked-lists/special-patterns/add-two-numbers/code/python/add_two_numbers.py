class Node:
    def __init__(self, d): self.data=d; self.next=None
class LL:
    def add(self, l1, l2): d=Node(0); c=d; carry=0; [(c.next,carry,c,l1,l2):=(Node((carry+(l1.data if l1 else 0)+(l2.data if l2 else 0))%10),(carry+(l1.data if l1 else 0)+(l2.data if l2 else 0))//10,c.next,l1.next if l1 else None,l2.next if l2 else None) for _ in iter(lambda:l1 or l2 or carry,None)]; return d.next
    def display(self, h): [print(h.data,end="") or (h:=h.next) for _ in iter(lambda:h,None)]; print()
if __name__=="__main__": at=LL(); l1=Node(2); l1.next=Node(4); l1.next.next=Node(3); l2=Node(5); l2.next=Node(6); l2.next.next=Node(4); at.display(at.add(l1,l2))