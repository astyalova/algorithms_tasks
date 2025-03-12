/*
https://contest.yandex.ru/contest/25070/run-report/133214978/
ПРИНЦИП РАБОТЫ

Алгоритм реализует поиск максимального остовного дерева с использованием модифицированного алгоритма Крускала.
Читаю входные данные, сортирую рёбра по убыванию весаб использую структуру DSU для эффективного объединения 
компонент связности.
Перебираю рёбра в отсортированном порядке добавляя их в остовное дерево, если они соединяют разные компоненты.
Если после обработки всех рёбер в дереве оказалось n-1 рёбер, вывожу суммарный вес. В противном случае граф 
несвязный, и выводится кодовая фраза.

ДОКАЗАТЕЛЬСТВО КОРРЕКТНОСТИ
Алгоритм Крускала гарантирует построение минимального остовного дерева при сортировке рёбер по возрастанию 
веса. Так как нужно максимальное дерево, сортирую рёбра по убыванию и применяю тот же принцип.
Каждое добавляемое ребро имеет максимальный возможный вес, который не создаёт цикла.
Если бы существовало другое остовное дерево с большим весом, оно включало бы рёбра меньшего веса, что 
противоречит построенному дереву.
Использование DSU гарантирует, что будет выбрано ровно n-1 рёбер, если граф связен.

ВРЕМЕННАЯ СЛОЖНОСТЬ
Сортировка рёбер O(m log m),
Инициализация DSU O(n),
Объединение компонент и поиск корня O(α(n)), где α(n) обратная функция Акермана,
Обход рёбер O(m α(n))
Итоговая сложность = O(m log m).

ПРОСТРАНСТВЕННАЯ СЛОЖНОСТЬ
Список рёбер занимает O(m)
массивы parent и rank занимают O(n)
Итоговая сложность = O(n+m)
*/

#include <iostream>
#include <vector>
#include <algorithm>

struct Edge {
    int u, v, w;
    bool operator<(const Edge &other) const {
        return w > other.w;  
    }
};

struct DSU {
    
public:
    DSU(int n) {
        parent.resize(n + 1);
        rank.resize(n + 1, 0);
        for (int i = 1; i <= n; i++) {
            parent[i] = i;
        }
    }
    
    bool unite(int a, int b) { 
        a = find(a); 
        b = find(b); 
        if (a == b) return false; 
        if (rank[a] < rank[b]) std::swap(a, b); 
        parent[b] = a; 
        if (rank[a] == rank[b]) rank[a]++; 
        return true; 
    } 

    private:
    std::vector<int> parent, rank;
    
    int find(int x) { 
        if (parent[x] == x) return x; /
        return parent[x] = find(parent[x]); 
    }
};

int main() { 
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    int n, m; 
    std::cin >> n >> m; 
    
    std::vector<Edge> edges(m); 
    for (auto &edge : edges) { 
        std::cin >> edge.u >> edge.v >> edge.w; 
    } 
    
    std::sort(edges.begin(), edges.end()); 
    
    DSU dsu(n); 
    int maxTreeWeight = 0, edgesUsed = 0; 
    
    for (const auto &edge : edges) { 
        if (dsu.unite(edge.u, edge.v)) { 
            maxTreeWeight += edge.w; 
            edgesUsed++; 
        } 
    } 
    
    if (edgesUsed == n - 1) { 
        std::cout << maxTreeWeight << "\n"; 
    } else { 
        std::cout << "Oops! I did it again" << "\n"; 
    } 
    
    return 0; 
}
