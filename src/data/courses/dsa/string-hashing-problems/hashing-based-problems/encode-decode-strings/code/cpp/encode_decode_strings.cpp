// ============================================================
// Encode and Decode Strings
// ============================================================

#include <string>
#include <vector>
using namespace std;

// ============================================================
// Solution: Length-Prefix Encoding (Optimal)
// Time: O(N) | Space: O(1) extra
// ============================================================
class Codec {
public:
    // Encode: prefix each string with "length#"
    string encode(vector<string>& strs) {
        string result;
        for (const string& s : strs) {
            result += to_string(s.size()) + "#" + s;
        }
        return result;
    }

    // Decode: read length, skip #, extract that many characters
    vector<string> decode(string s) {
        vector<string> result;
        int i = 0;

        while (i < s.size()) {
            // Find the '#' separator
            int j = s.find('#', i);

            // Parse the length
            int length = stoi(s.substr(i, j - i));

            // Extract the string (exactly 'length' characters after '#')
            result.push_back(s.substr(j + 1, length));

            // Move past this string
            i = j + 1 + length;
        }

        return result;
    }
};
