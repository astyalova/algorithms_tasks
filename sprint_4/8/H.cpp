#include <string>
#include <unordered_map>
#include <iostream>

int main() {
    std::string str;

    std::getline(std::cin, str);
    std::unordered_map <char, int> res;
    int maxL = 0;
    int start = 0;

    for(int i = 0; i < str.size(); ++i) {
        char ch = str[i];

        if(res.count(ch) && res[ch] >= start) {
            start = res[ch] + 1;
        }
        res[ch] = i;
        
        maxL = std::max(maxL, i - start + 1);
    }
    std::cout << maxL;
}
