#include <iostream>
#include <string>

int main() {
    int a, m;
    std::string str;
    
    std::cin >> a >> m;
    std::cin.ignore();  

    std::getline(std::cin, str);

    long long hash = 0;
    long long power = 1; 

    for (int i = str.size() - 1; i >= 0; --i) {
        int ascii_code = static_cast<int>(str[i]);
        hash = (hash + ascii_code * power) % m;
        power = (power * a) % m;
    }

    std::cout << hash << std::endl;

    return 0;
}

    