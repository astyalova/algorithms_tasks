#include <iostream>
#include <vector>
#include <limits.h>
#include <algorithm>

void maxSub(std::vector<int>& x, int n) {
    std::vector<int> dp(n, 1);
    std::vector<int> prev(n, -1);

    int max_len = 0;
    int last_index = 0;

    for(int i = 0; i < n; ++i) {
        for(int j = 0; j < i; ++j) {
            if(x[j] < x[i] && dp[j] + 1 > dp[i]) {
                dp[i] = std::max(dp[j] + 1, dp[i]);
                prev[i] = j;
            }
        }

        if(dp[i] > max_len) {
            max_len = dp[i];
            last_index = i;
        }
    }

    std::vector<int> res;

    while(last_index != -1) {
        res.push_back(last_index + 1);
        last_index = prev[last_index];
    }

    std::cout << max_len << '\n';

    for(int i = max_len - 1; i >= 0; --i) {
        if(i == 0) {
            std::cout << res[i];
        } else {
            std::cout << res[i] << " ";
        }
    }
}


int main() {
    int n = 0;

    std::cin >> n;

    std::vector<int> x(n);

    for(int i = 0; i < n; ++i) {
        std::cin >> x[i];
    }

    maxSub(x, n);
}

