// Time: O(N * log(sum - max))
// Space: O(1)

#include <vector>
#include <algorithm>
#include <numeric>
using namespace std;

class Solution {
public:
    int allocateBooks(vector<int>& books, int m) {
        int n = books.size();
        
        // Edge case: More students than books
        if (m > n) return -1;
        
        // Binary search range
        int low = *max_element(books.begin(), books.end());  // Minimum possible answer
        int high = accumulate(books.begin(), books.end(), 0); // Maximum possible answer
        int result = high;
        
        while (low <= high) {
            int mid = low + (high - low) / 2;
            
            // Check if we can allocate with max pages = mid
            if (canAllocate(books, n, m, mid)) {
                result = mid;      // This works, try smaller
                high = mid - 1;
            } else {
                low = mid + 1;     // Too small, need larger limit
            }
        }
        
        return result;
    }
    
private:
    bool canAllocate(vector<int>& books, int n, int m, int maxPages) {
        int studentCount = 1;      // Start with first student
        int currentPages = 0;      // Pages assigned to current student

        for (int i = 0; i < n; i++) {
            // If a single book has more pages than our limit, impossible
            if (books[i] > maxPages) return false;

            // Try to assign current book to current student
            if (currentPages + books[i] <= maxPages) {
                currentPages += books[i];  // Assign to current student
            } else {
                // Current student's limit reached, assign to next student
                studentCount++;
                currentPages = books[i];   // Start new student with current book
                
                // If we need more students than available, this limit is too small
                if (studentCount > m) return false;
            }
        }
        
        // Successfully allocated all books within the limit
        return true;
    }
};
