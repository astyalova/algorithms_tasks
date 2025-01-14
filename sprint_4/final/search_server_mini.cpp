/*

С Наступающим!!!

https://contest.yandex.ru/contest/24414/run-report/130633287/

-- ПРИНЦИП РАБОТЫ --
Эта поисковая система решает задачу поиска релевантных документов по запросам с использованием 
инвертированного индекса.
Сначала строю инвертированный индекс, который хранит для каждого слова список документов, в которых оно 
встречается и частоту вхождений в эти документы.
Для каждого запроса извлекаю все уникальные слова из запроса. Для каждого слова запроса проверяю,
есть ли оно в инвертированном индексе, и если оно есть, то обновляю релевантность документов, добавляя 
к сумме частоты этого слова.
После обработки всех слов запроса для каждого документа, сортирую документы по двум критериям:1)по убыванию 
релевантности (сумма частот всех слов запроса), 2) при равной релевантности по возрастанию номера документа.
Вывожу итоговые документы.

-- ДОКАЗАТЕЛЬСТВО КОРРЕКТНОСТИ --
Инвертированный индекс построен корректно, так как каждому слову сопоставляется список документов,
и для каждого слова правильно считается его частота в каждом документе.
Каждый запрос обрабатывается правильно, для каждого слова запроса корректно обновляю релевантность документов.
Сортировка документов работает корректно, сначала сортируем по релевантности, а затем по номеру 
документа, если равны.

-- ВРЕМЕННАЯ СЛОЖНОСТЬ --
Построение инвертированного индекса: Разбиваю каждый документ на слова, что требует O(l) времени,
где l — длина документа. Для всех документов сложность будет O(t), где t — общее количество слов во 
всех документах.
Обработка запросов: Для каждого слова запроса доступ к инвертированному индексу выполняется за O(1).Перебор 
документов, содержащих хотя бы одно слово из запроса, и обновление релевантности документов требует O(n), 
где n — количество таких документов. Сортировка релевантных документов выполняется за O(n * log(n)), 
где n — количество документов.
Для одного запроса общая сложность: O(w + n * log(n)), где w — количество слов в запросе, n — количество 
документов, которые содержат хотя бы одно из слов запроса.
Для всех запросов общая сложность: q * (w + n * log(n))), где q — количество запросов.
Итоговая сложность:O(t + q * (w + n * log(n)))

-- ПРОСТРАНСТВЕННАЯ СЛОЖНОСТЬ --
Инвертированный индекс требует O(n) памяти, где n — количество уникальных слов, умноженное на количество 
документов, в которых они встречаются.
Для хранения всех документов требуется O(t), где t — суммарное количество символов во всех документах.
Для обработки запросов дополнительно требуется O(q) памяти для хранения списка релевантных документов.
Общая сложность по памяти: O(n * q + t + q)

*/

#include <iostream>
#include <unordered_map>
#include <algorithm>
#include <string>
#include <sstream>
#include <vector>
#include <unordered_set>


std::vector<std::string> splitting(const std::string& str) {
    std::vector<std::string> words;
    std::istringstream stream(str);
    std::string word;
    while (stream >> word) {
        words.push_back(word);
    }
    return words;
}

std::unordered_map<std::string, std::unordered_map<int, int>> build_inverted_index(const std::vector<std::string>& documents) {
    std::unordered_map<std::string, std::unordered_map<int, int>> inverted_index;

    for (int i = 0; i < documents.size(); ++i) {
        auto words = splitting(documents[i]);
        for (const auto& word : words) {
            inverted_index[word][i]++;
        }
    }
    return inverted_index;
}

std::unordered_map<int, int> calculate_relevance(const std::vector<std::string>& query_words, const std::unordered_map<std::string, std::unordered_map<int, int>>& inverted_index) {
    std::unordered_map<int, int> relevance;

    std::unordered_set<std::string> unique_query_words(query_words.begin(), query_words.end());

    for (const auto& word : unique_query_words) {
        if (inverted_index.find(word) != inverted_index.end()) {
            for (const auto& [doc_id, freq] : inverted_index.at(word)) {
                relevance[doc_id] += freq;
            }
        }
    }
    return relevance;
}

std::vector<int> get_top_documents(const std::unordered_map<int, int>& relevance) {
    std::vector<std::pair<int, int>> results(relevance.begin(), relevance.end());

    std::sort(results.begin(), results.end(), [](const std::pair<int, int>& a, const std::pair<int, int>& b) {
        if (a.second != b.second) {
            return a.second > b.second; 
        }
        return a.first < b.first; 
    });

    std::vector<int> top_docs;
    int size = std::min(5, static_cast<int>(results.size()));

    for (int i = 0; i < size; ++i) {
        top_docs.push_back(results[i].first + 1); 
    }
    return top_docs;
}

void print_results(const std::vector<int>& top_docs) {
    for (const auto& doc_id : top_docs) {
        std::cout << doc_id << " ";
    }
    std::cout << "\n";
}

int main() {
    int n = 0;
    std::cin >> n;
    std::cin.ignore();
    std::vector<std::string> documents(n);
    for (int i = 0; i < n; ++i) {
        std::getline(std::cin, documents[i]);
    }

    auto inverted_index = build_inverted_index(documents);

    int m = 0;
    std::cin >> m;
    std::cin.ignore();
    
    for (int q = 0; q < m; ++q) {
        std::string query;
        std::getline(std::cin, query);

        auto query_words = splitting(query);
        
        auto relevance = calculate_relevance(query_words, inverted_index);
        
        auto top_docs = get_top_documents(relevance);

        print_results(top_docs);
    }

    return 0;
}
