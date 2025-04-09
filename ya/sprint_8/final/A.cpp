/*
https://contest.yandex.ru/contest/26133/run-report/135234980/

ПРИНЦИП РАБОТЫ:

Алгоритм состоит из двух частей. Первая часть — распаковка строки, которая реализована с помощью 
рекурсии. Функция, проходя по символам входной строки, обрабатывает буквы и последовательности вида n[A], 
где n — количество повторов, а [A] — подстрока, которую необходимо распаковать рекурсивно. После получения 
распакованной строки для каждого входного выражения вторая часть алгоритма аходит наибольший общий префикс
среди всех полученных строк, обновляя его в процессе

ДОКАЗАТЕЛЬСТВО КОРРЕКТНОСТИ:

Если встречается цифра, это сигнализирует о том что далее идет конструкция вида n[A]. Алгоритм рекурсивно 
декодирует строку внутри скобок, а затем повторяет её нужное количество раз. Строки, которые не являются числами,
просто добавляются к результату.
Функция поиска общего префикса обрабатывает строки сразу, поочередно обновляя текущий префикс. 
Если на каком то шаге префикс пуст, алгоритм завершает выполнение

ВРЕМЕННАЯ СЛОЖНОСТЬ:
O(n * m), где n количество строк, m средняя длина строки после декодирования

ПРОСТРАНСТВЕННАЯ СЛОЖНОСТЬ:
O(m) -  Используется только O(m) памяти для хранения текущего префикса.

*/

#include <iostream>
#include <string>
#include <cctype>
#include <algorithm>

std::string decode(const std::string &s, size_t &i) {
    std::string result;
    while (i < s.size() && s[i] != ']') {
        if (isdigit(s[i])) {
            int count = s[i] - '0';
            i++;
            if (i < s.size() && s[i] == '[') {
                i++;
                std::string decodedPart = decode(s, i);
                if (i < s.size() && s[i] == ']') {
                    i++;
                }
                for (int j = 0; j < count; j++) {
                    result += decodedPart;
                }
            }
        } else {
            result.push_back(s[i]);
            i++;
        }
    }
    return result;
}

std::string decodeString(const std::string &s) {
    size_t i = 0;
    return decode(s, i);
}

std::string commonPrefix(const std::string &s1, const std::string &s2) {
    size_t minLength = std::min(s1.size(), s2.size());
    size_t i = 0;
    while (i < minLength && s1[i] == s2[i]) {
        i++;
    }
    return s1.substr(0, i);
}

int main() {
    int n;
    std::cin >> n;

    std::string commonPrefixStr;
    if (n > 0) {
        std::string packed;
        std::cin >> packed;
        commonPrefixStr = decodeString(packed);

        for (int i = 1; i < n; i++) { 
            std::string packed;
            std::cin >> packed;
            std::string decoded = decodeString(packed);

            commonPrefixStr = commonPrefix(commonPrefixStr, decoded);
            if (commonPrefixStr.empty()) {
                break;
            }
        }
    }

    std::cout << commonPrefixStr << std::endl;
    return 0;
}
