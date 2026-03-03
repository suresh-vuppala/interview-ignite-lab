#include <vector>
using namespace std;

int countSubarrays(vector<int>& arr) {
    int n = arr.size();
    return n * (n + 1) / 2;
}

int countSubsequences(vector<int>& arr) {
    return (1 << arr.size()) - 1;
}