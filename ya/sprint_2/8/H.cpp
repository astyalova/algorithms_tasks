#include <iostream>
#include <stack>
#include <string>

    bool is_correct_ch_seq(std::string str) {
        std::stack <char> res;
        if(str.empty()) {
            return true;
        }

        for(char ch : str) {
            if(ch == '(' || ch == '{' || ch == '[') {
                res.push(ch);
            } else {
                if (res.empty()) {
                    return false;
                }
                char symb = res.top();
                if ((symb == '(' && ch == ')') || (symb == '{' && ch == '}') || (symb == '[' && ch == ']')) {
                    res.pop();
                } else {
                    return false;
                }
            }
        }
        return res.empty();
    }

 int main() {
    std::string str;
    std::getline(std::cin, str);
    std::cout << (is_correct_ch_seq(str) ? "True" : "False");
    return 0;
 }
