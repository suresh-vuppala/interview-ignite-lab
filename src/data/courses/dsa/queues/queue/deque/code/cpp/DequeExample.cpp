#include <iostream>
#include <deque>
using namespace std;

int main() {
    deque<int> dq;
    
    dq.push_back(5);     // [5]
    dq.push_front(3);    // [3, 5]
    dq.push_back(7);     // [3, 5, 7]
    
    cout << "Front: " << dq.front() << endl; // 3
    dq.pop_front();
    cout << "Rear: " << dq.back() << endl;   // 7
    dq.pop_back();
    cout << "Remaining: " << dq.front() << endl; // 5
    
    return 0;
}
