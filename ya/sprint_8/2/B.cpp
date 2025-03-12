#include <iostream>
#include <vector>
#include <limits.h>
#include <algorithm>

bool compareString(std::string& s, std::string& t) {

    int n = s.size();
    int m = t.size();

    if(abs(n - m) > 1) return false;

    int left = 0;
    int right = 0;

    bool isEdited = false;
    while(left < n && right < m) {
        if(s[left] != t[right]) {

            if(isEdited) {
                return false;
            }

            if(n == m) {
                ++left;
                ++right;
            } else if(n < m) {
                ++right;
            } else {
                ++left;
            }

            isEdited = true;
        } 
        else {
            ++left;
            ++right;
        }
    }
    if(!isEdited) isEdited = true;
    return (isEdited || left < n || right < m);
}

int main() {
    std::string s;
    std::string t;

    std::getline(std::cin, s);
    std::getline(std::cin, t);
    
    compareString(s, t) ? std::cout<< "OK" : std::cout << "FAIL";
}

