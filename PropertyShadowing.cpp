//
// Created by john on 18-8-2.
// 获取遮蔽的属性
//

#include <iostream>

using namespace std;

class A
{
public:
    int num = 1;
};

class B : public A
{
public:
    int num = 2;
};

int main() {
    B b;
    cout << b.num << endl;
    cout << b.A::num << endl;
//    cout << b.A << endl; // result: error

    return 0;
}