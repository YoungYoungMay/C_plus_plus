//C++对象模型-》探索单继承对象模型

#include <iostream>
#include <stdio.h>
using namespace std;

class Base
{
    public:
        virtual void func1()
        {
            cout<<"Base::func1()"<<endl;
        }
        virtual void func2()
        {
            cout<<"Base::func2()"<<endl;
        }
    private:
        int a;
};

class Derive:public Base
{
    public:
        virtual void func1()
        {
            cout<<"Derive::func1()"<<endl;
        }
        virtual void func3()
        {
            cout<<"Derive::func3()"<<endl;
        }
        virtual void func4()
        {
            cout<<"Derive::func4()"<<endl;
        }
    private:
        int b;
};

typedef void(*FUNC) ();
void PrintTable(int* VTable)
{
    cout<<"虚表地址"<<VTable<<endl;
    int i = 0;
    for(; VTable[i]!=0; ++i)
    {
        printf("第%d个虚函数地址:0x%x, ->", i, VTable[i]);
        FUNC f = (FUNC) VTable[i];
        f();
    }
    cout<<endl;
}

void Test()
{
    Base b1;
    Derive d1;
    int* VTable1 = (int*)(*(int*)&b1);
    int* VTable2 = (int*)(*(int*)&d1);
    PrintTable(VTable1);
    PrintTable(VTable2);
}

int main()
{
    Test();
    return 0;
}
