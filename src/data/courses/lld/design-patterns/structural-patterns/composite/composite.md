# Composite Pattern

> **Intent:** Compose objects into tree structures to represent part-whole hierarchies. Composite lets clients treat individual objects and compositions uniformly.

<br>

---

## When to Use

- **Tree/hierarchy** structures (file system, org chart, UI components, menus)
- Want to **treat leaf and container uniformly** — same interface
- **Recursive structures** — a group can contain groups

<br>

---

## Example: File System

```java
interface FileSystemItem {
    String getName();
    long getSize();
    void display(String indent);
}

// Leaf
class File implements FileSystemItem {
    private String name;
    private long size;
    
    public File(String name, long size) { this.name = name; this.size = size; }
    public String getName() { return name; }
    public long getSize() { return size; }
    public void display(String indent) { System.out.println(indent + "📄 " + name + " (" + size + "B)"); }
}

// Composite — contains other FileSystemItems (files OR folders)
class Folder implements FileSystemItem {
    private String name;
    private List<FileSystemItem> children = new ArrayList<>();
    
    public Folder(String name) { this.name = name; }
    public void add(FileSystemItem item) { children.add(item); }
    public void remove(FileSystemItem item) { children.remove(item); }
    
    public String getName() { return name; }
    public long getSize() {
        return children.stream().mapToLong(FileSystemItem::getSize).sum(); // Recursive!
    }
    public void display(String indent) {
        System.out.println(indent + "📁 " + name + " (" + getSize() + "B)");
        children.forEach(c -> c.display(indent + "  "));
    }
}

// Usage — uniform treatment
Folder root = new Folder("root");
Folder src = new Folder("src");
src.add(new File("App.java", 2048));
src.add(new File("Main.java", 1024));
root.add(src);
root.add(new File("README.md", 512));
root.display(""); // Recursively displays entire tree
```

<br>

---

## Key Takeaways

1. **Tree structures** — folders contain files or other folders
2. **Uniform interface** — treat leaf and composite the same way
3. **Recursive operations** — `getSize()` on folder sums all children
4. **Common in:** File systems, UI components, organization hierarchies, menu systems
