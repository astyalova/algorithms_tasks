#include <iostream>
#include <vector>

int main() {
    int n = 0, m = 0;

    std::cin >> n >> m;

    std::vector<std::vector<int>> edges(n + 1);

    for(int i = 0; i < m; ++i) {
        int u, v;

        std::cin >> u >> v;

        edges[u].push_back(v);
    }

    for(int i = 1; i <= n; ++i) {
        std::cout << edges[i].size() << " ";
        for(const auto& x : edges[i]) {
            if(x) {
                std::cout << x << " ";
            }
        }
        std::cout << std::endl;
    }
}

