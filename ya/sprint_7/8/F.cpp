
#include <iostream>
#include <vector>


int maxFlowers(std::vector<std::vector<char>>& field, int n, int m) {
    std::vector<std::vector<int>> dp(n, std::vector<int>(m, 0));

    dp[n - 1][0] = field[n - 1][0] - '0';

    for(int i = n - 2; i >= 0; --i) {
        dp[i][0] = dp[i + 1][0] + (field[i][0] - '0');
    }

    for (int j = 1; j < m; ++j) {
        dp[n - 1][j] = dp[n - 1][j - 1] + (field[n - 1][j] - '0');
    }

    dp[n-1][0] = field[n-1][0] - '0';
    for(int i = n - 2; i >= 0; --i) {
        for(int j = 1; j < m; ++j) {
            dp[i][j] = std::max(dp[i + 1][j], dp[i][j - 1]) + (field[i][j] - '0');
        }
    }

    return dp[0][m - 1];
}

int main() {

    int n = 0;
    int m = 0;

    std::cin >> n >> m;

    std::vector<std::vector<char>> field(n, std::vector(m, ' '));

    for(int i = 0; i < n; ++i) {
        for(int j = 0; j < m; ++j) {
            std::cin >> field[i][j];
        }
    }

    std::cout <<  maxFlowers(field, n, m);

}

