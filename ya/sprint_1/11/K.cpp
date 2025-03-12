#include <iostream>
#include <string> 
#include <vector>
#include <algorithm>

int main() {
   int n = 0;
   std::cin >> n;
   long long arr[n];
   std::string f_number;

   for(long long  i = 0; i < n; ++i) {
      std::cin >> arr[i];
      f_number.push_back(arr[i]+'0');
   }   
   int k = 0;
   std::cin >> k;
   std::vector <int> result;
   int carry = k;

   for(int i = f_number.size()-1; i >= 0; --i) {
      int char_to_number = f_number[i] - '0';
      int digit = char_to_number%10;
      int sum = digit + carry;
      result.push_back(sum%10);
      carry = sum/10;
   }

   while(carry > 0) {
      result.push_back(carry%10);
      carry /= 10;
   }

   std::reverse(result.begin(), result.end());

   for(auto n : result) {
      std::cout << n << " ";
   }
   return 0;
}