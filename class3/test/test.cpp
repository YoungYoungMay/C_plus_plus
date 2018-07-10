//类&对象(概念及定义)


//面向对象三大特性:封装、继承、多态

////1.class声明的类默认是私有的；struct声明的类默认是公有的
//#include <iostream>
//using namespace std;
//
//class Person
//{
//    int a;
//    void Display()
//    {
//        cout<<a<<endl;
//    }
//};
//
//struct Person1
//{
//    int b;
//    void Display()
//    {
//        cout<<b<<endl;
//    }
//};
//
//int main()
//{
//    Person p;
//    p.a = 5;
//    //Person1 p1;
//    //p1.b = 6;
//    p.Display();
//    //p1.Display();
//    return 0;
//}

//封装的实现：数据和方法封装在一起；访问限定符


////2.成员函数的声明和定义
//#include <iostream>
//using namespace std;
//
////(1)类内定义成员函数
////class Person
////{
////    public:
////        void Display()//成员函数
////        {
////            cout<<_name<<"-"<<_sex<<"-"<<_age<<endl;
////        }
////    public://成员变量
////        char* _name;
////        char* _sex;
////        int _age;
////};
//
////(2)类外定义成员函数
//class Person
//{
//    public:
//        void Display();//成员函数
//    public://成员变量
//        char* _name;
//        char* _sex;
//        int _age;
//};
//void Person::Display()
//{
//    cout<<_name<<"-"<<_sex<<"-"<<_age<<endl;
//}
//
//int main()
//{
//    //将类实例化为一个对象
//    Person p;
//    p._name = "YoungJack";
//    p._sex = "男";
//    p._age = 25;
//    p.Display();
//
//    //可以通过指针修改
//    Person* ptr = &p;
//    ptr->_name = "满舒克";
//    ptr->_sex = "男";
//    ptr->_age = 28;
//    ptr->Display();
//
//    return 0;
//}


////3.每个对象的大小为类中所有成员变量大小之和,且遵循内存对齐原则
//#include <iostream>
//using namespace std;
//
//class A
//{
//    char ch;
//    double d;
//};
//
//class B
//{
//    char ch;
//    A a;
//    char ch2;
//};
//
//int main()
//{
//    int size1 = sizeof(A);
//    int size2 = sizeof(B);
//    cout<<size1<<endl;
//    cout<<size2<<endl;
//    return 0;
//}


////4.空类的大小为1字节
#include <iostream>
using namespace std;

class A
{

};

int main()
{
    cout<<sizeof(A)<<endl;
    return 0;
}
