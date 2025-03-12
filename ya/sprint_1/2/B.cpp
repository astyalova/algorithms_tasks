#include <iostream>
#include <cmath>

int main() {
   int a = 0, b = 0, c = 0;
   std::cin >> a >> b >> c;
   if((abs(a)%2 != 0 && abs(b)%2 != 0 && abs(c)%2 != 0) || (abs(a)%2 == 0 && abs(b)%2 == 0 && abs(c)%2 == 0)) {
      std::cout << "WIN";
   } else {
      std::cout << "FAIL";
   }
   return 0;
}