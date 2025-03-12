/*

https://contest.yandex.ru/contest/25597/run-report/134580738/

ПРИНЦИП РАБОТЫ:
Считаю общую сумму очков, если она нечетная возвращаю false. Создаю вектор dp размера S/2 + 1, в нем я буду 
хранить информацию о том, можно ли получить сумму от 0 до sum / 2  из текущих очков, dp[0] - базовый случай,
сумму 0 всегда достижима. Алгоритм проходит по каждому элементу массива points и обновляет вектор dp, пытаясь
собрать суммы от 0 до sum / 2. Если в конце значение dp[sum / 2] равно 1, значит, можно разбить массив на 
два подмножества с одинаковой суммой.

ДОКАЗАТЕЛЬСТВО КОРРЕКТНОСТИ:
Если массиве можно собрать сумму S/2 и сумма четная, то можно собрать и вторую такую сумма

ВРЕМЕННАЯ СЛОЖНОСТЬ:
О(n + s/2), где n длина массива points

ПРОСТРАНСТВЕННАЯ СЛОЖНОСТЬ:
O(n), так как используется массив dp


*/
#include <string>
#include <iostream>
#include <vector>

bool twoSum(int n, std::vector<int>& points) {
    int sum = 0;

    for(int i = 0; i < n; ++i) {
        sum += points[i];
    }

    if(sum % 2 != 0) {
        return false;
    }

    std::vector<int> dp(sum / 2 + 1, 0);
    dp[0] = 1;

    for(int i = 0; i < n; ++i) {
        for(int j = sum / 2; j >= points[i]; --j) {
            if(dp[j - points[i]]) {
                dp[j] = 1;
            }
        }
    }
    return dp[sum / 2];
}

int main() {
    int n = 0;

    std::cin >> n;

    std::vector<int> points(n);

    for(int i = 0; i < n; ++i) {
        std::cin >> points[i];
    }

    twoSum(n, points) ? std::cout << "True" : std::cout << "False";
	return 0;
}