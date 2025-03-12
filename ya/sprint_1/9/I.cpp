#include <iostream>

int main() {
   int n = 0;
   std::cin >> n;
   bool is_Pow = false;
   int last_num = 0;

   for(double i = n; i > 0; i = i/4) {
      if(i == 1 && last_num%4 == 0) {
         is_Pow = true;
      }
      last_num = i;
   }   

   if(is_Pow) {
      std::cout << "True";
   } else {
      std::cout << "False";
   }
   return 0;
}