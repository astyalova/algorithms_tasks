/*
https://contest.yandex.ru/contest/25070/run-report/133215323/

ПРИНЦИП РАБОТЫ
Алгоритм основан на итеративном поиске в глубину (DFS) с использованием стека для подсчёта островов и нахождения их
максимального размера.
Каждая ячейка # представляет часть суши, а .  воду.
Алгоритм проходит по всей карте, и если встречает #, запускает итеративный DFS, помечая посещённые клетки.
DFS использует стек вместо рекурсии, что позволяет избежать переполнения стека вызовов.
При обходе учитываются только соседние клетки по горизонтали и вертикали.
После завершения DFS увеличивается счётчик островов и обновляется максимальный размер.

ДОКАЗАТЕЛЬСТВО КОРРЕКТНОСТИ
Каждый остров обходится ровно один раз, так как посещённые клетки помечаются в visited.
Использование стека гарантирует, что все соединённые клетки одного острова будут учтены.
Поиск начинается с непосещённой клетки #, что предотвращает двойной подсчёт.
Корректность достигается за счёт полного обхода всех возможных вариантов.

ВРЕМЕННАЯ СЛОЖНОСТЬ
В худшем случае DFS посещает все n * m клетки  O(n * m).
Каждый элемент обрабатывается один раз O(1) на каждую ячейку.
Итоговая сложность O(n * m).

ПРОСТРАНСТВЕННАЯ СЛОЖНОСТЬ
visited занимает O(n * m) памяти.
Стек в итеративной DFS в худшем случае может хранить O(n * m) элементов.
Итоговая сложность O(n * m).
*/

#include <iostream>
#include <vector>
#include <stack>

class WaterWorld {

public:
    WaterWorld(int n, int m) : n(n), m(m), grid(n, std::vector<char>(m)), visited(n, std::vector<bool>(m, false)) {}

    void readInput() {
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                std::cin >> grid[i][j];
            }
        }
    }

    int iterativeDFS(int x, int y) {
        std::stack<std::pair<int, int>> s;
        s.push({x, y});
        visited[x][y] = true;
        int size = 0;
        
        const int dx[] = {-1, 1, 0, 0};
        const int dy[] = {0, 0, -1, 1};

        while (!s.empty()) {
            auto [cx, cy] = s.top(); s.pop();
            size++;
            
            for (int d = 0; d < 4; ++d) {
                int nx = cx + dx[d], ny = cy + dy[d];
                if (nx >= 0 && nx < n && ny >= 0 && ny < m && grid[nx][ny] == '#' && !visited[nx][ny]) {
                    visited[nx][ny] = true;
                    s.push({nx, ny});
                }
            }
        }
        return size;
    }

    void solve() {
        int island_count = 0, max_size = 0;
        
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                if (grid[i][j] == '#' && !visited[i][j]) {
                    int size = iterativeDFS(i, j);
                    island_count++;
                    max_size = std::max(max_size, size);
                }
            }
        }
        std::cout << island_count << " " << max_size << std::endl;
    }

    private:
    int n, m;
    std::vector<std::vector<char>> grid;
    std::vector<std::vector<bool>> visited;
};

int main() {
    int n, m;
    std::cin >> n >> m;
    WaterWorld world(n, m);
    world.readInput();
    world.solve();
    return 0;
}
