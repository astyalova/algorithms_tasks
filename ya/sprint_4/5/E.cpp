#include <iostream>
#include <string>

int hash(std::string str, int a, int m, int beg, int end) {
    long long hash = 0;
    long long power = 1; 

    for (int i = end; i >= beg; --i) {
        int ascii_code = static_cast<int>(str[i]);
        hash = (hash + ascii_code * power) % m;
        power = (power * a) % m;
    }
    return hash;
}

int main() {
    int a, m;
    std::string str;
    
    std::cin >> a >> m;
    std::cin.ignore();  

    std::getline(std::cin, str);

    int n = 0;

    std::cin >> n;
    std::cin.ignore();

    for(int i = 0; i < n; ++i) {
        int beg = 0, end = 0;
        std::cin >> beg >> end;
        beg -= 1;
        end -= 1;
        std::cout << hash(str, a, m, beg, end) << std::endl;
    }
    return 0;
}
