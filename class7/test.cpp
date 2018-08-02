//C++对象模型-》探索虚函数表

#include <iostream>
using namespace std;

class Base
{
    public:
        virtual void func1()
        {}
        virtual void func2()
        {}

    private:
        int a;
};

void Test()
{
    Base b1;
}

int main()
{
    Test();
    return 0;
}
