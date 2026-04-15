# Design Unix 'find' Command

Design a file search utility similar to the Unix `find` command that can search a file system with various filters.

<br>

---

## Requirements

### Main Requirements (Functional)

1. **Search by name** — exact match or pattern (wildcard, regex)
2. **Search by extension** — find all `.java`, `.txt` files
3. **Search by size** — greater than, less than, equal to
4. **Search by type** — file only, directory only, or both
5. **Combine filters** — AND/OR logic (find `.java` files > 1MB)
6. **Recursive search** — search subdirectories
7. **Return matching results** as a list

### Extended Requirements

1. Search by modification date
2. Search by permissions
3. Limit search depth
4. Execute action on found files (delete, move, print)

<br>

---

## Core Entities

### 1. FileSystemEntry (Abstract)
- Attributes: name, path, size, createdDate, modifiedDate
- Subtypes: File, Directory

### 2. Filter (Interface — Strategy Pattern)
- `boolean matches(FileSystemEntry entry)`
- Implementations: NameFilter, ExtensionFilter, SizeFilter, TypeFilter

### 3. CompositeFilter (Composite Pattern)
- ANDFilter: all filters must match
- ORFilter: at least one filter must match

### 4. Finder
- Orchestrates search with filters on a root directory

<br>

---

## Design Patterns Used

| Pattern | Where | Why |
|---------|-------|-----|
| **Composite** | FileSystemEntry (File/Directory tree) | Recursive tree structure |
| **Strategy** | Filter interface with swappable implementations | Different filter criteria |
| **Composite** | AND/OR filter combinations | Combine filters flexibly |

<br>

---

## Class Diagram

```
<<interface>> Filter
├─ matches(FileSystemEntry): boolean
│
├── NameFilter
├── ExtensionFilter
├── SizeFilter (operator: GT/LT/EQ, threshold)
├── TypeFilter (FILE/DIRECTORY)
├── ANDFilter(List<Filter>)
└── ORFilter(List<Filter>)

<<abstract>> FileSystemEntry
├─ name, path, size
├── File (extension)
└── Directory (children: List<FileSystemEntry>)

Finder
├─ search(Directory root, Filter filter): List<FileSystemEntry>
```

<br>

---

## Key Design Decisions

1. **Filter as Strategy** — each criterion is a separate class, easy to add new ones (OCP)
2. **CompositeFilter** — AND/OR combinations without modifying existing filters
3. **FileSystemEntry hierarchy** — Composite pattern for recursive directory traversal
4. **Finder is stateless** — takes root + filter, returns results

<br>

---

## Interview Tips

- Start by asking: "What filters should be supported?"
- Mention extensibility: "New filters can be added without modifying existing code"
- Draw the Filter interface and Composite pattern clearly
- Discuss: "Should filters be composable? AND/OR?"
