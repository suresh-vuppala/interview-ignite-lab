// ISP Example — Document Management System
interface Readable { String read(); }
interface Writable { void write(String content); }
interface Deletable { void delete(); }
interface Versionable { List<String> getVersionHistory(); void rollback(int version); }

// Simple text file — read + write only
class TextFile implements Readable, Writable {
    private String content = "";
    public String read() { return content; }
    public void write(String content) { this.content = content; }
}

// Cloud document — full featured
class CloudDocument implements Readable, Writable, Deletable, Versionable {
    private List<String> versions = new ArrayList<>();
    private String content = "";
    
    public String read() { return content; }
    public void write(String content) { versions.add(this.content); this.content = content; }
    public void delete() { content = null; versions.clear(); }
    public List<String> getVersionHistory() { return Collections.unmodifiableList(versions); }
    public void rollback(int version) { content = versions.get(version); }
}

// Read-only config — only Readable
class ConfigFile implements Readable {
    private final String content;
    public ConfigFile(String content) { this.content = content; }
    public String read() { return content; }
    // No write, delete, or version — not forced to implement them!
}
