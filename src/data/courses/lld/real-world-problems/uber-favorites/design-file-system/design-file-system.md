# Design a File System

Design an in-memory file system with directory navigation, wildcard support, and standard Unix-like operations.

<br>

---

## Requirements

### Main Requirements (Functional)

1. **mkdir** — create directory (support nested: `mkdir -p a/b/c`)
2. **touch** — create empty file
3. **ls** — list directory contents (with wildcard: `ls *.java`)
4. **cd** — change directory (support `..`, `.`, absolute and relative paths)
5. **pwd** — print current working directory
6. **cat** — read file content
7. **rm** — remove file or empty directory
8. **write** — write content to a file

### Extended Requirements (If Time Permits)

1. `mv` — move/rename files
2. `cp` — copy files/directories
3. `find` — recursive search with filters
4. File permissions (read/write/execute)
5. Symbolic links
6. File size tracking
7. `tree` — display directory tree structure

<br>

---

## Constraints

- Path separator: `/`
- Root directory: `/`
- File names: 1-255 characters, alphanumeric + `.` + `-` + `_`
- Maximum path depth: 100 levels
- Maximum file content: 1 MB
- Maximum files per directory: 10,000
- Case-sensitive file names

<br>

---

## Identify Primary Actors

1. **User** — navigates and manipulates the file system
   - Actions: create/delete files and dirs, read/write content, navigate, search

2. **File System** — manages the directory tree
   - Actions: resolve paths, maintain tree structure, enforce constraints

<br>

---

## Core Entities

### 1. FileSystemNode (Abstract)
- **Attributes**: name, parent: Directory, createdAt, modifiedAt
- **Methods**: getName(), getPath(), isDirectory()
- **Responsibilities**: Base type for all file system entries

### 2. File (extends FileSystemNode)
- **Attributes**: content: String, size: int
- **Methods**: read(), write(content), getSize()

### 3. Directory (extends FileSystemNode)
- **Attributes**: children: Map<String, FileSystemNode>
- **Methods**: addChild(), removeChild(), getChild(), listChildren(), listMatching(pattern)

### 4. FileSystem
- **Attributes**: root: Directory, currentDir: Directory
- **Methods**: mkdir(path), touch(name), ls(pattern), cd(path), pwd(), cat(name), rm(name), write(name, content)
- **Responsibilities**: Command interface, path resolution, current directory tracking

<br>

---

## Relationships (Tabular)

| Entity A | Relationship | Entity B | Type |
|----------|-------------|----------|------|
| Directory | contains | FileSystemNode[] | Composition (◆) |
| File | extends | FileSystemNode | Inheritance |
| Directory | extends | FileSystemNode | Inheritance |
| FileSystemNode | has parent | Directory | Association |
| FileSystem | has | root: Directory | Composition (◆) |
| FileSystem | tracks | currentDir: Directory | Association |

<br>

---

## Relationships Diagram (Textual UML)

```
  FileSystem
  -root: Directory ◆
  -currentDir: Directory →
  +mkdir(), +touch(), +ls()
  +cd(), +pwd(), +cat()
  +rm(), +write()
       │
       └──◆──→ <<abstract>> FileSystemNode
                -name, -parent
                +getName(), +getPath()
                +isDirectory()
                     △
                ┌────┴────┐
              File     Directory ◆──→ Map<name, FileSystemNode>
              -content    -children
              -size       +addChild(), +removeChild()
                          +getChild(), +listChildren()
                          +listMatching(wildcard)
```

<br>

---

## Design Patterns Used

### 1. **Composite Pattern**
- **Where**: File/Directory hierarchy — Directory contains FileSystemNodes (files or other directories)
- **Why**: Tree structure where operations (getSize, display) work recursively
- **Benefit**: `ls`, `rm -r`, `find` all work uniformly on files and directories

### 2. **Iterator Pattern**
- **Where**: Directory listing and recursive traversal
- **Why**: Encapsulate traversal logic (BFS for ls, DFS for find)

<br>

---

## Concurrency & Thread Safety

### Thread Safety Mechanisms
- **Directory operations**: `synchronized(directory)` per directory — fine-grained locking
- **Path resolution**: Read-lock for traversal, write-lock for modifications
- **File content**: `ReadWriteLock` per file — concurrent reads, exclusive writes

### Race Conditions Handled
- **Two users create same-named file**: First wins, second gets `FileExistsException`
- **Delete directory while someone is inside it**: Check reference count or prevent deletion of non-empty dirs
- **Read file while being written**: ReadWriteLock ensures consistent content

<br>

---

## Edge Cases & Error Handling

### Edge Cases
1. **cd `/`** — go to root directory
2. **cd `..` from root** — stay at root (no parent)
3. **mkdir existing directory** — no-op or error (configurable)
4. **rm non-empty directory** — reject (need `rm -r` for recursive)
5. **Wildcard `*` with no matches** — return empty list
6. **File name with spaces** — support with quoting
7. **Very long path** — validate depth limit
8. **Circular paths with `..`** — resolve properly (`/a/b/../c` → `/a/c`)
9. **Create file with same name as directory** — reject, name collision

### Error Handling Strategy
- **FileNotFoundException**: File or directory does not exist
- **FileExistsException**: Name already taken in directory
- **NotADirectoryException**: Trying to cd into a file
- **DirectoryNotEmptyException**: Trying to rm non-empty directory
- **PathTooDeepException**: Exceeded maximum nesting depth

<br>

---

## Implementation

```code```
