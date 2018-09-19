#include <iostream>
#include <utility>
#include <thread>
#include <chrono>
#include <vector>

void f1(std::vector<int> &vector) {
    while (true) {
        for (int &num : vector) {
            num = 3;
        }
    }
}

void f2(std::vector<int> &vector) {
    while (true) {
        int res = rand() % 2;
        switch (res) {
            case 0:
                if (vector.size() < 5) {
                    for (int i=0; i< 1000; ++i) {
                        vector.push_back(5);
                    }
                } else {
                    vector.pop_back();
                    vector.resize(vector.size());
                }
                break;
            case 1:
                if (vector.size() > 1) {
                    vector.pop_back();
                    vector.resize(vector.size());
                } else {
                    for (int i=0; i< 1000; ++i) {
                        vector.push_back(78685565);
                    }
                }
                break;
        }
    }
}

int main() {
    std::vector<int> vector = {3};
    std::thread t2(f1, std::ref(vector)); // pass by value
    std::thread t3(f2, std::ref(vector)); // pass by reference
    t2.join();
    t3.join();
    return 0;
}