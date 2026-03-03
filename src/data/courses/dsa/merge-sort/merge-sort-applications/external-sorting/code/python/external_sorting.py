import heapq

def external_sort(input_file, output_file, chunk_size):
    temp_files = sort_chunks(input_file, chunk_size)
    merge_chunks(temp_files, output_file)

def sort_chunks(file, size):
    temps = []
    # Read chunks, sort in memory, write to temp files
    return temps

def merge_chunks(files, output):
    heap = []
    # k-way merge using min-heap
    # heapq.heappush(heap, (value, file_index))
    pass