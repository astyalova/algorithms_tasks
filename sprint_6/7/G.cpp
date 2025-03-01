#include <vector>
#include <iostream>
#include <algorithm>
#include <queue>


int bfs(int start, std::vector<int>&used, std::vector<std::vector<int>>&edges) {
    std::queue<int> planned;
    used[start] = 0;
    planned.push(start);

    int max = 0;

    while(!planned.empty()) {
        int u = planned.front();
        planned.pop();

        for(const auto& to : edges[u]) {
            if(used[to] == -1) {
                used[to] = used[u] + 1;
                max = std::max(max, used[to]);
                planned.push(to);
            }
        }
    }
    return max;
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
    
    std::vector<int> used(n, -1);

    std::cout << bfs(s, used, edges);
}


