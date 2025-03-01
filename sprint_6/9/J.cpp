#include <vector>
#include <iostream>
#include <algorithm>
#include <stack>

int times = 0;

void dfs(int start, std::vector<bool>&used, std::vector<std::vector<int>>&edges, std::stack<int>& order) {
    used[start] = true;

    for(const auto& to : edges[start]) {
        if(!used[to]) {
            dfs(to, used, edges, order);
        }
    }
    order.push(start);
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

    std::stack<int>order;
    std::vector<bool> used(n, false);

    for(int i = 0; i < n; ++i) {
        if(!used[i]) {
            dfs(i, used, edges, order);
        }
    }

    while(!order.empty()) {
        std::cout << order.top() + 1 << " ";
        order.pop();
    }
}


