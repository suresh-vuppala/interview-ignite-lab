# Internal Sorting
def internal_sort(arr):
    arr.sort()  # All data in memory

# External Sorting
def external_sort(file, chunk_size):
    # 1. Divide into chunks
    chunks = divide_into_chunks(file, chunk_size)
    # 2. Sort each chunk in memory
    for chunk in chunks:
        sort_chunk(chunk)
    # 3. Merge sorted chunks
    merge_chunks(chunks)