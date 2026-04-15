# Decorator Pattern

> **Intent:** Attach additional responsibilities to an object dynamically. Decorators provide a flexible alternative to subclassing for extending functionality.

<br>

---

## When to Use

- **Add behavior without modifying** existing classes
- **Combine behaviors dynamically** at runtime
- **Avoid subclass explosion** (Encrypted + Compressed + Logged = too many subclasses)

<br>

---

## The Subclass Explosion Problem

```
DataSource
├── FileDataSource
├── EncryptedFileDataSource
├── CompressedFileDataSource
├── EncryptedCompressedFileDataSource     // Every combination!
├── LoggedFileDataSource
├── LoggedEncryptedFileDataSource
├── LoggedCompressedFileDataSource
└── LoggedEncryptedCompressedFileDataSource  // 2^N combinations!
```

<br>

---

## Solution: Decorator

```java
interface DataSource {
    String read();
    void write(String data);
}

class FileDataSource implements DataSource {
    private String filename;
    public FileDataSource(String f) { this.filename = f; }
    public String read() { return "raw file data"; }
    public void write(String data) { System.out.println("Writing to " + filename); }
}

// Base decorator — wraps a DataSource
abstract class DataSourceDecorator implements DataSource {
    protected DataSource wrapped;
    public DataSourceDecorator(DataSource source) { this.wrapped = source; }
}

class EncryptionDecorator extends DataSourceDecorator {
    public EncryptionDecorator(DataSource s) { super(s); }
    public String read() { return decrypt(wrapped.read()); }
    public void write(String data) { wrapped.write(encrypt(data)); }
    private String encrypt(String d) { return "ENC(" + d + ")"; }
    private String decrypt(String d) { return d.replace("ENC(","").replace(")",""); }
}

class CompressionDecorator extends DataSourceDecorator {
    public CompressionDecorator(DataSource s) { super(s); }
    public String read() { return decompress(wrapped.read()); }
    public void write(String data) { wrapped.write(compress(data)); }
    private String compress(String d) { return "ZIP(" + d + ")"; }
    private String decompress(String d) { return d.replace("ZIP(","").replace(")",""); }
}

// Stack decorators dynamically!
DataSource source = new FileDataSource("data.txt");
source = new EncryptionDecorator(source);   // Add encryption
source = new CompressionDecorator(source);  // Add compression
source.write("Hello");  // → compress → encrypt → write to file
```

<br>

---

## Java Standard Library Examples

- `BufferedReader(new FileReader("file.txt"))` — adds buffering
- `new BufferedInputStream(new FileInputStream("file"))` — adds buffering
- `Collections.unmodifiableList(list)` — adds immutability
- `Collections.synchronizedList(list)` — adds thread-safety

<br>

---

## Key Takeaways

1. **Wraps object to add behavior** — same interface, enhanced functionality
2. **Stackable** — combine multiple decorators
3. **Open-Closed** — add features without changing existing classes
4. **Java I/O streams** are the classic Decorator example
5. **Decorator vs Inheritance:** Decorator = runtime composition, Inheritance = compile-time
