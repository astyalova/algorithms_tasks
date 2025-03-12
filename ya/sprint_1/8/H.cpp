#include <iostream>
#include <algorithm>

int main() {

    std::string first, second, res;
    std::getline(std::cin, first);
    std::getline(std::cin, second);

    int carry = 0;
    int i = first.size() - 1;
    int j = second.size() - 1;

    while(i >= 0 || j >= 0 || carry) {

        if(i >= 0) {
            carry += first[i] - '0';
        }

        if(j >= 0) {
            carry += second[j] - '0';
        }

        res += carry % 2 + '0';

        carry /= 2;

        --i;
        --j;
    }

    std::reverse(res.begin(), res.end());

    std::cout << res;

    return 0;
}

