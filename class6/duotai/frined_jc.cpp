//友元与继承
    //-》友元关系不能继承，即基类友元不能访问子类私有和保护成员

#include <iostream>
#include <string>
using namespace std;

class Person
{
        friend void Display(Person& p, Student& s);
    protected:
        string _name;
};

class Student:public Person
{
    protected:
        int _num;
};

void Display(Person& p, Student& s)
{
    cout<<p._name<<endl;
    cout<<s._name<<endl;
    cout<<s._num<<endl;
}

void Test()
{
    Person p;
    Student s;
    Display(p, s);
}

int main()
{
    Test();
    return 0;
}
