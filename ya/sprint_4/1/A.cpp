#include <iostream>
#include <vector>
#include <string>
#include <unordered_set>

void add(std::string& str, std::unordered_set <std::string>& s, std::vector <std::string>& v) {
    if(s.find(str) == s.end()) {
        s.insert(str);
        v.push_back(str);
    }
}

int main() {
    int n = 0;
    std::cin >> n;
    std::cin.ignore();
    std::vector <std::string> uniq;
    std::unordered_set <std::string> uniq2;
    for(int i = 0; i < n; ++i) {
        std::string str;
        std::getline(std::cin, str);
        add(str, uniq2, uniq);
    }

    for(auto str : uniq) {
        std::cout << str << '\n';
    }
} 