#include <iostream>
#include <string> 
#include <unordered_map>

int main() {
   std::string s;
   std::string t;

   std::getline(std::cin, s);
   std::getline(std::cin, t);

   std::unordered_map <char, int> s1;
   std::unordered_map <char, int> t1;

   for(char ch : s) {
      s1[ch]++;
   }

   for(char ch : t) {
      t1[ch]++;
   }

   for(const auto& pair : t1) {
      if(s1.find(pair.first) == s1.end() || s1.at(pair.first) != pair.second) {
         std::cout << pair.first;
      }
   }

   return 0;
}