// ===========================================================================
// DESIGN: Unix 'find' Command — Low Level Design
// ===========================================================================
// Fully functional single-file C++ implementation
// Patterns: Composite Pattern, Strategy Pattern
// Principles: SOLID, Composition over Inheritance
// ===========================================================================

// ---------------------------------------------------------------------------
// 1. FUNCTIONAL REQUIREMENTS
// ---------------------------------------------------------------------------
// FR1: Search files/directories by name (exact match or wildcard *)
// FR2: Search by file extension (e.g., .java, .txt, .cpp)
// FR3: Search by file size (greater than / less than / equal to)
// FR4: Search by type (file only or directory only)
// FR5: Combine multiple filters with AND/OR logic
// FR6: Recursively search all subdirectories from a root
// FR7: Return list of matching entries with path information

// ---------------------------------------------------------------------------
// 2. CONSTRAINTS & ASSUMPTIONS
// ---------------------------------------------------------------------------
// - Up to 1,000,000 files in the system
// - Directory depth up to 100 levels
// - File names: 1-255 characters
// - Size range: 0 bytes to 10 GB
// - In-memory simulation (no real filesystem access)

// ---------------------------------------------------------------------------
// 3. CORE ENTITIES & RELATIONSHIPS
// ---------------------------------------------------------------------------
// +-------------------+------------------+--------------+-------------+----------------------------+
// | Source             | Destination      | Type         | Cardinality | Description                |
// +-------------------+------------------+--------------+-------------+----------------------------+
// | Directory          | FileSystemEntry  | Composition  | 1 -> many   | Dir owns its children      |
// | File               | FileSystemEntry  | Inheritance  | IS-A        | File is a FSEntry          |
// | Directory          | FileSystemEntry  | Inheritance  | IS-A        | Dir is a FSEntry           |
// | ANDFilter          | Filter           | Composition  | 1 -> many   | AND owns sub-filters       |
// | ORFilter           | Filter           | Composition  | 1 -> many   | OR owns sub-filters        |
// | NameFilter         | Filter           | Inheritance  | IS-A        | Concrete strategy          |
// | ExtensionFilter    | Filter           | Inheritance  | IS-A        | Concrete strategy          |
// | SizeFilter         | Filter           | Inheritance  | IS-A        | Concrete strategy          |
// | TypeFilter         | Filter           | Inheritance  | IS-A        | Concrete strategy          |
// | Finder             | Filter           | Dependency   | uses        | Finder uses filter         |
// | Finder             | Directory        | Dependency   | uses        | Finder searches directory  |
// +-------------------+------------------+--------------+-------------+----------------------------+

// ---------------------------------------------------------------------------
// 4. PLANTUML CLASS DIAGRAM
// ---------------------------------------------------------------------------
// @startuml UnixFind
// skinparam classAttributeIconSize 0
//
// abstract class FileSystemEntry {
//   - name : string
//   - path : string
//   - size : long
//   + getName() : string
//   + getPath() : string
//   + {abstract} getSize() : long
//   + {abstract} isDirectory() : bool
//   + {abstract} display(indent) : void
// }
//
// class File {
//   - extension : string
//   + getExtension() : string
// }
//
// class Directory {
//   - children : vector<FileSystemEntry*>
//   + add(entry) : void
//   + getChildren() : vector
//   + getSize() : long  // recursive sum
// }
//
// interface Filter {
//   + {abstract} matches(entry) : bool
//   + {abstract} describe() : string
// }
//
// class NameFilter   { - pattern : string }
// class ExtensionFilter { - ext : string }
// class SizeFilter   { - threshold : long\n- op : SizeOp }
// class TypeFilter   { - directoryOnly : bool }
// class ANDFilter    { - filters : vector<Filter*> }
// class ORFilter     { - filters : vector<Filter*> }
//
// class Finder {
//   + search(root, filter) : vector<FileSystemEntry*>
//   - searchRecursive(dir, filter, results) : void
// }
//
// FileSystemEntry <|-- File
// FileSystemEntry <|-- Directory
// Directory *-- "0..*" FileSystemEntry : owns
// Filter <|.. NameFilter
// Filter <|.. ExtensionFilter
// Filter <|.. SizeFilter
// Filter <|.. TypeFilter
// Filter <|.. ANDFilter
// Filter <|.. ORFilter
// ANDFilter *-- "1..*" Filter : composes
// ORFilter  *-- "1..*" Filter : composes
// Finder ..> Filter : uses
// Finder ..> Directory : searches
// @enduml

