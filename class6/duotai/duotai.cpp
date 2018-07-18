//虚函数&多态
    //-》多态即调用不同的函数，完成不同的功能
    //-》子类重写父类的虚函数实现多态，要求函数名、参数列表、返回值完全相同
    //-》虚函数的重写指的是子类定义了一个与父类完全的虚函数时，子类的这个函数重写(覆盖)了父类的虚函数
    //-》父类的virtual关键字必须写，子类的可写可不写，建议写

//多态形成的必要条件：
    //-》继承
    //-》虚函数的重写
    //-》父类的指针/引用，不能是对象

#include <iostream>
#include <string>
using namespace std;

class Person
{
    public:
        virtual void BuyTickets()//父类的虚函数关键字必须在
        {
            cout<<"买票--全价"<<endl;
        }
    protected:
        string _name;//姓名
};

class Student : public Person
{
    public:
        virtual void BuyTickets()
        {
            cout<<"买票--半价"<<endl;
        }
    protected:
        int _num;//学号
};

class Solider : public Person
{
    public:
        virtual void BuyTickets()
        {
            cout<<"买票--免票"<<endl;
        }
    protected:
        int _id;//编号
};

//void Fun(Person& p)
void Fun(Person* p)
{
    p->BuyTickets();
    //p.BuyTickets();
}

void Test()
{
    Person p;
    Student s;
    Solider sl;
    //Fun(p);
    //Fun(s);
    //Fun(sl);
    Fun(&p);
    Fun(&s);
    Fun(&sl);
}

int main()
{
    Test();
    return 0;
}
