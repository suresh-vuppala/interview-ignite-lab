// ============================================================
// Sort Stack Using One Auxiliary Stack
// ============================================================

#include <stack>
using namespace std;

class Solution {
public:
    void sortStack(stack<int>& input) {
        stack<int> aux;

        while (!input.empty()) {
            int temp = input.top();
            input.pop();

            // Move elements back from aux while they're greater
            while (!aux.empty() && aux.top() > temp) {
                input.push(aux.top());
                aux.pop();
            }

            // Insert temp at correct position in aux
            aux.push(temp);
        }

        // Move sorted elements back to input
        while (!aux.empty()) {
            input.push(aux.top());
            aux.pop();
        }
    }
};
