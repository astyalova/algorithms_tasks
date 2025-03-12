//https://contest.yandex.ru/contest/22450/run-report/125464969/

#include <iostream>
#include <vector>


int main() {
   int k = 0;
   std::cin >> k; 
   std::cin.ignore();

   std::vector<int> digit_count(10, 0);

   for(int i = 0; i <= 4; ++i) {
      std::string str;
      std::getline(std::cin, str);
      for (char c : str) {
         if (isdigit(c)) {
            int digit = c - '0'; 
            digit_count[digit]++;
         }
      }
   }

   int points = 0;
   for (int i = 1; i <= 9; ++i) {
      points += (digit_count[i] > 0 && digit_count[i] <= 2 * k);
   }

    std::cout << points << std::endl;
 
   return 0;
}