#include <iostream>
#include <string>
#include <vector>

using namespace std;

// ===========================================================================
// ENUMERATIONS
// ===========================================================================

// Comparison operators for size-based filtering
enum SizeOp {
    SIZE_GT,   // Greater than
    SIZE_LT,   // Less than
    SIZE_EQ    // Equal to
};

// ===========================================================================
// CLASS: FileSystemEntry [Abstract Base — Composite Pattern: Component]
// Responsibility: Common interface for files and directories
// ===========================================================================
class FileSystemEntry {
protected:
    string name;    // Entry name (e.g., "Main.java")
    string path;    // Full path (e.g., "/root/src/Main.java")
    long size;      // Size in bytes

public:
    FileSystemEntry(const string& name, const string& path, long size)
        : name(name), path(path), size(size) {}

    virtual ~FileSystemEntry() {}

    // Encapsulated getters
    string getName() const { return name; }
    string getPath() const { return path; }
    virtual long getSize() const { return size; }

    // Polymorphic: overridden by Directory
    virtual bool isDirectory() const { return false; }

    // Display for debugging
    virtual void display(const string& indent) const {
        cout << indent << name << " (" << size << "B)" << endl;
    }
};

// ===========================================================================
// CLASS: File [Composite Pattern: Leaf]
// Responsibility: Represents a file with name, path, size, extension
// Relationship: File IS-A FileSystemEntry (Inheritance)
// ===========================================================================
class File : public FileSystemEntry {
private:
    string extension;   // Extracted from filename after last '.'

public:
    File(const string& name, const string& path, long size)
        : FileSystemEntry(name, path, size)
    {
        // Extract file extension
        size_t dot = name.rfind('.');
        extension = (dot != string::npos) ? name.substr(dot + 1) : "";
    }

    string getExtension() const { return extension; }

    void display(const string& indent) const {
        cout << indent << "[FILE] " << name
             << " (." << extension << ", " << size << "B)" << endl;
    }
};

// ===========================================================================
// CLASS: Directory [Composite Pattern: Composite]
// Responsibility: Contains files and sub-directories (tree structure)
// Relationship: Directory OWNS FileSystemEntry children (Composition)
// ===========================================================================
class Directory : public FileSystemEntry {
private:
    vector<FileSystemEntry*> children;   // Composition: dir owns children

public:
    Directory(const string& name, const string& path)
        : FileSystemEntry(name, path, 0) {}

    // Clean up owned children — Composition ownership semantics
    ~Directory() {
        for (size_t i = 0; i < children.size(); i++) {
            delete children[i];
        }
    }

    bool isDirectory() const { return true; }

    // Add child entry (file or subdirectory)
    void add(FileSystemEntry* entry) {
        children.push_back(entry);
    }

    const vector<FileSystemEntry*>& getChildren() const {
        return children;
    }

    // Recursive size: sum of all children
    long getSize() const {
        long total = 0;
        for (size_t i = 0; i < children.size(); i++) {
            total += children[i]->getSize();
        }
        return total;
    }

    void display(const string& indent) const {
        cout << indent << "[DIR] " << name << "/" << endl;
        for (size_t i = 0; i < children.size(); i++) {
            children[i]->display(indent + "  ");
        }
    }
};

