#include <iostream>
#include <vector>
#include <limits.h>
#include <algorithm>

std::string insertInString(std::vector<std::pair<std::string, int>>& strings, std::string& s) {
    std::string str = "";
    int m = s.size();
    int n = strings.size();

    int left = 0;
    int right = 0;

    std::sort(strings.begin(), strings.end(), [] (auto& a, auto&b) { return a.second < b.second;});

    while(left < m || right < n) {

        if(right < n && left == strings[right].second) {
            str += strings[right].first;
            ++right;    
        }

        if(left < m) {
            str += s[left];
            ++left;
        }
    }

    return str;
}

int main() {
    std::string s;

    std::getline(std::cin, s);
    
    int n = 0;

    std::cin >> n;

    std::vector<std::pair<std::string, int>> strings(n);

    for(int i = 0; i < n; ++i) {
        std::cin >> strings[i].first >> strings[i].second;
    }

    std::cout << insertInString(strings, s);
}

