#include <string>
using namespace std;

int strStr(string text, string pattern) {
    int n = text.size(), m = pattern.size();
    for (int i = 0; i <= n-m; i++) {
        int j = 0;
        while (j < m && text[i+j] == pattern[j])
            j++;
        if (j == m) return i;
    }
    return -1;
}