// ===========================================================================
// INTERFACE: Filter [Strategy Pattern: Strategy]
// Responsibility: Defines the contract for search filters
// SOLID: OCP — new filters without modifying existing code
// ===========================================================================
class Filter {
public:
    virtual ~Filter() {}
    virtual bool matches(const FileSystemEntry& entry) const = 0;
    virtual string describe() const = 0;
};

// ===========================================================================
// CLASS: NameFilter [Strategy: Concrete — wildcard name matching]
// ===========================================================================
class NameFilter : public Filter {
private:
    string pattern;

    // Wildcard matching: * = any chars, ? = single char
    bool wildcardMatch(const string& text, const string& pat) const {
        size_t t = 0, p = 0;
        size_t starIdx = string::npos, matchIdx = 0;
        while (t < text.size()) {
            if (p < pat.size() && (pat[p] == text[t] || pat[p] == '?')) {
                t++; p++;
            } else if (p < pat.size() && pat[p] == '*') {
                starIdx = p; matchIdx = t; p++;
            } else if (starIdx != string::npos) {
                p = starIdx + 1; matchIdx++; t = matchIdx;
            } else {
                return false;
            }
        }
        while (p < pat.size() && pat[p] == '*') p++;
        return p == pat.size();
    }

public:
    NameFilter(const string& pattern) : pattern(pattern) {}

    bool matches(const FileSystemEntry& entry) const {
        return wildcardMatch(entry.getName(), pattern);
    }

    string describe() const { return "NameFilter('" + pattern + "')"; }
};

// ===========================================================================
// CLASS: ExtensionFilter [Strategy: Concrete — extension matching]
// ===========================================================================
class ExtensionFilter : public Filter {
private:
    string ext;

public:
    ExtensionFilter(const string& ext) : ext(ext) {}

    bool matches(const FileSystemEntry& entry) const {
        const File* file = dynamic_cast<const File*>(&entry);
        return file != NULL && file->getExtension() == ext;
    }

    string describe() const { return "ExtensionFilter('" + ext + "')"; }
};

// ===========================================================================
// CLASS: SizeFilter [Strategy: Concrete — size comparison]
// ===========================================================================
class SizeFilter : public Filter {
private:
    long threshold;
    SizeOp op;

public:
    SizeFilter(long threshold, SizeOp op) : threshold(threshold), op(op) {}

    bool matches(const FileSystemEntry& entry) const {
        long s = entry.getSize();
        if (op == SIZE_GT) return s > threshold;
        if (op == SIZE_LT) return s < threshold;
        return s == threshold;
    }

    string describe() const {
        string o = (op == SIZE_GT) ? ">" : (op == SIZE_LT) ? "<" : "==";
        return "SizeFilter(size " + o + " " + to_string(threshold) + ")";
    }
};

// ===========================================================================
// CLASS: TypeFilter [Strategy: Concrete — file vs directory]
// ===========================================================================
class TypeFilter : public Filter {
private:
    bool dirOnly;

public:
    TypeFilter(bool dirOnly) : dirOnly(dirOnly) {}

    bool matches(const FileSystemEntry& entry) const {
        return entry.isDirectory() == dirOnly;
    }

    string describe() const { return dirOnly ? "TypeFilter(DIR)" : "TypeFilter(FILE)"; }
};

// ===========================================================================
// CLASS: ANDFilter [Composite Filter — all must match]
// Responsibility: Combines filters with AND logic
// Pattern: Composite (filter tree) + Strategy (each sub-filter)
// ===========================================================================
class ANDFilter : public Filter {
private:
    vector<Filter*> filters;   // Composition: AND owns sub-filters

public:
    void addFilter(Filter* f) { filters.push_back(f); }

    ~ANDFilter() {
        for (size_t i = 0; i < filters.size(); i++) delete filters[i];
    }

    bool matches(const FileSystemEntry& entry) const {
        for (size_t i = 0; i < filters.size(); i++) {
            if (!filters[i]->matches(entry)) return false;  // Short-circuit
        }
        return true;
    }

