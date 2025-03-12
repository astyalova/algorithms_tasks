// #include <iostream>
// #include <vector>

//  struct Node{
//             int value;
//             Node* next;
//         };

// class Queue{
//     private:

//     int size_n = 0;
//     public:

//     bool isEmpty() {
//         return size_n == 0;
//     }

//     void put(int x) {
//         Node* head = nullptr;

//         // if(size_n != max_n) {
//         //     queue[tail] = x;
//         //     tail = (tail + 1)%max_n;
//         //     size_n += 1;
//         // } 
//     }

//     void get() {
//         if(isEmpty()) {
//             std::cout << "None" << '\n';
//         } else {
//             std::cout << queue[head] << '\n';
//         }
//     }    

//     void size() {
//         std::cout << size_n << '\n';
//     }

// };

// int main() {
//     Queue queue;
//     int n = 0;
//     std::cin >> n;
//     std::cin.ignore();

//     for(int i = 0; i < n; ++i) {
//         std::string command;
//         std::cin >> command;
//         if(command == "put") {
//             int n = 0;
//             std::cin>>n;
//             queue.push(n);
//         } else if(command == "get") {
//             queue.pop();
//         } else if(command == "size") {
//             queue.size();
//         }
//     }
// return 0;
//}

#include <iostream>

void stairs_builder(int n) {
    if(n > 0) {
    std::cout << "Осталось построить " << n << " ступеней." << std::endl;
    stairs_builder(n - 1);
    std::cout << "Осталось постр " << n << " ступеней." << std::endl;
    } else {
        return;
    }
}

int main() {
    stairs_builder(5);
    return 0;
} 