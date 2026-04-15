// ===========================================================================
// DESIGN: Unix 'find' Command — Low Level Design
// ===========================================================================
// Fully functional single-file Java implementation
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
// abstract class FileSystemEntry {
//   - name : String
//   - path : String
//   - size : long
//   + getName() : String
//   + getPath() : String
//   + {abstract} getSize() : long
//   + isDirectory() : boolean
//   + {abstract} display(indent) : void
// }
// class File { - extension : String \n + getExtension() }
// class Directory { - children : List<FileSystemEntry> \n + add() \n + getChildren() }
// interface Filter { + matches(entry) : boolean \n + describe() : String }
// class NameFilter { - pattern }
// class ExtensionFilter { - ext }
// class SizeFilter { - threshold \n - op }
// class TypeFilter { - dirOnly }
// class ANDFilter { - filters : List<Filter> }
// class ORFilter  { - filters : List<Filter> }
// class Finder { + search(root, filter) : List }
// FileSystemEntry <|-- File
// FileSystemEntry <|-- Directory
// Directory *-- "0..*" FileSystemEntry
// Filter <|.. NameFilter
// Filter <|.. ExtensionFilter
// Filter <|.. SizeFilter
// Filter <|.. TypeFilter
// Filter <|.. ANDFilter
// Filter <|.. ORFilter
// ANDFilter *-- "1..*" Filter
// ORFilter  *-- "1..*" Filter
// Finder ..> Filter
// Finder ..> Directory
// @enduml

import java.util.*;

// ===========================================================================
// ENUMERATIONS
// ===========================================================================

// Size comparison operators for SizeFilter
enum SizeOp {
    GT,  // Greater than
    LT,  // Less than
    EQ   // Equal to
}

// ===========================================================================
// CLASS: FileSystemEntry [Abstract — Composite Pattern: Component]
// Responsibility: Base class for all file system nodes
// ===========================================================================
abstract class FileSystemEntry {
    protected String name;   // Entry name (e.g., "Main.java")
    protected String path;   // Full path (e.g., "/root/src/Main.java")
    protected long size;     // Size in bytes

    public FileSystemEntry(String name, String path, long size) {
        this.name = name;
        this.path = path;
        this.size = size;
    }

    // Encapsulated getters
    public String getName() { return name; }
    public String getPath() { return path; }
    public long getSize() { return size; }

    // Overridden by Directory to return true
    public boolean isDirectory() { return false; }

    // Abstract display for tree visualization
    public abstract void display(String indent);
}

// ===========================================================================
// CLASS: File [Composite Pattern: Leaf]
// Responsibility: Represents a file with name, path, size, extension
// Relationship: File IS-A FileSystemEntry (Inheritance)
// ===========================================================================
class File extends FileSystemEntry {
    private String extension;  // Extracted from filename

    public File(String name, String path, long size) {
        super(name, path, size);
        // Extract extension from filename
        int dot = name.lastIndexOf('.');
        this.extension = (dot >= 0) ? name.substring(dot + 1) : "";
    }

    public String getExtension() { return extension; }

    @Override
    public void display(String indent) {
        System.out.println(indent + "[FILE] " + name + " (." + extension + ", " + size + "B)");
    }
}

// ===========================================================================
// CLASS: Directory [Composite Pattern: Composite]
// Responsibility: Contains files and sub-directories (tree node)
// Relationship: Composition — Directory OWNS its children
// ===========================================================================
class Directory extends FileSystemEntry {
    // Composition: directory owns its children
    private List<FileSystemEntry> children = new ArrayList<>();

    public Directory(String name, String path) {
        super(name, path, 0);
    }

    @Override
    public boolean isDirectory() { return true; }

    // Add child (file or subdirectory)
    public void add(FileSystemEntry entry) {
        children.add(entry);
    }

    public List<FileSystemEntry> getChildren() {
        return Collections.unmodifiableList(children);
    }

