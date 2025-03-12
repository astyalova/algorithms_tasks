#include <iostream>

int main() {
   int n = 0;
   std::cin >> n;

   int arr[n];

   for(int i = 0; i < n; ++i) {
      std::cin >> arr[i];
   }

   int counter = 0;
   for(int i = 0; i < n; ++i) {
      int last_number = arr[i-1], next_number = arr[i+1];
      if( n == 1) {
         counter++;
      } else if (i == 0) {
         if(arr[i] > next_number) {
            counter++;
         }
      } else if(i == n-1) {
         if(arr[i] > last_number) {
            counter++;
         }
      } else if(arr[i] > last_number && arr[i] > next_number) {
         counter++;
      }
   }

   std::cout << counter << " ";

   return 0;
}