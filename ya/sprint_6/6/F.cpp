#include <vector>
#include <iostream>
#include <algorithm>
#include <queue>


int bfs(int start, int end, std::vector<int>&used, std::vector<std::vector<int>>&edges) {
    int min = 99;
    std::queue<int> planned;
    used[start] = 0;
    planned.push(start);

    while(!planned.empty()) {
        int u = planned.front();
        planned.pop();

        for(const auto& to : edges[u]) {
            if(used[to] == -1) {
                used[to] = used[u] + 1;
                if(to == end) {
                    min = std::min(min, used[to]);
                    return min;
                }
                planned.push(to);
            }
        }
    }
    return -1;
}

#include <vector>
#include <iostream>
#include <algorithm>

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

    int start, end;

    std::cin >> start >> end;

    --start;
    --end;

    std::vector<int> used(n, -1);

    if(start == end) {
        std::cout << 0;
    } else {
        std::cout << bfs(start, end, used, edges);
    }
}