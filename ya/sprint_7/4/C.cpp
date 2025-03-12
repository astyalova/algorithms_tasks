#include <iostream>
#include <vector>
#include <unordered_map>

const int MOD = 1000000007;

int fibonachi(int n) {
    int a = 1;
    int b = 1;
    int fib = 0;

	for(int i = 2; i <=n; ++i) {
        fib = (a + b) % MOD;
        b = a;
        a = fib;
	}
    return fib;
}

int main() {

    int n = 0;

    std::cin >> n;
    
    std::cout << fibonachi(n);

}