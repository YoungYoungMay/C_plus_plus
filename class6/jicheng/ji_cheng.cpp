//继承
    //-》继承与转换
    //-》继承体系中的作用域

#include <iostream>
#include <string>
using namespace std;

////1.继承与转换--------》前提：public继承
//class Person//父类
//{
//    public:
//        //Person(const string& name)
//        //    :_name(name)
//        //{}
//
//        void Display()
//        {
//            cout<<_name<<endl;
//        }
//    protected:
//        string _name;
//};
//
//class Student : public Person//派生类（public继承)
//{
//    public:
//        int _num;
//};
//
//void Test()
//{
//    Person p;
//    Student s;
//
//    //(1)子类对象可以赋值给父类对象
//    p = s;
//
//    //(2)父类对象不可以赋值给子类对象
//    //s = p;
//
//    //(3)父类指针/引用可以指向子类对象
//    Person* p1 = &s;
//    Person& p2 = s;
//
//    //(4)子类的指针/引用不能指向父类对象(可以强转实现)
//        //-》因为p在前面本来就指向一个子类，再强转为子类没有问题
//        //-》若是p在前面指向的就是父类，强转是有问题的
//    Student* p3 = (Student*)&p;
//    Student& p4 = (Student&)p;
//
//    p3->_num = 10;//程序会崩溃？
//    p4._num = 20;
//    p.Display();
//}

//2.继承体系中的作用域
class Person
{
    public:
        Person(const char* name="", int id=0)
            :_name(name)
             ,_num(id)
        {}

    protected:
        string _name;//姓名
        int _num;//身份证号
};

class Student : public Person
{
    public:
        Student(const char* name, int id, int stuNum)
            :Person(name, id)
             ,_num(stuNum)
        {}

        void DisplayNum()
        {
            cout<<"身份证号# "<<Person::_num<<endl;
            cout<<"学号# "<<_num<<endl;
        }

    protected:
        //构成隐藏,就近访问
        int _num;//学号
};

void Test()
{
    Student s("jonyj", 110, 1);
    s.DisplayNum();
}

int main()
{
    Test();
    return 0;
}
