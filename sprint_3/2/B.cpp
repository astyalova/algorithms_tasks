#include <iostream>
#include <vector>
#include <algorithm>

std::vector<std::string> digit_to_chars = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"
};

void Combinations(const std::string &str, int index, std::string current, std::vector<std::string> &res) {
    
    if (index == str.size()) {
        res.push_back(current);
        return;
    }

    
    int digit = str[index] - '0';
    for (char ch : digit_to_chars[digit]) {
        Combinations(str, index + 1, current + ch, res);
    }
}

int main() {
    std::string str;
    std::getline(std::cin, str);

    std::vector<std::string> result;

    Combinations(str, 0, "", result);

   
    std::sort(result.begin(), result.end());

    for (size_t i = 0; i < result.size(); ++i) {
        std::cout << result[i];
        if (i != result.size() - 1) {
            std::cout << " ";
        }
    }
    std::cout << std::endl;

    return 0;
}