    // Recursive size calculation
    @Override
    public long getSize() {
        long total = 0;
        for (FileSystemEntry child : children) {
            total += child.getSize();
        }
        return total;
    }

    @Override
    public void display(String indent) {
        System.out.println(indent + "[DIR] " + name + "/");
        for (FileSystemEntry child : children) {
            child.display(indent + "  ");
        }
    }
}

// ===========================================================================
// INTERFACE: Filter [Strategy Pattern: Strategy]
// Responsibility: Contract for search filter strategies
// SOLID: OCP — add new filters without modifying existing code
// ===========================================================================
interface Filter {
    boolean matches(FileSystemEntry entry);
    String describe();
}

// ===========================================================================
// CLASS: NameFilter [Strategy: Concrete — wildcard name matching]
// ===========================================================================
class NameFilter implements Filter {
    private String pattern;

    public NameFilter(String pattern) {
        this.pattern = pattern;
    }

    @Override
    public boolean matches(FileSystemEntry entry) {
        return wildcardMatch(entry.getName(), pattern);
    }

    @Override
    public String describe() { return "NameFilter('" + pattern + "')"; }

    // Wildcard matching: * = any chars, ? = single char
    private boolean wildcardMatch(String text, String pat) {
        int t = 0, p = 0;
        int starIdx = -1, matchIdx = 0;
        while (t < text.length()) {
            if (p < pat.length() && (pat.charAt(p) == text.charAt(t) || pat.charAt(p) == '?')) {
                t++; p++;
            } else if (p < pat.length() && pat.charAt(p) == '*') {
                starIdx = p; matchIdx = t; p++;
            } else if (starIdx != -1) {
                p = starIdx + 1; matchIdx++; t = matchIdx;
            } else {
                return false;
            }
        }
        while (p < pat.length() && pat.charAt(p) == '*') p++;
        return p == pat.length();
    }
}

// ===========================================================================
// CLASS: ExtensionFilter [Strategy: Concrete — extension matching]
// ===========================================================================
class ExtensionFilter implements Filter {
    private String ext;

    public ExtensionFilter(String ext) { this.ext = ext; }

    @Override
    public boolean matches(FileSystemEntry entry) {
        // Only File objects have extensions
        if (!(entry instanceof File)) return false;
        return ((File) entry).getExtension().equals(ext);
    }

    @Override
    public String describe() { return "ExtensionFilter('" + ext + "')"; }
}

// ===========================================================================
// CLASS: SizeFilter [Strategy: Concrete — size comparison]
// ===========================================================================
class SizeFilter implements Filter {
    private long threshold;
    private SizeOp op;

    public SizeFilter(long threshold, SizeOp op) {
        this.threshold = threshold;
        this.op = op;
    }

    @Override
    public boolean matches(FileSystemEntry entry) {
        long s = entry.getSize();
        switch (op) {
            case GT: return s > threshold;
            case LT: return s < threshold;
            case EQ: return s == threshold;
            default: return false;
        }
    }

    @Override
    public String describe() {
        String o = (op == SizeOp.GT) ? ">" : (op == SizeOp.LT) ? "<" : "==";
        return "SizeFilter(size " + o + " " + threshold + ")";
    }
}

// ===========================================================================
// CLASS: TypeFilter [Strategy: Concrete — file vs directory]
// ===========================================================================
class TypeFilter implements Filter {
    private boolean dirOnly;

    public TypeFilter(boolean dirOnly) { this.dirOnly = dirOnly; }

    @Override
    public boolean matches(FileSystemEntry entry) {
        return entry.isDirectory() == dirOnly;
    }

    @Override
    public String describe() { return dirOnly ? "TypeFilter(DIR)" : "TypeFilter(FILE)"; }
}

// ===========================================================================
// CLASS: ANDFilter [Composite Filter — all must match]
// Pattern: Composite applied to filters + Strategy
// ===========================================================================
class ANDFilter implements Filter {
    private List<Filter> filters = new ArrayList<>();

