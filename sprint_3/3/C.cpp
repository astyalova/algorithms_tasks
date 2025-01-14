#include <iostream>
#include <string>

bool isSubsequence(const std::string& s, const std::string& t) {
    int i = 0;
    int j = 0;

    while (i < s.size() && j < t.size()) {
        if (s[i] == t[j]) {
            i++;
        }
        j++;
    }
    return i == s.size();
}

int main() {
    std::string s, t;
    std::cin >> s >> t;

    if (isSubsequence(s, t)) {
        std::cout << "True\n";
    } else {
        std::cout << "False\n";
    }

    return 0;
}
