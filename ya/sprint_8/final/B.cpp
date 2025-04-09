/*
https://contest.yandex.ru/contest/26133/run-report/135258591/

ПРИНЦИП РАБОТЫ

Алгоритм использует префиксное дерево (Tree) для хранения словаря и динамическое программирование для разбиения 
текста на слова.Добавляем в него все слова из словаря посимвольно, создавая новые узлы при необходимости.
В конце каждого слова помечаем соответствующий узел (is_word = true)
Создаем массив dp, где dp[i] = true, если можно разбить подстроку  на слова из словаря
Базовый случай: dp[0] = true, так как пустую строку всегда можно разбить
Если dp[left] = false, пропускаем (нельзя разбить). Запускаем поиск в Tree начиная с sentence[left]:
Если нашли слово (is_word = true), помечаем dp[right] = true

ДОКАЗАТЕЛЬСТВО КОРРЕКТНОСТИ

Префиксное дерево позволяет эффективно проверять, содержится ли подстрока в словаре
Это ускоряет процесс проверки слов, поскольку поиск выполняется за O(k), где k — длина слова
Если sentence[0, left] можно разбить (dp[left] = true), и sentence[left, right] — это слово из словаря,
то sentence[0, right] тоже можно разбить, значит, dp[right] = true
Мы перебираем все left и right, гарантируя нахождение разбиения, если оно существует

ВРЕМЕННАЯ СЛОЖНОСТЬ

Построение Tree: O(NK), где N — количество слов, K — средняя длина слова
В худшем случае каждое right двигается на O(K), поэтому сложность O(MK), где M — длина текста

Общий итог: O(NK + MK).

ПРОСТРАНСТВЕННАЯ СЛОЖНОСТЬ
Хранение Tree O(NK), тк в худшем случае создается N * K узлов
Хранение dp O(M)
Общий итог: O(NK + M).

*/

#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include <memory>

class TreeNode {
public:
    bool is_word = false;
    std::unordered_map<char, std::unique_ptr<TreeNode>> child;
};

class Tree {
private:
    std::unique_ptr<TreeNode> root;
public:
    Tree() {
        root = std::make_unique<TreeNode>();
    }

    void addWord(const std::string& word) {
        TreeNode* cur = root.get();
        for (char ch : word) {
            if (cur->child.find(ch) == cur->child.end()) {
                cur->child[ch] = std::make_unique<TreeNode>();
            }
            cur = cur->child[ch].get();
        }
        cur->is_word = true;
    }

    TreeNode* getRoot() { return root.get(); }
};

bool isSplite(const std::string& sentence, Tree& tree) {
    int m = sentence.size();
    std::vector<bool> dp(m + 1, false);
    dp[0] = true;
    TreeNode* root = tree.getRoot();

    for (int left = 0; left <= m; ++left) {
        if (!dp[left]) continue;
        TreeNode* cur = root;
        for (int right = left + 1; right <= m; ++right) {
            char ch = sentence[right - 1];
            if (cur->child.find(ch) == cur->child.end()) break;
            cur = cur->child[ch].get();
            if (cur->is_word) dp[right] = true;
        }
    }
    return dp[m];
}

int main() {
    std::string sentence;
    std::getline(std::cin, sentence);

    int n;
    std::cin >> n;
    std::cin.ignore();

    Tree tree;
    for (int i = 0; i < n; ++i) {
        std::string word;
        std::getline(std::cin, word);
        tree.addWord(word);
    }

    std::cout << (isSplite(sentence, tree) ? "YES" : "NO") << std::endl;
    return 0;
}
