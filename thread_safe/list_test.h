#include <iostream>
#include <utility>
#include <thread>
#include <chrono>
#include <list>

void f1(std::list<int> &list) {
    while (true) {
        for (int &num : list) {
//            num = 3;
        }
    }
}

void f2(std::list<int> &list) {
    while (true) {
        int res = rand() % 2;
        switch (res) {
            case 0:
                if (list.size() < 5) {
                    list.push_back(5);
                } else {
                    list.pop_front();
                }
                break;
            case 1:
                if (list.size() > 1) {
                    list.pop_back();
                } else {
                    list.push_front(78685565);
                }
                break;
        }
    }
}

int main() {
    std::list<int> list = {3};
    std::thread t2(f1, std::ref(list)); // pass by value
    std::thread t3(f2, std::ref(list)); // pass by reference
    t2.join();
    t3.join();
    return 0;
}