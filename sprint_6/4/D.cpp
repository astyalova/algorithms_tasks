#include <vector>
#include <iostream>
#include <algorithm>
#include <queue>


void bfs(int start, std::vector<bool>&used, std::vector<std::vector<int>>&edges) {
    std::queue<int> planned;
    planned.push(start);
    used[start] = true;


    while(!planned.empty()) {
        int u = planned.front();
        planned.pop();

        std:: cout << u + 1 << " ";

        for(const auto& to : edges[u]) {
            if(!used[to]) {
                used[to] = true;
                planned.push(to);
            }
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
    
    for(int i = 0; i < n; ++i) {
        std::sort(edges[i].begin(), edges[i].end());
    }

    int s = 0;

    std::cin >> s;

    --s;
    
    std::vector<bool> used(n, false);

    bfs(s, used, edges);
}


