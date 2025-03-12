/*
https://contest.yandex.ru/contest/23815/run-report/130355857/
-- ПРИНЦИП РАБОТЫ --
Алгоритм реализует in-place быструю сортировку (quick sort). Основной принцип работы:
Выбирается опорный элемент (pivot), середина текущего диапазона. Два указателя, i и j, 
перемещаются по массиву: i двигается вправо, пока элементы меньше опорного. j двигается 
влево, пока элементы больше опорного. Если указатели встретились или пересеклись,
диапазон делится на две части. Алгоритм рекурсивно сортирует обе части массива.
-- ДОКАЗАТЕЛЬСТВО КОРРЕКТНОСТИ --
На каждом этапе алгоритм корректно разделяет массив на две части. Левая часть содержит 
элементы, меньшие или равные опорному.Правая часть содержит элементы, большие опорного.
После разделения обе части сортируются рекурсивно, пока размер подмассивов не станет
равным единице. Используется перегруженный оператор <, который сравнивает участников
по заданным критериям.
-- ВРЕМЕННАЯ СЛОЖНОСТЬ --
В худшем случае O(n^2), если массив уже отсортирован или если эл-ты плохо сбалансированы
относительно pivot. 
-- ПРОСТРАНСТВЕННАЯ СЛОЖНОСТЬ --
Дополнительная память требуется только для переменных pivot, i, j, l, r, что составляет 
O(1). Для каждого уровня рекурсии требуется память для хранения границ текущего диапазона (l, r).
Максимальная глубина рекурсии — O(log n) в среднем случае, O(n) в худшем. Итоговая O(log n).
*/

#include <vector>
#include <algorithm>
#include <string>
#include <iostream>

struct Participant {
    std::string login;
    int problem_solved;
    int penalty;

    bool operator <(Participant& other) {

        if(problem_solved != other.problem_solved) {
            return problem_solved > other.problem_solved;
        }

        if(penalty != other.penalty) {
            return penalty < other.penalty;
        }

        return login < other.login;
    }
};

void quick_sort(std::vector<Participant>& p, int l, int r) {
    if(l >= r) {
        return;
    }
    
    Participant pivot = p[(l+r-1)/2];

    int i = l, j = r;
    while (i <= j) {
        while (p[i] < pivot) {
            i++;
        }

        while (pivot < p[j]) {
            j--;
        }

        if (i <= j) {
            std::swap(p[i], p[j]);
            i++;
            j--;
        }
    }

     if (l < j) {
        quick_sort(p, l, j);
    }

    if (i < r) {
        quick_sort(p, i, r);
    }
}

int main() {
    int n = 0;
    std::cin >> n;

    std::vector <Participant> participants(n);
    
    for(int i = 0; i < participants.size(); ++i) {
        std::cin >> participants[i].login >> participants[i].problem_solved >> participants[i].penalty;
    }

    quick_sort(participants, 0, n - 1);

    for (const auto& participant : participants) {
        std::cout << participant.login << '\n';
    }

    return 0;

}