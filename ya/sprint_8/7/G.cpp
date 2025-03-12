#include <iostream>
#include <vector>
#include <limits.h>
#include <algorithm>

void subArr(std::vector<int>& x, std::vector<int>& a) {
    int n = x.size();
    int m = a.size();

    std::vector<int> sub_a(m - 1, 0);

    for(int i = 1; i < m; ++i) {
        sub_a[i - 1] = abs(a[i] - a[i - 1]);
    }

    int k = m - 1;

    std::vector<int> res;
    for(int i = 0; i <= n - m; ++i) {
        std::vector<int> sub_x(m - 1);
        for(int j = 1; j < m; ++j) {
            sub_x[j - 1] = abs(x[i + j] - x[i + j - 1]);
        }
        if(sub_x == sub_a) {
            res.push_back(i + 1);
        }
    }

    for(const auto& x : res) {
        std::cout << x << " ";
    }
}


int main() {
    int n = 0;

    std::cin >> n;

    std::vector<int> x(n);

    for(int i = 0; i < n; ++i) {
        std::cin >> x[i];
    }

    int m = 0;

    std::cin >> m;

    std::vector<int> a(m);

    for(int i = 0; i < m; ++i) {
        std::cin >> a[i];
    }

    subArr(x, a);
}

