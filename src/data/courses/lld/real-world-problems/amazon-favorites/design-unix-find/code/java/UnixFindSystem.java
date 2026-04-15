// Design Unix Find Command
import java.util.*;
import java.time.LocalDateTime;

// ========== FILE SYSTEM ==========
abstract class FileSystemEntry {
    protected String name;
    protected String path;
    protected long size;
    protected LocalDateTime modifiedDate;
    
    public FileSystemEntry(String name, String path, long size) {
        this.name = name; this.path = path; this.size = size;
        this.modifiedDate = LocalDateTime.now();
    }
    public String getName() { return name; }
    public String getPath() { return path; }
    public long getSize() { return size; }
    public boolean isDirectory() { return false; }
}

class File extends FileSystemEntry {
    private String extension;
    public File(String name, String path, long size) {
        super(name, path, size);
        int dot = name.lastIndexOf('.');
        this.extension = dot >= 0 ? name.substring(dot + 1) : "";
    }
    public String getExtension() { return extension; }
}

class Directory extends FileSystemEntry {
    private List<FileSystemEntry> children = new ArrayList<>();
    public Directory(String name, String path) { super(name, path, 0); }
    public void add(FileSystemEntry entry) { children.add(entry); }
    public List<FileSystemEntry> getChildren() { return children; }
    @Override public boolean isDirectory() { return true; }
    @Override public long getSize() {
        return children.stream().mapToLong(FileSystemEntry::getSize).sum();
    }
}

// ========== FILTERS (Strategy Pattern) ==========
interface Filter {
    boolean matches(FileSystemEntry entry);
}

class NameFilter implements Filter {
    private String pattern;
    public NameFilter(String pattern) { this.pattern = pattern; }
    public boolean matches(FileSystemEntry entry) {
        return entry.getName().matches(pattern.replace("*", ".*"));
    }
}

class ExtensionFilter implements Filter {
    private String extension;
    public ExtensionFilter(String ext) { this.extension = ext; }
    public boolean matches(FileSystemEntry entry) {
        return entry instanceof File && ((File) entry).getExtension().equals(extension);
    }
}

enum SizeOperator { GT, LT, EQ }
class SizeFilter implements Filter {
    private long threshold;
    private SizeOperator op;
    public SizeFilter(long threshold, SizeOperator op) {
        this.threshold = threshold; this.op = op;
    }
    public boolean matches(FileSystemEntry entry) {
        return switch (op) {
            case GT -> entry.getSize() > threshold;
            case LT -> entry.getSize() < threshold;
            case EQ -> entry.getSize() == threshold;
        };
    }
}

// Composite Filters
class ANDFilter implements Filter {
    private List<Filter> filters;
    public ANDFilter(Filter... filters) { this.filters = List.of(filters); }
    public boolean matches(FileSystemEntry entry) {
        return filters.stream().allMatch(f -> f.matches(entry));
    }
}

class ORFilter implements Filter {
    private List<Filter> filters;
    public ORFilter(Filter... filters) { this.filters = List.of(filters); }
    public boolean matches(FileSystemEntry entry) {
        return filters.stream().anyMatch(f -> f.matches(entry));
    }
}

// ========== FINDER ==========
class UnixFind {
    public List<FileSystemEntry> search(Directory root, Filter filter) {
        List<FileSystemEntry> results = new ArrayList<>();
        searchRecursive(root, filter, results);
        return results;
    }
    
    private void searchRecursive(Directory dir, Filter filter, List<FileSystemEntry> results) {
        for (FileSystemEntry entry : dir.getChildren()) {
            if (filter.matches(entry)) results.add(entry);
            if (entry instanceof Directory) {
                searchRecursive((Directory) entry, filter, results);
            }
        }
    }
}

// Usage:
// Filter filter = new ANDFilter(new ExtensionFilter("java"), new SizeFilter(1024, SizeOperator.GT));
// List<FileSystemEntry> results = new UnixFind().search(rootDir, filter);
