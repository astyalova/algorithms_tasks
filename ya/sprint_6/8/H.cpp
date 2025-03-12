#include <vector>
#include <iostream>
#include <algorithm>

int times = 0;

void dfs(int start, std::vector<bool>&used, std::vector<std::vector<int>>&edges, std::vector<int>& entry, std::vector<int>& leave) {
    start == 0 ?  times += 0 : times += 1;
    entry[start] = times;
    used[start] = true;

    for(const auto& to : edges[start]) {
        if(!used[to]) {
            dfs(to, used, edges, entry, leave);
        }
    }

    times += 1;
    leave[start] = times;
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
    }

    for(int i = 0; i < edges.size(); ++i) {
        std::sort(edges[i].begin(), edges[i].end());
    }
    
    int s = 0;

    std::vector<bool> used(n, false);
    std::vector<int> entry(n, 0);
    std::vector<int> leave(n, 0);

    dfs(s, used, edges, entry, leave);

    for(int i = 0; i < n; ++i) {
        std::cout << entry[i] << " " << leave[i] << std::endl;
    }
}


