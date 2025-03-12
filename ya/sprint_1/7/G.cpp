#include <iostream>
#include <string>
#include <algorithm>

int main() {
   int n = 0;
   std::cin >> n;
   std::string res;
   long long r = 0;

   for(int i = n; i > 0; i = i/2) {
      char ch = (i%2) + '0';
      res.push_back(ch);
   }

   std::reverse(res.begin(), res.end());

   if(n == 0) {
      r = 0;
   } else {
      r = std::stoll(res);
   }
   
   std::cout << r;
   return 0;
}