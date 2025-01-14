/*
//https://contest.yandex.ru/contest/24414/run-report/130681131/
-- ПРИНЦИП РАБОТЫ --
Алгоритм представляет реализацию хэш-таблицы, с использованием метода цепочек для решений коализий.
В качестве хэш-функции используется эта формула (key % size + size) % size, которая гарантирует, что
результат будет всегда положительным.
Каждый слот таблицы содержит связный список пар. Если несколько ключей имеют одинаковый хеш, их значения 
хранятся в одном списке.
-- ДОКАЗАТЕЛЬСТВО КОРРЕКТНОСТИ --
Использование метода цепочек для разрешения коллизий гарантирует, что каждая операция корректно 
выполняется даже при совпадении хешей для разных ключей.
Хеш-функция распределяет ключи равномерно по индексам таблицы, минимизируя вероятность коллизий.
-- ВРЕМЕННАЯ СЛОЖНОСТЬ --
O(1).
-- ПРОСТРАНСТВЕННАЯ СЛОЖНОСТЬ --
Хэш-таблица - O(size),
Cвязанный список - O(n),
Итого - O(size+n).
*/
#include <iostream>
#include <string>
#include <vector>
#include <list>

class HashTable {
private:
    static const int size = 100003;
    std::vector<std::list<std::pair<int, int>>> table;

    int hash(int key) const {
        return (key % size + size) % size;
    }

public:
    HashTable() : table(size) {}

    std::string get(int key) {
        int hsh = hash(key);
        for (auto& pair : table[hsh]) {
            if (pair.first == key) {
                return std::to_string(pair.second);
            }
        }
        return "None";
    }

    void put(int key, int value) {
        int hsh = hash(key);
        for (auto& pair : table[hsh]) {
            if (pair.first == key) {
                pair.second = value;
                return;
            }
        }
        table[hsh].emplace_back(key, value);
    }

    std::string del(int key) {
        int hsh = hash(key);
        for (auto it = table[hsh].begin(); it != table[hsh].end(); ++it) {
            if (it->first == key) {
                int value = it->second;
                table[hsh].erase(it);
                return std::to_string(value);
            }
        }
        return "None";
    }
};


int main() {
    int n = 0;
    std::cin >> n;
    std::cin.ignore();

    HashTable ht;

    for(int i = 0; i < n; ++i) {
        std::string str;
        std::cin >> str;

        if(str == "get") {
            int key = 0;
            std::cin >> key;
            std::cout << ht.get(key) << '\n';
        } else if(str == "put") {
            int key = 0, value = 0;
            std::cin >> key >> value;
            ht.put(key, value);
        } else if(str == "delete") {
            int key = 0;
            std::cin >> key;
            std::cout << ht.del(key) << '\n';
        }
    }
    return 0;
}