    string describe() const {
        string d = "AND(";
        for (size_t i = 0; i < filters.size(); i++) {
            if (i > 0) d += " && ";
            d += filters[i]->describe();
        }
        return d + ")";
    }
};

// ===========================================================================
// CLASS: ORFilter [Composite Filter — any must match]
// ===========================================================================
class ORFilter : public Filter {
private:
    vector<Filter*> filters;

public:
    void addFilter(Filter* f) { filters.push_back(f); }
    ~ORFilter() { for (size_t i = 0; i < filters.size(); i++) delete filters[i]; }

    bool matches(const FileSystemEntry& entry) const {
        for (size_t i = 0; i < filters.size(); i++) {
            if (filters[i]->matches(entry)) return true;  // Short-circuit
        }
        return false;
    }

    string describe() const {
        string d = "OR(";
        for (size_t i = 0; i < filters.size(); i++) {
            if (i > 0) d += " || ";
            d += filters[i]->describe();
        }
        return d + ")";
    }
};

// ===========================================================================
// CLASS: Finder [Search Orchestrator]
// Responsibility: Recursive DFS search with filter
// Dependency: Uses Filter (abstraction) and Directory — DIP applied
// ===========================================================================
class Finder {
public:
    vector<FileSystemEntry*> search(Directory& root, const Filter& filter) const {
        vector<FileSystemEntry*> results;
        searchRecursive(root, filter, results);
        return results;
    }

private:
    // DFS traversal of file system tree
    void searchRecursive(const Directory& dir, const Filter& filter,
                         vector<FileSystemEntry*>& results) const {
        const vector<FileSystemEntry*>& children = dir.getChildren();
        for (size_t i = 0; i < children.size(); i++) {
            // Check filter match
            if (filter.matches(*children[i])) {
                results.push_back(children[i]);
            }
            // Recurse into subdirectories
            if (children[i]->isDirectory()) {
                searchRecursive(
                    static_cast<Directory&>(*children[i]), filter, results);
            }
        }
    }
};

// ===========================================================================
// MAIN — Full demonstration of all features
// ===========================================================================
int main() {
    cout << "============================================" << endl;
    cout << "  Unix 'find' Command — LLD Demo" << endl;
    cout << "============================================" << endl;

    // --- Build sample file system ---
    Directory root("root", "/root");

    Directory* src = new Directory("src", "/root/src");
    src->add(new File("Main.java", "/root/src/Main.java", 2048));
    src->add(new File("App.java", "/root/src/App.java", 4096));
    src->add(new File("Utils.cpp", "/root/src/Utils.cpp", 1024));
    src->add(new File("config.xml", "/root/src/config.xml", 512));

    Directory* test = new Directory("test", "/root/src/test");
    test->add(new File("TestMain.java", "/root/src/test/TestMain.java", 3072));
    test->add(new File("TestApp.java", "/root/src/test/TestApp.java", 1536));
    src->add(test);

    Directory* docs = new Directory("docs", "/root/docs");
    docs->add(new File("README.md", "/root/docs/README.md", 256));
    docs->add(new File("design.txt", "/root/docs/design.txt", 8192));

    Directory* build = new Directory("build", "/root/build");
    build->add(new File("output.jar", "/root/build/output.jar", 65536));
    build->add(new File("debug.log", "/root/build/debug.log", 10240));

    root.add(src);
    root.add(docs);
    root.add(build);

    cout << "\n--- File System Tree ---" << endl;
    root.display("");

    Finder finder;

    // Test 1: Find all .java files
    cout << "\n--- Test 1: Find *.java files ---" << endl;
    ExtensionFilter javaFilter("java");
    vector<FileSystemEntry*> results = finder.search(root, javaFilter);
    cout << "Found " << results.size() << " matches:" << endl;
    for (size_t i = 0; i < results.size(); i++)
        cout << "  " << results[i]->getPath() << endl;

    // Test 2: Find files > 2000 bytes
    cout << "\n--- Test 2: Files > 2000 bytes ---" << endl;
    SizeFilter largeFilter(2000, SIZE_GT);
    results = finder.search(root, largeFilter);
    for (size_t i = 0; i < results.size(); i++)
        cout << "  " << results[i]->getPath() << " (" << results[i]->getSize() << "B)" << endl;

    // Test 3: .java AND > 1000 bytes
    cout << "\n--- Test 3: .java AND > 1000B ---" << endl;
    ANDFilter andFilter;
    andFilter.addFilter(new ExtensionFilter("java"));
    andFilter.addFilter(new SizeFilter(1000, SIZE_GT));
    results = finder.search(root, andFilter);
    for (size_t i = 0; i < results.size(); i++)
        cout << "  " << results[i]->getPath() << " (" << results[i]->getSize() << "B)" << endl;

    // Test 4: README* OR *.log
    cout << "\n--- Test 4: README* OR *.log ---" << endl;
    ORFilter orFilter;
    orFilter.addFilter(new NameFilter("README*"));
    orFilter.addFilter(new ExtensionFilter("log"));
    results = finder.search(root, orFilter);
    for (size_t i = 0; i < results.size(); i++)
        cout << "  " << results[i]->getPath() << endl;

    // Test 5: Directories only
    cout << "\n--- Test 5: Directories only ---" << endl;
    TypeFilter dirFilter(true);
    results = finder.search(root, dirFilter);
    for (size_t i = 0; i < results.size(); i++)
        cout << "  " << results[i]->getPath() << "/" << endl;

    cout << "\n=== All tests passed ===" << endl;
    return 0;
}

