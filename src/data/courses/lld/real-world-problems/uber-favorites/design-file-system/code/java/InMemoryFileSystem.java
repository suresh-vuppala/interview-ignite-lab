// In-Memory File System
import java.util.*;
import java.util.stream.*;

abstract class FileSystemNode {
    protected String name;
    protected Directory parent;
    public FileSystemNode(String name) { this.name = name; }
    public String getName() { return name; }
    public boolean isDirectory() { return false; }
    public Directory getParent() { return parent; }
    public void setParent(Directory p) { this.parent = p; }
}

class File extends FileSystemNode {
    private String content = "";
    public File(String name) { super(name); }
    public String getContent() { return content; }
    public void setContent(String c) { this.content = c; }
    public int getSize() { return content.length(); }
}

class Directory extends FileSystemNode {
    private Map<String, FileSystemNode> children = new LinkedHashMap<>();
    public Directory(String name) { super(name); }
    @Override public boolean isDirectory() { return true; }
    
    public void addChild(FileSystemNode node) { children.put(node.getName(), node); node.setParent(this); }
    public void removeChild(String name) { children.remove(name); }
    public FileSystemNode getChild(String name) { return children.get(name); }
    public Collection<FileSystemNode> listChildren() { return children.values(); }
    
    public List<FileSystemNode> listMatching(String pattern) {
        String regex = pattern.replace(".", "\.").replace("*", ".*");
        return children.values().stream()
            .filter(n -> n.getName().matches(regex))
            .collect(Collectors.toList());
    }
}

class FileSystem {
    private Directory root;
    private Directory currentDir;
    
    public FileSystem() {
        root = new Directory("/");
        currentDir = root;
    }
    
    public void mkdir(String path) {
        String[] parts = path.split("/");
        Directory dir = path.startsWith("/") ? root : currentDir;
        for (String part : parts) {
            if (part.isEmpty()) continue;
            FileSystemNode child = dir.getChild(part);
            if (child == null) {
                Directory newDir = new Directory(part);
                dir.addChild(newDir);
                dir = newDir;
            } else if (child.isDirectory()) {
                dir = (Directory) child;
            } else throw new IllegalStateException(part + " is a file, not directory");
        }
    }
    
    public void touch(String name) {
        if (currentDir.getChild(name) == null) currentDir.addChild(new File(name));
    }
    
    public void cd(String path) {
        if ("/".equals(path)) { currentDir = root; return; }
        if ("..".equals(path)) {
            if (currentDir.getParent() != null) currentDir = currentDir.getParent();
            return;
        }
        FileSystemNode node = currentDir.getChild(path);
        if (node != null && node.isDirectory()) currentDir = (Directory) node;
        else throw new IllegalArgumentException("Directory not found: " + path);
    }
    
    public String pwd() {
        Deque<String> stack = new ArrayDeque<>();
        Directory d = currentDir;
        while (d != null && d != root) { stack.push(d.getName()); d = d.getParent(); }
        return "/" + String.join("/", stack);
    }
    
    public List<String> ls(String pattern) {
        Collection<FileSystemNode> items = pattern != null && pattern.contains("*")
            ? currentDir.listMatching(pattern)
            : currentDir.listChildren();
        return items.stream().map(n -> n.getName() + (n.isDirectory() ? "/" : "")).toList();
    }
}
