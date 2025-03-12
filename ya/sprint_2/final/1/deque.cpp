/*
https://contest.yandex.ru/contest/22781/run-report/129170899/
-- ПРИНЦИП РАБОТЫ --
Я реализовала дек ограниченной длины с помощью кольцевого буффера.
После добавления элемента в начало индекс head уменьшается, но если он доходит до конца массива,
он заворачивается в конец.
После добавления элемента в конец индекс tail увеличивается, но если он доходит до конца массива,
он заворачивается в начало.
После удаления элемента в начале индекс head увеличивается переходя к следующему элементу, если он достигает
конца массива, то вовзращается в начало.
После удаления элемента в конце индекс tail уменьшается.
-- ДОКАЗАТЕЛЬСТВО КОРРЕКТНОСТИ --
Исходя из этого алгоритма, когда мы удаляем или добавляем элемент, мы не используем выделение памяти, а просто 
сдвигаем индексы, что влияет на эффективность.
-- ВРЕМЕННАЯ СЛОЖНОСТЬ --
Из-за того, что не нужно выделять память, каждая операция выполняется за O(1). Для инициализации использую список инициализации. Для 
вектора O(n), для остальных переменных O(1). Суммарное время работы складывается из общих операций и равно O(n)+O(1) = O(n);
-- ПРОСТРАНСТВЕННАЯ СЛОЖНОСТЬ --
Основной объем памяти занимает вектор интов, он занимает O(n), где n - количество заданных элементов, поэтому
пространственная сложность будет O(n).
*/

#include <vector>
#include <iostream>

class Deque {
    std::vector <int> deque;
    int max_n;
    int head;
    int tail;
    int size;
public:
    Deque(int n) : deque(n), head(0), tail(0), max_n(0), size(0) {}

    bool is_empty() {
        return size == 0;
    }
    void push_back(int value) {
        if(size == max_n) {
            std::cout << "error" << '\n';
        } else {
            deque[tail] = value;
            tail = (tail + 1)%max_n;
            size += 1;
        }
    } 
    void push_front(int value) {
        if(size == max_n) {
            std::cout << "error" << '\n';
        } else {
            head = (head - 1 + max_n)%max_n;
            deque[head] = value;
            size += 1;
        }
    }
    void pop_front()  {
        if(is_empty()) {
            std::cout << "error" << '\n';
        } else {
            int x = deque[head];
            head = (head + 1)%max_n;
            size -= 1;
            std::cout << x << '\n';
        }
    } 

    void pop_back() {
        if(is_empty()) {
            std::cout << "error" << '\n';
        } else {
            tail = (tail - 1  + max_n)%max_n;
            int x = deque[tail];
            size -= 1;
            std::cout << x << '\n';
        }
    } 


};

int main() {
    
    int n = 0;
    int size = 0;
    std::cin >> size >> n;
    //std::cin.ignore();
    Deque deque(n);

    for(int i = 0; i < size; ++i) {
        std::string command;
        std::cin >> command;
        if(command == "push_back") {
            int n = 0;
            std::cin>>n;
            deque.push_back(n);
        } else if(command == "push_front") {
            int n = 0;
            std::cin>>n;
            deque.push_front(n);
        } else if(command == "pop_front") {
            deque.pop_front();
        } else if(command == "pop_back") {
            deque.pop_back();
        }
    }
return 0;
}