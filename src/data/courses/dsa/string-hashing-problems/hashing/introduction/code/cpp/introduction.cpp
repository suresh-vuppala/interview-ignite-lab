#include <unordered_map>
#include <iostream>
using namespace std;

int main() {
    unordered_map<string, int> map;
    map["key"] = 10;
    cout << map["key"];
    return 0;
}