    public void addFilter(Filter f) { filters.add(f); }

    @Override
    public boolean matches(FileSystemEntry entry) {
        for (Filter f : filters) {
            if (!f.matches(entry)) return false;  // Short-circuit
        }
        return true;
    }

    @Override
    public String describe() {
        StringBuilder sb = new StringBuilder("AND(");
        for (int i = 0; i < filters.size(); i++) {
            if (i > 0) sb.append(" && ");
            sb.append(filters.get(i).describe());
        }
        return sb.append(")").toString();
    }
}

// ===========================================================================
// CLASS: ORFilter [Composite Filter — any must match]
// ===========================================================================
class ORFilter implements Filter {
    private List<Filter> filters = new ArrayList<>();

    public void addFilter(Filter f) { filters.add(f); }

    @Override
    public boolean matches(FileSystemEntry entry) {
        for (Filter f : filters) {
            if (f.matches(entry)) return true;  // Short-circuit
        }
        return false;
    }

    @Override
    public String describe() {
        StringBuilder sb = new StringBuilder("OR(");
        for (int i = 0; i < filters.size(); i++) {
            if (i > 0) sb.append(" || ");
            sb.append(filters.get(i).describe());
        }
        return sb.append(")").toString();
    }
}

// ===========================================================================
// CLASS: Finder [Search Orchestrator]
// Responsibility: Recursive DFS search using Filter abstraction
// SOLID: DIP — depends on Filter interface, not concrete filters
// ===========================================================================
class Finder {

    // Public API: search from root with given filter
    public List<FileSystemEntry> search(Directory root, Filter filter) {
        List<FileSystemEntry> results = new ArrayList<>();
        searchRecursive(root, filter, results);
        return results;
    }

    // DFS traversal of file system tree
    private void searchRecursive(Directory dir, Filter filter,
                                  List<FileSystemEntry> results) {
        for (FileSystemEntry entry : dir.getChildren()) {
            // Check if current entry matches filter
            if (filter.matches(entry)) {
                results.add(entry);
            }
            // Recurse into subdirectories
            if (entry.isDirectory()) {
                searchRecursive((Directory) entry, filter, results);
            }
        }
    }
}

// ===========================================================================
// MAIN CLASS — Full demonstration
// ===========================================================================
public class UnixFindSystem {
    public static void main(String[] args) {
        System.out.println("============================================");
        System.out.println("  Unix 'find' Command — LLD Demo (Java)");
        System.out.println("============================================");

        // --- Build file system ---
        Directory root = new Directory("root", "/root");

        Directory src = new Directory("src", "/root/src");
        src.add(new File("Main.java", "/root/src/Main.java", 2048));
        src.add(new File("App.java", "/root/src/App.java", 4096));
        src.add(new File("Utils.cpp", "/root/src/Utils.cpp", 1024));
        src.add(new File("config.xml", "/root/src/config.xml", 512));

        Directory test = new Directory("test", "/root/src/test");
        test.add(new File("TestMain.java", "/root/src/test/TestMain.java", 3072));
        test.add(new File("TestApp.java", "/root/src/test/TestApp.java", 1536));
        src.add(test);

        Directory docs = new Directory("docs", "/root/docs");
        docs.add(new File("README.md", "/root/docs/README.md", 256));
        docs.add(new File("design.txt", "/root/docs/design.txt", 8192));

        Directory build = new Directory("build", "/root/build");
        build.add(new File("output.jar", "/root/build/output.jar", 65536));
        build.add(new File("debug.log", "/root/build/debug.log", 10240));

        root.add(src);
        root.add(docs);
        root.add(build);

        System.out.println("\n--- File System Tree ---");
        root.display("");

        Finder finder = new Finder();

        // Test 1: Find all .java files
        System.out.println("\n--- Test 1: Find *.java files ---");
        List<FileSystemEntry> results = finder.search(root, new ExtensionFilter("java"));
        System.out.println("Found " + results.size() + " matches:");
        for (FileSystemEntry e : results)
            System.out.println("  " + e.getPath());

        // Test 2: Find files > 2000 bytes
        System.out.println("\n--- Test 2: Files > 2000 bytes ---");
        results = finder.search(root, new SizeFilter(2000, SizeOp.GT));
        for (FileSystemEntry e : results)
            System.out.println("  " + e.getPath() + " (" + e.getSize() + "B)");

        // Test 3: .java AND > 1000 bytes
        System.out.println("\n--- Test 3: .java AND > 1000B ---");
        ANDFilter andFilter = new ANDFilter();
        andFilter.addFilter(new ExtensionFilter("java"));
        andFilter.addFilter(new SizeFilter(1000, SizeOp.GT));
        results = finder.search(root, andFilter);
        for (FileSystemEntry e : results)
            System.out.println("  " + e.getPath() + " (" + e.getSize() + "B)");

        // Test 4: README* OR *.log
        System.out.println("\n--- Test 4: README* OR *.log ---");
        ORFilter orFilter = new ORFilter();
        orFilter.addFilter(new NameFilter("README*"));
        orFilter.addFilter(new ExtensionFilter("log"));
        results = finder.search(root, orFilter);
        for (FileSystemEntry e : results)
            System.out.println("  " + e.getPath());

        // Test 5: Directories only
        System.out.println("\n--- Test 5: Directories only ---");
        results = finder.search(root, new TypeFilter(true));
        for (FileSystemEntry e : results)
            System.out.println("  " + e.getPath() + "/");

        System.out.println("\n=== All tests passed ===");
    }
}