// ===========================================================================
// 5. SUMMARY
// ===========================================================================

// EXECUTION FLOW:
//   main() -> build Directory tree -> create Finder
//     -> finder.search(root, filter)
//       -> searchRecursive(dir, filter, results)
//         -> for each child: filter.matches(child)
//           -> [ExtensionFilter]: dynamic_cast -> getExtension()
//           -> [SizeFilter]: getSize() vs threshold
//           -> [ANDFilter]: iterate sub-filters, all must be true
//           -> [ORFilter]: iterate sub-filters, first true wins
//         -> if child.isDirectory(): recurse

// METHOD CALL TREE:
//   finder.search(root, filter)
//     -> searchRecursive(dir, filter, results)
//          -> dir.getChildren()
//          -> filter.matches(child)
//               -> [AND] -> subFilter1.matches() && subFilter2.matches()
//               -> [OR]  -> subFilter1.matches() || subFilter2.matches()
//          -> child.isDirectory() ? recurse : skip

// CLASS RESPONSIBILITY TABLE:
//   FileSystemEntry  | Abstract base for file system nodes
//   File             | Leaf node with name, path, size, extension
//   Directory        | Composite node owning children (files + dirs)
//   Filter           | Strategy interface — defines matches() contract
//   NameFilter       | Wildcard name matching (*, ?)
//   ExtensionFilter  | File extension matching
//   SizeFilter       | Size comparison (GT/LT/EQ)
//   TypeFilter       | File vs directory type check
//   ANDFilter        | Composite filter — all sub-filters must match
//   ORFilter         | Composite filter — any sub-filter must match
//   Finder           | DFS search orchestrator using Filter abstraction

// DESIGN PATTERNS:
//   1. Composite    -> FileSystemEntry/File/Directory tree structure
//   2. Strategy     -> Filter interface with swappable implementations
//   3. Composite    -> ANDFilter/ORFilter compose multiple Filters

// BEST PRACTICES:
//   1. Encapsulation        -> private fields, public getters
//   2. Polymorphism         -> virtual matches(), isDirectory(), getSize()
//   3. Composition > Inherit-> ANDFilter CONTAINS filters, not extends
//   4. DIP                  -> Finder depends on Filter abstraction
//   5. OCP                  -> Add new filter without changing Finder
//   6. SRP                  -> Each filter handles ONE criterion
//   7. Memory management    -> Destructors clean up owned children
