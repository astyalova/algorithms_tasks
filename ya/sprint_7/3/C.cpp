#include <vector>
#include <iostream>
#include <algorithm>

void dfs(int start, std::vector<bool>&used, std::vector<std::vector<int>>&edges) {
    used[start] = true;
    std::cout << start + 1 << " ";

    for(const auto& x : edges[start]) {
        if(!used[x]) {
            dfs(x, used, edges);
        }
    }
}

int main() {
    int n = 0, m = 0;

    std::cin >> n >> m;

    std::vector<std::vector<int>>edges(n);

    for(int i = 0; i < m; ++i) {
        int u, v;

        std::cin >> u >> v;

        --u;
        --v;

        edges[u].push_back(v);
        edges[v].push_back(u);
    }

    for(int i = 0; i < edges.size(); ++i) {
        std::sort(edges[i].begin(), edges[i].end());
    }

    int start = 0;

    std::cin >> start;

    --start;

    std::vector<bool>used(n, false);

    dfs(start, used, edges);
}


