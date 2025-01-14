#include <iostream>
#include <cmath>
#include <algorithm>

int main() {
	int n = 0, k = 0, l = 1, r = 1;
	std::cin >> n >> k;
	int mod = static_cast<int>(std::pow(10, k));
	for(int i = 0; i < n; ++i) {
		std::swap(l, r);
        r = (l+r)%mod;
    }
    std::cout << l;
}