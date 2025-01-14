#include <iostream>

int main() {
   int n = 0;
   std::cin >> n;

   std::string str;
   std::string str1;
   std::string str2;
   
   std::cin.ignore();
   std::getline(std::cin, str);

   for(size_t i = 0; i < str.size(); ++i) {
      if(str[i] == ' ') {
         if(str1.size() > str2.size()) {
            str2 = str1;
         }
         str1.clear();
      } else {
            str1.push_back(str[i]);
         } 
      } 

   if (str1.size() > str2.size()) {
      str2 = str1;
   }


   std::cout << str2 << '\n' << str2.size();

   return 0;
}