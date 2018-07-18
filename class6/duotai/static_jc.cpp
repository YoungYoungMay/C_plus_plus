//继承与静态成员
    //-》基类若定义了static成员，则整个继承体系中只有一个这样的成员
    //无论派生出多少个子类，都只有一个static成员

#include <iostream>
#include <string>
using namespace std;

class Person
{
    public:
        Person()
        {
            ++_count;
        }
    protected:
        string _name;//姓名
    public:
        static int _count;//统计人数
};

int Person::_count=0;

class Student:public Person
{
    protected:
        int _num;//学号
};

class Graduate:public Student
{
    protected:
        string _course;//研究科目
};

void Test()
{
    Student s1;
    Student s2;
    Student s3;
    Graduate s4;
    cout<<"人数"<<Person::_count<<endl;
    Student::_count = 0;
    cout<<"人数"<<Person::_count<<endl;
    Graduate::_count = 2;
    cout<<"人数"<<Person::_count<<endl;
}

int main()
{
    Test();
    return 0;
}
