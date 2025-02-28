/*
https://contest.yandex.ru/contest/24810/run-report/132496099/
ПРИНЦИП РАБОТЫ
Сортировка осуществляется с помощью построения max-кучи и последующего удаления максимальных элементов.
Алгоритм состоит из двух этапов:
Построение max-кучи: элементы массива организуются так, чтобы каждый родитель был больше своих потомков.
Упорядочивание: максимальный элемент (в корне) перемещается в конец массива, затем куча восстанавливается на 
оставшейся части массива.
Для восстановления свойства кучи используется операция "просеивание вниз", которая выполняется рекурсивно или итеративно.

ДОКАЗАТЕЛЬСТВО КОРРЕКТНОСТИ
Построение max-кучи гарантирует, что в корне всегда находится наибольший элемент. После перемещения его в конец массива 
восстанавливается свойство кучи на оставшейся части массива. Процесс повторяется до тех пор, пока массив не будет отсортирован.
Так как операция просеивание вниз поддерживает свойства кучи, алгоритм корректно сортирует массив по убыванию или возрастанию.

ВРЕМЕННАЯ СЛОЖНОСТЬ
Построение max-кучи:
Операция просеивание вниз вызывается для каждого элемента начиная с середины массива.
На каждом уровне требуется O(log n) времени (глубина дерева). Суммарная сложность построения кучи O(n)
Сортировка:
Для каждого из n элементов выполняется операция "просеивание вниз" с затратами O(log n) на каждую операцию.
Сложность этапа сортировки O(n log n)
Итоговая временная сложность алгоритма O(n log n)

ПРОСТРАНСТВЕННАЯ СЛОЖНОСТЬ
Алгоритм  не использует дополнительную память для хранения данных. Входной массив participants занимает 
O(n) памяти. Итоговая пространственная сложность O(n)
*/

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

struct Participant {
    std::string login;
    int solved;
    int penalty;
};

bool compare(const Participant &a, const Participant &b) {
    if (a.solved != b.solved) return a.solved > b.solved;
    if (a.penalty != b.penalty) return a.penalty < b.penalty;
    return a.login < b.login;
}

void heapify(std::vector<Participant> &heap, int n, int i) {
    while (true) {
        int largest = i;
        int left = 2 * i + 1;
        int right = 2 * i + 2;
        if (left < n && compare(heap[left], heap[largest])) largest = left;
        if (right < n && compare(heap[right], heap[largest])) largest = right;
        if (largest == i) break;
        std::swap(heap[i], heap[largest]);
        i = largest;
    }
}

void buildHeap(std::vector<Participant> &heap) {
    for (int i = heap.size() / 2 - 1; i >= 0; --i) {
        heapify(heap, heap.size(), i);
    }
}

void heapSort(std::vector<Participant> &participants) {
    buildHeap(participants);
    for (int i = participants.size() - 1; i > 0; --i) {
        std::swap(participants[0], participants[i]);
        heapify(participants, i, 0);
    }
}

int main() {
    int n;
    std::cin >> n;
    std::vector<Participant> participants(n);
    for (int i = 0; i < n; ++i) {
        std::cin >> participants[i].login >> participants[i].solved >> participants[i].penalty;
    }
    heapSort(participants);
    for (int i = n - 1; i >= 0; --i) {
        std::cout << participants[i].login << "\n";
    }
    return 0;
}
