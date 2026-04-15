# Design a File System

Design an in-memory file system that supports creating files/directories, navigation (`cd`, `ls`, `pwd`), and wildcard pattern matching.

<br>

---

## Requirements

### Main Requirements
1. **mkdir** — create directory (support nested: `mkdir -p a/b/c`)
2. **touch** — create file
3. **ls** — list contents (with wildcard: `ls *.java`)
4. **cd** — change directory (support `..`, `.`, absolute paths)
5. **pwd** — print working directory
6. **cat** — read file content
7. **rm** — remove file or directory

<br>

---

## Design Patterns Used

| Pattern | Where | Why |
|---------|-------|-----|
| **Composite** | File/Directory hierarchy | Tree structure, uniform interface |
| **Iterator** | Traversal for ls, find operations | Encapsulate traversal |

<br>

---

## Core Entities

```
FileSystemNode (abstract)
├── File: name, content, size
├── Directory: name, children: Map<String, FileSystemNode>
    ├─ addChild(), removeChild(), getChild(), list()

FileSystem
├─ root: Directory
├─ currentDir: Directory
├─ mkdir(path), touch(name), ls(pattern), cd(path), pwd()
```

<br>

---

## Interview Tips

- Composite pattern is the natural fit
- Path resolution: split by `/`, traverse from root or current dir
- Wildcard matching: convert `*.java` to regex `.*\.java`
- cd `..` requires parent pointer or path stack
