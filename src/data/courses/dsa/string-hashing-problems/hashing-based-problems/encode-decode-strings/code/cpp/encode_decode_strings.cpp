class Codec {
public:
    // Encode: prefix each string with its length followed by '#'
    // e.g. ["hello","world"] -> "5#hello5#world"
    string encode(vector<string>& strs) {
        string encoded = "";
        for (const string& s : strs) {
            encoded += to_string(s.size()) + "#" + s;
        }
        return encoded;
    }

    // Decode: read length, skip '#', extract substring
    vector<string> decode(string s) {
        vector<string> result;
        int i = 0;
        while (i < s.size()) {
            int j = s.find('#', i);           // Find the '#' delimiter
            int len = stoi(s.substr(i, j - i)); // Parse the length
            result.push_back(s.substr(j + 1, len)); // Extract the string
            i = j + 1 + len;                  // Move past the string
        }
        return result;
    }
};