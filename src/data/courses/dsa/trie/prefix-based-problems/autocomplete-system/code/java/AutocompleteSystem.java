import java.util.*;

class AutocompleteSystem {
    class TrieNode {
        Map<Character, TrieNode> children = new HashMap<>();
        Map<String, Integer> sentences = new HashMap<>(); // sentence -> frequency
    }
    
    private TrieNode root = new TrieNode();
    private TrieNode current = root;
    private StringBuilder prefix = new StringBuilder();
    
    public AutocompleteSystem(String[] sentences, int[] times) {
        // Insert all sentences with frequencies
        for (int i = 0; i < sentences.length; i++) {
            insert(sentences[i], times[i]);
        }
    }
    
    public List<String> input(char c) {
        if (c == '#') {
            // Save current sentence
            insert(prefix.toString(), 1);
            prefix = new StringBuilder();
            current = root;
            return new ArrayList<>();
        }
        
        prefix.append(c);
        if (!current.children.containsKey(c)) {
            current.children.put(c, new TrieNode());
        }
        current = current.children.get(c);
        
        // Get top 3 sentences
        return getTop3(current.sentences);
    }
    
    private void insert(String sentence, int freq) {
        TrieNode node = root;
        for (char c : sentence.toCharArray()) {
            if (!node.children.containsKey(c)) {
                node.children.put(c, new TrieNode());
            }
            node = node.children.get(c);
            node.sentences.put(sentence, node.sentences.getOrDefault(sentence, 0) + freq);
        }
    }
    
    private List<String> getTop3(Map<String, Integer> sentences) {
        List<String> result = new ArrayList<>(sentences.keySet());
        // Sort by frequency (desc), then lexicographically (asc)
        Collections.sort(result, (a, b) -> {
            int freqA = sentences.get(a);
            int freqB = sentences.get(b);
            return freqA == freqB ? a.compareTo(b) : freqB - freqA;
        });
        return result.subList(0, Math.min(3, result.size()));
    }
}
