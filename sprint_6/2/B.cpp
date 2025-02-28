#include <iostream>
#include <vector>

int main() {
    int n = 0;
    int m = 0;

    std::cin >> n >> m;
    std::vector<std::vector<int>> graph(n, std::vector<int>(n, 0));

    for(int i = 0; i < m; ++i) {
        int u = 0, v = 0;
        std::cin >> u >> v;
        --u;
        --v;
        graph[u][v] = 1;
        }

    for(int i = 0; i < n; ++i) {
        for(int j = 0; j < n; ++j) {
            std::cout << graph[i][j] << " ";
        }
        std::cout << '\n';
    }

    return 0;
}