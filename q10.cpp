#include <iostream>
#include <string>

bool checkOnlyAlphabeticCharacter(const std::string &str) {
    for(char c: str) {
        if(c < 65 || c > 122) {
            return false;
        } else if(c > 90 && c < 97) {
            return false;
        }
    }
    return true;
}





int main() {
    std::string str;
    std::cin >> str;
    str = str.substr(0, str.size() - 1);
    
    std::cout << "String: " << str << "\n";
    std::cout << (checkOnlyAlphabeticCharacter(str) ? "true" : "false");
}