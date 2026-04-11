// ============================================================
// Sort Stack
// ============================================================

import java.util.*;

class Solution {
    public void sortStack(Deque<Integer> input) {
        Deque<Integer> aux = new ArrayDeque<>();
        while (!input.isEmpty()) {
            int temp = input.pop();
            while (!aux.isEmpty() && aux.peek() > temp) input.push(aux.pop());
            aux.push(temp);
        }
        while (!aux.isEmpty()) input.push(aux.pop());
    }
}
