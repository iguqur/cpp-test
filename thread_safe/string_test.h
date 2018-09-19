#include <iostream>
#include <utility>
#include <thread>
#include <chrono>
#include <string>

void f1(std::string &string) {
    while (true) {
        int size = string.size();
        size = size;
        for (char &c : string) {
            c = 3;
        }
    }
}

void f2(std::string &string) {
    while (true) {
        int num = rand();
        for (int i=0; i<num && string.size()>1; ++i) {
            string.pop_back();
        }
        num = rand();
        for (int i=0; i<num && string.size()<1000; ++i) {
            string.push_back('d');
        }
    }
}

int main() {
    std::string string = "2sdf";
    std::thread t2(f1, std::ref(string)); // pass by value
    std::thread t3(f2, std::ref(string)); // pass by reference
    t2.join();
    t3.join();
    return 0;
}