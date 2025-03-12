#include <vector>
#include <iostream>
#include <algorithm>
#include <stack>

void dfs(int start, std::vector<int>&used, std::vector<std::vector<int>>&edges, int& counter) {
    used[start] = counter;
    for(const auto& to : edges[start]) {
        if(used[to] == -1) {
            dfs(to, used, edges, counter);
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
    
    std::vector<int>used(n, -1);
    int counter = 0;

    for(int i = 0; i < n; ++i) {
        if(used[i] == -1) {
            ++counter;
            dfs(i, used, edges, counter);
        }
    }

    std::cout << counter << std::endl;

for (int i = 1; i <= counter; ++i) {
        for (int j = 0; j < n; ++j) {
            if (used[j] == i) {
                std::cout << j + 1 << " ";
            }
        }
        std::cout << std::endl;
    }
}


