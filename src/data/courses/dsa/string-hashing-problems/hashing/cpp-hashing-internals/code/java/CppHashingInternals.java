// C++ Hashing Internals — Java Equivalent Reference
// This lesson focuses on C++ std::unordered_map/unordered_set internals.
// Java equivalent: java.util.HashMap / java.util.HashSet

import java.util.*;

class CppHashingInternals {
    public static void main(String[] args) {
        // Java HashMap is the equivalent of C++ unordered_map
        HashMap<String, Integer> map = new HashMap<>();
        map.put("key", 42);
        System.out.println(map.get("key")); // 42

        // Key differences from C++:
        // 1. Java uses hashCode() + equals() (not operator== and std::hash)
        // 2. Java auto-treeifies buckets at size 8 (red-black tree)
        // 3. Default load factor: 0.75 (vs 1.0 in C++)
        // 4. Java doesn't allow custom hash in constructor (override hashCode)
    }
}
