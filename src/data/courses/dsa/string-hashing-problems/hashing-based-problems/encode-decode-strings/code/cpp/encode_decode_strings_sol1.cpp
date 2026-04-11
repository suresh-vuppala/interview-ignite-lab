class Codec {
public:
    // Encode: "length#string" format — handles any character
    string encode(vector<string>& strs) {
        string result;
        for (const string& s : strs)
            result += to_string(s.size()) + "#" + s;
        return result;
    }
    string decode(string s) {
        // Note: returns single string for simplicity; actual returns vector
    }
    vector<string> decodeToList(string s) {
        vector<string> result;
        int i = 0;
        while (i < s.size()) {
            int j = s.find('#', i);
            int len = stoi(s.substr(i, j - i));
            result.push_back(s.substr(j + 1, len));
            i = j + 1 + len;
        }
        return result;
    }
};