# Java Hashing Internals — Python Equivalent Reference
# This lesson focuses on Java HashMap/HashSet internals.
# Python equivalent: dict / set

class JavaHashingInternals:
    """
    Python dict is the equivalent of Java HashMap.
    
    Key differences from Java:
    1. Python uses __hash__() + __eq__() (not hashCode/equals)
    2. Python dicts use open addressing (Java uses chaining + treeification)
    3. Python dicts maintain insertion order (since 3.7)
    4. No separate TreeMap equivalent — use sorted() or SortedDict
    """
    def demo(self):
        d = {"key": 42}
        print(d["key"])  # 42
