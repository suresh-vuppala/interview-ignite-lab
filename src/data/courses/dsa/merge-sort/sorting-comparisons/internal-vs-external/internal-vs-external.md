# Internal vs External Sorting

## Internal Sorting
Data fits entirely in main memory (RAM).

**Examples**: Quick Sort, Merge Sort, Heap Sort  
**Characteristics**: Fast, random access

## External Sorting
Data too large for memory, stored on disk.

**Examples**: External Merge Sort, Polyphase Merge  
**Characteristics**: Sequential access, I/O optimization

## Key Differences
- **Internal**: All data in RAM
- **External**: Data on disk, chunks in RAM
- **Performance**: Internal faster, External handles large data

## Code
```code```