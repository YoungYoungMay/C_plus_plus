//纯虚函数
    //-》成员函数的形参后面写"=0"，成员函数成为虚函数
    //-》包含纯虚函数的类称为抽象类/接口类
    //-》抽象类不能实例化出对象；只有纯虚函数在子类中隐藏之后，才能实例化出对象
#include <iostream>
#include <string>
using namespace std;

class Person//抽象类/接口类
{
    virtual void Display() = 0;//纯虚函数

    protected:
        string _name;//姓名
};

class Student:public Person
{
    public:
        virtual void Display()
        {
            cout<<"Student-Display()"<<endl;
        }
    protected:
        int _num;
};


int main()
{
    //抽象类不能实例化出对象
    //Person p;

    //重写虚函数的子类，可以实例化出对象
    Student s;
    s.Display();
    return 0;
}
