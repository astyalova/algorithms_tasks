/*
https://contest.yandex.ru/contest/22781/run-report/129248725/
-- ПРИНЦИП РАБОТЫ --
Алгоритм реализуют вычисление обратной польской аннотации. Где в стеке временно хранятся числа для выполнения
операций. Входная строка парсится по токенам с помощью std::istringstream. Если токен операнд, то с помощью функции
stoi преобразуется в int и кладется на вершинку стека. Если токен оператор, то из стека извлекаются два числа, 
правый операнд(второй) и левый(первый), над ними совершается операция, а после результат кладется на вершину
стека. Для деление используется округление. После обработки всех токенов в стеке остается результат.
-- ДОКАЗАТЕЛЬСТВО КОРРЕКТНОСТИ --
За счет того, что числа хранятся в стеке, можно эффективно производить вычисления.
-- ВРЕМЕННАЯ СЛОЖНОСТЬ --
Для n токенов (чисел и операторов) выполняется O(n) операций.
Таким образом, временная сложность алгоритма O(n).
-- ПРОСТРАНСТВЕННАЯ СЛОЖНОСТЬ --
Алгоритм использует стек для хранения чисел и переменные для вычислений. Пространственная сложность для стека:
 O(n). Временные переменные (left, right, res) занимают O(1) памяти. Переменные для работы со строкой 
 (std::istringstream, std::string token) также занимают O(1) памяти. Итоговая: O(n).
*/

#include <stack>
#include <string>
#include <iostream>
#include <sstream>
#include <cmath>

int reverse_polish_notation(std::string str) {
    std::stack <int> numbers;
    std::istringstream stream(str);
    std::string token;

    while(stream >> token) {
        if(isdigit(token.back())) {
            numbers.push(std::stoi(token));
        } else {
            int res = 0;
            int right = numbers.top();
            numbers.pop();
            int left = numbers.top();
            numbers.pop();
            if(token == "+") {
                res = left + right;
                numbers.push(res);
            } else if(token == "-") {
                res = left - right;
                numbers.push(res);
            } else if(token == "*") {
                res = right * left;
                numbers.push(res);
            } else if(token == "/") {
                res = std::floor(static_cast <double>(left)/right);
                numbers.push(res);
            }
        }
    }
    return numbers.top();
}

int main() {
    std::string str;
    std::getline(std::cin, str);
    std::cout << reverse_polish_notation(str) << '\n';
}