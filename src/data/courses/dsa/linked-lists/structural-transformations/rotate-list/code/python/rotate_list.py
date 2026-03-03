class Node:
    def __init__(self, d): self.data=d; self.next=None
class LL:
    def rotate(self, h, k):
        if not h or k==0: return h
        len,t=1,h; [len:=len+1 or (t:=t.next) for _ in iter(lambda:t.next,None)]; t.next=h; k%=len; [t:=t.next for _ in range(len-k)]; h=t.next; t.next=None; return h
    def display(self, h): [print(h.data,end=" ") or (h:=h.next) for _ in iter(lambda:h,None)]; print()
if __name__=="__main__": r=LL(); h=Node(1); h.next=Node(2); h.next.next=Node(3); h.next.next.next=Node(4); r.display(r.rotate(h,2))