from collections import deque, defaultdict

# ==================== SOLUTION 1: BFS + DFS (TWO-PASS) ====================
# Time: O(N×L² + P×L) | Space: O(N×L + P×L)

def find_ladders_bfs_dfs(beginWord, endWord, wordList):
    """
    Phase 1: BFS to build parent relationships.
    Phase 2: DFS to backtrack and construct all paths.
    """
    word_set = set(wordList)
    if endWord not in word_set:
        return []
    
    # BFS Phase: Build parent relationships
    parents = defaultdict(list)
    level = {beginWord: 0}
    queue = deque([beginWord])
    found = False
    current_level = 0
    
    while queue and not found:
        level_size = len(queue)
        current_level += 1
        visited_this_level = set()
        
        for _ in range(level_size):
            word = queue.popleft()
            
            for i in range(len(word)):
                for c in 'abcdefghijklmnopqrstuvwxyz':
                    next_word = word[:i] + c + word[i+1:]
                    
                    if next_word in word_set:
                        if next_word not in level:
                            visited_this_level.add(next_word)
                            parents[next_word].append(word)
                            
                            if next_word == endWord:
                                found = True
                        elif level[next_word] == current_level:
                            parents[next_word].append(word)
        
        for word in visited_this_level:
            level[word] = current_level
            queue.append(word)
    
    # DFS Phase: Construct paths
    result = []
    
    def dfs(word, path):
        if word == beginWord:
            result.append(path[::-1])
            return
        for parent in parents[word]:
            dfs(parent, path + [parent])
    
    if found:
        dfs(endWord, [endWord])
    
    return result


# ==================== SOLUTION 2: BFS LEVEL-BY-LEVEL ====================
# Time: O(N×L² + P×L) | Space: O(P×L)

def find_ladders_level_by_level(beginWord, endWord, wordList):
    """
    Build paths incrementally level by level.
    More space-efficient than storing parent map.
    """
    word_set = set(wordList)
    if endWord not in word_set:
        return []
    
    current_paths = [[beginWord]]
    result = []
    
    while current_paths:
        # Remove words used in current level
        for path in current_paths:
            word_set.discard(path[-1])
        
        next_paths = []
        for path in current_paths:
            word = path[-1]
            
            if word == endWord:
                result.append(path)
                continue
            
            for i in range(len(word)):
                for c in 'abcdefghijklmnopqrstuvwxyz':
                    next_word = word[:i] + c + word[i+1:]
                    if next_word in word_set:
                        next_paths.append(path + [next_word])
        
        if result:
            return result
        
        current_paths = next_paths
    
    return []


# ==================== SOLUTION 3: BIDIRECTIONAL BFS + DFS ====================
# Time: O(N×L² + P×L) | Space: O(N×L + P×L)

def find_ladders_bidirectional(beginWord, endWord, wordList):
    """
    Bidirectional BFS to find meeting point faster.
    Then construct paths from both directions.
    """
    word_set = set(wordList)
    if endWord not in word_set:
        return []
    
    # Build graphs from both directions
    forward_parents = defaultdict(list)
    backward_parents = defaultdict(list)
    
    begin_set = {beginWord}
    end_set = {endWord}
    forward_visited = {beginWord}
    backward_visited = {endWord}
    found = False
    is_forward = True
    
    while begin_set and end_set and not found:
        if len(begin_set) > len(end_set):
            begin_set, end_set = end_set, begin_set
            forward_parents, backward_parents = backward_parents, forward_parents
            forward_visited, backward_visited = backward_visited, forward_visited
            is_forward = not is_forward
        
        next_set = set()
        for word in begin_set:
            for i in range(len(word)):
                for c in 'abcdefghijklmnopqrstuvwxyz':
                    next_word = word[:i] + c + word[i+1:]
                    
                    if next_word in backward_visited:
                        found = True
                        if is_forward:
                            forward_parents[next_word].append(word)
                        else:
                            backward_parents[word].append(next_word)
                    
                    if next_word in word_set and next_word not in forward_visited:
                        next_set.add(next_word)
                        if is_forward:
                            forward_parents[next_word].append(word)
                        else:
                            backward_parents[word].append(next_word)
        
        for word in next_set:
            forward_visited.add(word)
        begin_set = next_set
    
    # Construct paths (simplified version)
    result = []
    if found:
        # Build paths using both parent maps
        def dfs(word, path):
            if word == beginWord:
                result.append(path[::-1])
                return
            for parent in forward_parents[word]:
                dfs(parent, path + [parent])
        
        dfs(endWord, [endWord])
    
    return result


# ==================== MAIN SOLUTION (RECOMMENDED) ====================

def findLadders(beginWord, endWord, wordList):
    """
    Find all shortest transformation sequences.
    
    Time: O(N×L² + P×L) - BFS + path construction
    Space: O(N×L + P×L) - parent map + result paths
    
    Example:
        >>> findLadders("hit", "cog", ["hot","dot","dog","lot","log","cog"])
        [["hit","hot","dot","dog","cog"], ["hit","hot","lot","log","cog"]]
    """
    return find_ladders_bfs_dfs(beginWord, endWord, wordList)
