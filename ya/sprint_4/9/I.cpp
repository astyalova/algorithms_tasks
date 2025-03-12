#include <iostream>
#include <vector>

class MyQueueSized {
    private:

        std::vector <int> queue;
        int head;
        int tail;
        int size_n;
        int max_n;

    public:

    MyQueueSized(int n) {
        queue.resize(n);
        head = 0;
        tail = 0;
        size_n = 0;
        max_n = n;
    }

    bool isEmpty() {
        return size_n == 0;
    }

    void push(int x) {
        if(size_n != max_n) {
            queue[tail] = x;
            tail = (tail + 1)%max_n;
            size_n += 1;
        } else {
            std::cout << "error" << '\n';
        }
    }

    void pop() {
        if(isEmpty()) {
            std::cout << "None" << '\n';
        } else {
            int x = queue[head];
            queue[head] = 0;
            head = (head + 1)%max_n;
            size_n -= 1;
            std::cout << x << '\n';
        }
    }

    void peek() {
        if(isEmpty()) {
            std::cout << "None" << '\n';
        } else {
            std::cout << queue[head] << '\n';
        }
    }    

    void size() {
        std::cout << size_n << '\n';
    }

};

int main() {
    
    int n = 0;
    int size = 0;
    std::cin >> size >> n;
    std::cin.ignore();
    MyQueueSized queue(n);

    for(int i = 0; i < size; ++i) {
        std::string command;
        std::cin >> command;
        if(command == "push") {
            int n = 0;
            std::cin>>n;
            queue.push(n);
        } else if(command == "pop") {
            queue.pop();
        } else if(command == "peek") {
            queue.peek();
        } else if(command == "size") {
            queue.size();
        }
    }
return 0;
}