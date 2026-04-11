// ============================================================
// Encode and Decode Strings
// ============================================================

import java.util.*;

// ============================================================
// Solution: Length-Prefix Encoding (Optimal)
// Time: O(N) | Space: O(1) extra
// ============================================================
public class Codec {

    // Encode: "length#string" for each string
    public String encode(List<String> strs) {
        StringBuilder sb = new StringBuilder();
        for (String s : strs) {
            sb.append(s.length()).append('#').append(s);
        }
        return sb.toString();
    }

    // Decode: read length, skip #, extract characters
    public List<String> decode(String s) {
        List<String> result = new ArrayList<>();
        int i = 0;

        while (i < s.length()) {
            int j = s.indexOf('#', i);           // Find separator
            int length = Integer.parseInt(s.substring(i, j)); // Parse length
            result.add(s.substring(j + 1, j + 1 + length));  // Extract string
            i = j + 1 + length;                  // Advance past this string
        }

        return result;
    }
}