// ===========================================================================
// 5. SUMMARY
// ===========================================================================

// EXECUTION FLOW:
//   main() -> build Directory tree -> create Finder
//     -> finder.search(root, filter)
//       -> searchRecursive(dir, filter, results)
//         -> for each child: filter.matches(child)
//           -> [ExtensionFilter]: instanceof File -> getExtension()
//           -> [SizeFilter]: getSize() vs threshold
//           -> [ANDFilter]: iterate sub-filters, all must be true
//           -> [ORFilter]: iterate sub-filters, first true wins
//         -> if child.isDirectory(): recurse

// METHOD CALL TREE:
//   finder.search(root, filter)
//     -> searchRecursive(dir, filter, results)
//          -> dir.getChildren()
//          -> filter.matches(child)  [polymorphic dispatch]
//               -> [AND] -> sub1.matches() && sub2.matches()
//               -> [OR]  -> sub1.matches() || sub2.matches()
//          -> child.isDirectory() ? recurse : skip

// CLASS RESPONSIBILITY TABLE:
//   FileSystemEntry  | Abstract base for file system nodes
//   File             | Leaf with name, path, size, extension
//   Directory        | Composite owning children (files + dirs)
//   Filter           | Strategy interface — matches() contract
//   NameFilter       | Wildcard name matching (*, ?)
//   ExtensionFilter  | File extension matching
//   SizeFilter       | Size comparison (GT/LT/EQ)
//   TypeFilter       | File vs directory type check
//   ANDFilter        | Composite filter — all must match
//   ORFilter         | Composite filter — any must match
//   Finder           | DFS search orchestrator

// DESIGN PATTERNS:
//   1. Composite -> File/Directory tree (Component/Leaf/Composite)
//   2. Strategy  -> Filter interface with swappable implementations
//   3. Composite -> ANDFilter/ORFilter compose multiple Filters

// BEST PRACTICES:
//   1. Encapsulation         -> private fields, public getters
//   2. Polymorphism          -> matches(), isDirectory(), getSize() dispatched at runtime
//   3. Composition > Inherit -> ANDFilter CONTAINS filters, not extends them
//   4. DIP                   -> Finder depends on Filter abstraction
//   5. OCP                   -> New filter = new class, zero changes to Finder
//   6. SRP                   -> Each filter handles ONE search criterion
//   7. Immutable collections -> getChildren() returns unmodifiableList
