#include <iostream>
#include <vector>
#include <limits.h>
#include <algorithm>

int compareStringNew(std::string& s, std::string& t) {

    int n = s.size();
    int m = t.size();

    std::string sNew;
    std::string tNew;

    for(int i = 0; i < n; ++i) {
        if((s[i] - '0') % 2 == 0) {
            sNew += s[i];
        }
    }

    for(int i = 0; i < m; ++i) {
        if((t[i] - '0') % 2 == 0) {
            tNew += t[i];
        }
    }

    int ans = 0;

    if(sNew < tNew) {
        ans = -1;
    } else if(sNew > tNew) {
        ans = 1;
    }

    return ans;
}


int main() {
    std::string s;
    std::string t;

    std::getline(std::cin, s);
    std::getline(std::cin, t);
    
    std::cout << compareStringNew(s, t);
}

