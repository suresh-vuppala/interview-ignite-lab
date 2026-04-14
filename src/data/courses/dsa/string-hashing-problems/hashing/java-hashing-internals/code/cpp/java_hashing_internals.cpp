// Java Hashing Internals — C++ Equivalent Reference
// This lesson focuses on Java HashMap/HashSet internals.
// C++ equivalent: std::unordered_map / std::unordered_set
#include <unordered_map>
#include <unordered_set>
#include <iostream>
using namespace std;

int main() {
    // C++ unordered_map is the equivalent of Java HashMap
    unordered_map<string, int> map;
    map["key"] = 42;
    cout << map["key"] << endl; // 42

    // Key differences from Java:
    // 1. C++ uses std::hash + operator== (not hashCode/equals)
    // 2. C++ uses chaining (linked list buckets, no treeification)
    // 3. Default load factor: 1.0 (vs 0.75 in Java)
    // 4. C++ allows custom hash: unordered_map<K,V,MyHash>
    // 5. C++ does NOT maintain insertion order
    return 0;
}
