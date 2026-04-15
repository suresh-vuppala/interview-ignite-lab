# Design Unix 'find' Command

Design a file search utility similar to the Unix `find` command that can search a file system with various filters.

<br>

---

## Requirements

### Main Requirements (Functional)

1. **Search by name** — exact match or wildcard pattern (`*.java`, `test*`)
2. **Search by extension** — find all `.java`, `.txt`, `.xml` files
3. **Search by size** — greater than, less than, or equal to a threshold
4. **Search by type** — file only, directory only, or both
5. **Combine filters** — AND/OR logic (e.g., `.java` files AND > 1MB)
6. **Recursive search** — search all subdirectories from a given root
7. **Return matching results** as a list of paths

### Extended Requirements (If Time Permits)

1. Search by modification date (modified after/before a date)
2. Search by permissions (readable, writable, executable)
3. Limit search depth (`-maxdepth N`)
4. Execute action on found files (delete, move, print path)
5. Exclude patterns (`--exclude "*.log"`)
6. Follow/skip symbolic links

<br>

---

## Constraints

- File system can have up to 1 million files
- Directory nesting depth up to 100 levels
- File names: 1-255 characters, alphanumeric + special chars
- Size range: 0 bytes to 10 GB
- Wildcard patterns: `*` (any chars), `?` (single char)
- Filters can be combined with AND/OR logic
- Search should not follow circular symbolic links

<br>

---

## Identify Primary Actors

1. **User** — initiates search with root directory and filters
   - Actions: specify filters, receive results, execute actions on results

2. **File System** — the underlying storage being searched
   - Provides: directory listing, file metadata (name, size, type, dates)

<br>

---

## Core Entities

### 1. FileSystemEntry (Abstract)
- **Attributes**: name, path, size, createdDate, modifiedDate, permissions
- **Responsibilities**: Base type for files and directories

### 2. File (extends FileSystemEntry)
- **Attributes**: extension, content (optional)
- **Responsibilities**: Represent a leaf node in the file system tree

### 3. Directory (extends FileSystemEntry)
- **Attributes**: children: List<FileSystemEntry>
- **Responsibilities**: Represent a composite node, contain files and subdirectories

### 4. Filter (Interface — Strategy Pattern)
- **Method**: `boolean matches(FileSystemEntry entry)`
- **Responsibilities**: Define a single search criterion

### 5. NameFilter, ExtensionFilter, SizeFilter, TypeFilter
- **Responsibilities**: Concrete filter implementations for each criterion

### 6. ANDFilter / ORFilter (Composite Filter)
- **Attributes**: filters: List<Filter>
- **Responsibilities**: Combine multiple filters with AND/OR logic

### 7. Finder
- **Method**: `search(Directory root, Filter filter): List<FileSystemEntry>`
- **Responsibilities**: Orchestrate recursive search with given filters

<br>

---

## Relationships (Tabular)

| Entity A | Relationship | Entity B | Type |
|----------|-------------|----------|------|
| Directory | contains | FileSystemEntry[] | Composition (◆) |
| File | extends | FileSystemEntry | Inheritance |
| Directory | extends | FileSystemEntry | Inheritance |
| ANDFilter | contains | Filter[] | Composition (◆) |
| ORFilter | contains | Filter[] | Composition (◆) |
| Finder | uses | Filter | Dependency |
| Finder | searches | Directory | Dependency |
| NameFilter | implements | Filter | Implementation |
| ExtensionFilter | implements | Filter | Implementation |
| SizeFilter | implements | Filter | Implementation |

<br>

---

## Relationships Diagram (Textual UML)

```
                  <<interface>>
                    Filter
                  +matches(): boolean
                     △
        ┌────────────┼────────────────────┐
        │            │                    │
   NameFilter   ExtensionFilter    SizeFilter
        │            │                    │
        └────────────┼────────────────────┘
                     │
              ┌──────┴──────┐
           ANDFilter     ORFilter
           (List<Filter>) (List<Filter>)


   <<abstract>> FileSystemEntry
   -name, -path, -size, -dates
          △
     ┌────┴────┐
   File     Directory ◆──→ FileSystemEntry[]
   -extension  -children


   Finder ──uses──→ Filter
   Finder ──searches──→ Directory
```

<br>

---

## Design Patterns Used

### 1. **Composite Pattern**
- **Where**: FileSystemEntry hierarchy (File/Directory)
- **Why**: Directory contains FileSystemEntry objects — files or other directories — forming a tree
- **Benefit**: Recursive traversal treats files and directories uniformly

### 2. **Strategy Pattern**
- **Where**: Filter interface with swappable implementations
- **Why**: Each filter criterion (name, size, extension, type) is a separate, interchangeable strategy
- **Benefit**: New filter types can be added without modifying existing code (OCP)

### 3. **Composite Pattern (again)**
- **Where**: ANDFilter / ORFilter combining multiple filters
- **Why**: Filters can be composed into complex expressions like `(Extension=java AND Size>1MB) OR Name=README`
- **Benefit**: Unlimited filter composition without combinatorial explosion of classes

<br>

---

## Concurrency & Thread Safety

### Thread Safety Mechanisms
- **File system access**: Directory listing is read-only — inherently safe for concurrent searches
- **Parallel search**: Different subtrees can be searched in parallel using `ForkJoinPool`
- **Result collection**: Use `ConcurrentLinkedQueue` or `Collections.synchronizedList` for thread-safe result accumulation

### Race Conditions Handled
- **File deleted during search**: Catch `NoSuchFileException`, skip the entry, continue
- **Directory modified during traversal**: Use snapshot of children list at traversal time
- **Symbolic link cycles**: Track visited directories using `Set<Path>` to detect cycles

<br>

---

## Edge Cases & Error Handling

### Edge Cases
1. **Empty directory** — no children, return empty results
2. **Root is a file, not directory** — return file itself if it matches filter
3. **Circular symbolic links** — detect cycles using visited set
4. **Permission denied** — skip inaccessible directories, log warning
5. **Very deep nesting (100+ levels)** — stack overflow risk → use iterative BFS or increase stack
6. **No matches found** — return empty list, not null
7. **Wildcard `*` matches everything** — filter returns all entries
8. **File name with special characters** — regex escaping for pattern matching

### Error Handling Strategy
- **FileNotFoundException**: Skip and continue search
- **PermissionDeniedException**: Log warning, skip directory
- **InvalidFilterException**: Throw immediately — fail fast on bad input
- **NullPointerException**: Validate all inputs in constructor

<br>

---

## Implementation

> See the **Java code tab** for the complete implementation including FileSystemEntry hierarchy, all Filter implementations (Name, Extension, Size, AND/OR composite), and the recursive Finder class.
