#include <iostream>
#include <vector>
#include <limits.h>

std::string reverseString(std::string& s) {
    std::string str = "";
    std::vector<std::string> words;

    for(char ch : s) {
        if(ch == ' ') {
            words.push_back(str);
            str = "";
        } else {
            str += ch;
        }
    }
    
    words.push_back(str);

    int n = words.size();
    int left = 0;
    int right = n - 1;

    while(left < right) {
        std::string temp = words[left];
        words[left] = words[right];
        words[right] = temp;

        ++left;
        --right;
    }
    
    std::string res = "";

    for(int i = 0; i < n; ++i) {
        res += words[i];
        if(i != n -1) {
            res += " ";
        }
    }
    return res;
}

int main() {
    std::string s;

    std::getline(std::cin, s);
    s = reverseString(s);

    for(const auto& ch : s) {
        std::cout << ch;
    }
}

