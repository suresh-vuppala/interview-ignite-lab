#include <vector>
using namespace std;
// ============================================================
// Solution 1: Dynamic array with modular indexing — wastes resize
// ============================================================
class Solution1 {
    vector<int> data;
    int front_, rear_, sz, cap;
public:
    Solution1(int k) : data(k), front_(0), rear_(-1), sz(0), cap(k) {}
    bool enQueue(int value) { if(sz==cap)return false; rear_=(rear_+1)%cap; data[rear_]=value; sz++; return true; }
    bool deQueue() { if(sz==0)return false; front_=(front_+1)%cap; sz--; return true; }
    int Front() { return sz==0?-1:data[front_]; }
    int Rear() { return sz==0?-1:data[rear_]; }
    bool isEmpty() { return sz==0; }
    bool isFull() { return sz==cap; }
};

// ============================================================
// Solution 2: Fixed array + front/rear pointers — clean O(1) ops
// ============================================================
class Solution2 {
    int *arr, front_, rear_, cap;
public:
    Solution2(int k) : arr(new int[k]), front_(-1), rear_(-1), cap(k) {}
    bool enQueue(int val) {
        if(isFull())return false;
        if(isEmpty())front_=0;
        rear_=(rear_+1)%cap; arr[rear_]=val; return true;
    }
    bool deQueue() {
        if(isEmpty())return false;
        if(front_==rear_){front_=rear_=-1;}else{front_=(front_+1)%cap;} return true;
    }
    int Front() { return isEmpty()?-1:arr[front_]; }
    int Rear() { return isEmpty()?-1:arr[rear_]; }
    bool isEmpty() { return front_==-1; }
    bool isFull() { return (rear_+1)%cap==front_; }
};
