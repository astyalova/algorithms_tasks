#include <iostream>
#include <vector>

long long catalan_number(int n) {
    if (n == 0 || n == 1) return 1; 

    long long catalan = 1;

    for (int i = 1; i <= n; ++i) {
        catalan = catalan * (2 * (2 * i - 1)) / (i + 1);
    }

    return catalan;
}

int main() {
    int n;
    std::cin >> n;
    std::cout << catalan_number(n) << '\n';
    return 0;
}
