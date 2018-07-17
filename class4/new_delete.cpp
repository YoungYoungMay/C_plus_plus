//C++动态内存管理

//1.new/delete
    //-》动态管理对象
//new[]/delete[]
    //-》动态管理对象数组
//必须成对使用
#include <iostream>
#include <stdlib.h>
using namespace std;

class AA
{
    public:
        AA()
        {
            cout<<"AA()"<<endl;
        }
        ~AA()
        {
            cout<<"~AA()"<<endl;
        }
};

class MyVector
{
    public:
        MyVector(size_t n)
        {
            _a = new int[n];          
            cout<<"MyVector()"<<endl;
        }
        ~MyVector()
        {
            delete[] _a;
            cout<<"~MyVector()"<<endl;
        }
    private:
        int* _a;
};

int main()
{
    ////1.动态开空间
    //AA* p1 = (AA*)malloc(sizeof(AA));
    //free(p1);
    ////2.调用构造函数初始化、析构函数清理
    //AA* p2 = new AA;
    //delete p2;
    //MyVector* pv = new MyVector(10);
    //delete[] pv;
    ////3.语言坑-》下面两种用法一样
    //int* p5 = (int*)operator new(4);
    //int* p6 = (int*)malloc(4);

    //
    allocator<AA>alloc;
    AA* p7 = alloc.allocate(1);//内存池
    new(p7)AA;//定位new replacement

    return 0;
}









