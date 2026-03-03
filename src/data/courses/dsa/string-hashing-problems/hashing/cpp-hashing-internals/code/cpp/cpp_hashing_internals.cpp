#include <unordered_map>
#include <string>
using namespace std;

struct CustomHash {
    size_t operator()(const pair<int,int>& p) const {
        return hash<int>()(p.first) ^ hash<int>()(p.second);
    }
};

int main() {
    unordered_map<pair<int,int>, int, CustomHash> map;
    map[{1,2}] = 5;
    return 0;
}