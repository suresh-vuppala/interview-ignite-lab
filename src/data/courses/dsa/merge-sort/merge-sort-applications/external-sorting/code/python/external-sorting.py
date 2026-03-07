# Time: O(N log N), Space: O(M) where M is chunk size

import heapq

def external_sort(data, chunk_size):
    chunks = []
    
    # Phase 1: Create sorted chunks
    for i in range(0, len(data), chunk_size):
        chunk = sorted(data[i:i + chunk_size])
        chunks.append(chunk)
    
    # Phase 2: K-way merge using min heap
    result = []
    heap = []
    
    for i, chunk in enumerate(chunks):
        if chunk:
            heapq.heappush(heap, (chunk[0], i, 0))
    
    while heap:
        val, chunk_idx, elem_idx = heapq.heappop(heap)
        result.append(val)
        
        if elem_idx + 1 < len(chunks[chunk_idx]):
            next_val = chunks[chunk_idx][elem_idx + 1]
            heapq.heappush(heap, (next_val, chunk_idx, elem_idx + 1))
    
    return result

data = [64, 34, 25, 12, 22, 11, 90, 88, 45, 50, 33, 17]
sorted_data = external_sort(data, chunk_size=3)
print(sorted_data)
