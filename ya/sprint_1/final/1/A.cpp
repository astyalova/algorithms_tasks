//https://contest.yandex.ru/contest/22450/run-report/125350873/


#include <iostream>
#include <algorithm>
#include <vector>
#include <limits>

int main() {
   int n = 0;
   std::cin >> n;

   std::vector <long long> houses(n);
   
   for(int i = 0; i < n; ++i) {
      std::cin>>houses[i];
   }
   std::vector <int> houses_s(n, std::numeric_limits<int>::max());

   for(int i = 0; i < n; ++i) {
      if(houses[i] == 0) {
         houses_s[i] = 0;
      } else if (i > 0 && houses_s[i - 1] != std::numeric_limits<int>::max()){
         houses_s[i] = houses_s[i - 1] + 1;
      }
   }

   for(int i = n-1; i >= 0; --i) {
      if(houses[i] == 0) {
         houses_s[i] = 0;
      } else if (i < n-1 && houses_s[i + 1] != std::numeric_limits<int>::max()) {
         houses_s[i] = std::min(houses_s[i], houses_s[i + 1] + 1);
      }
   }

   for(size_t i = 0; i < houses_s.size(); ++i) {
      std::cout << houses_s[i] << " ";
   }

   return 0;
}