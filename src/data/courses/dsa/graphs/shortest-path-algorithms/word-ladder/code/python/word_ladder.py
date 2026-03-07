from collections import deque, defaultdict

# ==================== SOLUTION 1: BFS WITH NEIGHBOR GENERATION ====================
# Time: O(N×L²×26) | Space: O(N×L)

def ladder_length_bfs(beginWord, endWord, wordList):
    """
    Generate all possible one-letter changes for each word.
    Try all 26 letters at each position.
    """
    word_set = set(wordList)
    if endWord not in word_set:
        return 0
    
    queue = deque([(beginWord, 1)])
    visited = {beginWord}
    
    while queue:
        word, level = queue.popleft()
        
        if word == endWord:
            return level
        
        # Generate all possible one-letter changes
        for i in range(len(word)):
            for c in 'abcdefghijklmnopqrstuvwxyz':
                next_word = word[:i] + c + word[i+1:]
                if next_word in word_set and next_word not in visited:
                    visited.add(next_word)
                    queue.append((next_word, level + 1))
    
    return 0


# ==================== SOLUTION 2: BFS WITH PATTERN MATCHING ====================
# Time: O(N×L²) | Space: O(N×L²)

def ladder_length_pattern(beginWord, endWord, wordList):
    """
    Preprocess words into patterns (e.g., "hot" -> "*ot", "h*t", "ho*").
    Words sharing a pattern are neighbors.
    Avoids trying all 26 letters.
    """
    if endWord not in wordList:
        return 0
    
    # Build pattern map: pattern -> list of words
    pattern_map = defaultdict(list)
    for word in wordList:
        for i in range(len(word)):
            pattern = word[:i] + '*' + word[i+1:]
            pattern_map[pattern].append(word)
    
    queue = deque([(beginWord, 1)])
    visited = {beginWord}
    
    while queue:
        word, level = queue.popleft()
        
        if word == endWord:
            return level
        
        # Get neighbors via patterns
        for i in range(len(word)):
            pattern = word[:i] + '*' + word[i+1:]
            for neighbor in pattern_map[pattern]:
                if neighbor not in visited:
                    visited.add(neighbor)
                    queue.append((neighbor, level + 1))
    
    return 0


# ==================== SOLUTION 3: BIDIRECTIONAL BFS ====================
# Time: O(N×L²) | Space: O(N×L)

def ladder_length_bidirectional(beginWord, endWord, wordList):
    """
    Search from both beginWord and endWord simultaneously.
    When searches meet, we found the shortest path.
    Explores exponentially fewer nodes.
    """
    word_set = set(wordList)
    if endWord not in word_set:
        return 0
    
    begin_set = {beginWord}
    end_set = {endWord}
    visited = set()
    level = 1
    
    while begin_set and end_set:
        # Always expand smaller set (optimization)
        if len(begin_set) > len(end_set):
            begin_set, end_set = end_set, begin_set
        
        next_set = set()
        for word in begin_set:
            for i in range(len(word)):
                for c in 'abcdefghijklmnopqrstuvwxyz':
                    next_word = word[:i] + c + word[i+1:]
                    
                    # Found meeting point
                    if next_word in end_set:
                        return level + 1
                    
                    if next_word in word_set and next_word not in visited:
                        visited.add(next_word)
                        next_set.add(next_word)
        
        begin_set = next_set
        level += 1
    
    return 0


# ==================== MAIN SOLUTION (RECOMMENDED) ====================

def ladderLength(beginWord, endWord, wordList):
    """
    Find shortest transformation sequence length.
    
    Time: O(N×L²) - bidirectional BFS
    Space: O(N×L) - sets and visited
    
    Example:
        >>> ladderLength("hit", "cog", ["hot","dot","dog","lot","log","cog"])
        5
    """
    return ladder_length_bidirectional(beginWord, endWord, wordList)
