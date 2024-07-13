#include <iostream>
#include <string>
#include <vector>

int GetLengthOfLongestSubString(const std::string &str) {
    int n = str.size();
    int res = 0;

    std::vector<int> lastIndex(256, -1);
    int i = 0;

    for (int j = 0; j < n; j++) {
        i = std::max(i, lastIndex[str[j]] + 1);
        res = std::max(res, j - i + 1);
        lastIndex[str[j]] = j;
    }
    return res;
}





int main() {
    std::string str = "abrshasasfdaf";
    std::cout << "String: " << str << "\n";
    int len = GetLengthOfLongestSubString(str);
    std::cout << "Length of the longest non-repeating character substring: " << len;
    return 0;
}
