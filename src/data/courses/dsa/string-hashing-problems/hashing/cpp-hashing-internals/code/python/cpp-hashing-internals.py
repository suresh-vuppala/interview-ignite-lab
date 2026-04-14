# C++ Hashing Internals — Python Equivalent Reference
# This lesson focuses on C++ std::unordered_map/unordered_set internals.
# Python equivalent: dict / set

class CppHashingInternals:
    """
    Python dict is the equivalent of C++ unordered_map.
    
    Key differences from C++:
    1. Python uses __hash__() + __eq__() (not operator== and std::hash)
    2. Python dicts use open addressing (not chaining like C++)
    3. Python dicts maintain insertion order (since 3.7)
    4. Load factor ~2/3 triggers resize (vs 1.0 in C++)
    """
    def demo(self):
        d = {"key": 42}
        print(d["key"])  # 42
        
        s = {1, 2, 3}  # set = unordered_set equivalent
        print(2 in s)   # True, O(1) average
