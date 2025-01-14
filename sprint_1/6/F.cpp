#include <iostream>
#include <cctype>

int main() {
   std::string str1;
   std::string str3;
   std::string str2;

   std::getline(std::cin, str1);
   for(size_t i = 0; i < str1.size(); ++i) {
      if(std::isalpha(str1[i]) || std::isdigit(str1[i])) {
         str3.push_back(std::tolower(str1[i]));
      }
   }

   for(int i = str3.size()-1; i >= 0; --i) {
      str2.push_back(str3[i]);
   }

   if(str3 == str2) {
      std::cout << "True";
   } else {
      std::cout << "False";
   }

   return 0;
}