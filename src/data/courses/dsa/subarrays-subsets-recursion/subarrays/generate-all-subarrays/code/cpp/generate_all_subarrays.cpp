#include <vector>
using namespace std;

vector<vector<int>> generateSubarrays(vector<int>& arr) {
    vector<vector<int>> result;
    for (int i = 0; i < arr.size(); i++) {
        for (int j = i; j < arr.size(); j++) {
            vector<int> sub;
            for (int k = i; k <= j; k++)
                sub.push_back(arr[k]);
            result.push_back(sub);
        }
    }
    return result;
}