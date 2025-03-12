#include <vector>
#include <iostream>
#include <set>

int main() {
    int n = 0, m = 0;
    std::cin >> n >> m;

    std::vector<std::set<int>> edges(n);  

    for (int i = 0; i < m; ++i) {
        int u, v;
        std::cin >> u >> v;
        --u; --v;
        if (u != v) {  
            edges[u].insert(v);
            edges[v].insert(u);
        }
    }

    for (int i = 0; i < n; ++i) {
        if (edges[i].size() != n - 1) { 
            std::cout << "NO\n";
            return 0;
        }
    }

    std::cout << "YES\n";
}
