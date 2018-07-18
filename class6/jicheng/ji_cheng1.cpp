//子类的默认成员函数

#include <iostream>
using namespace std;

class Person
{
    public:
        Person(const char* name)//构造函数
            :_name(name)
        {
            cout<<"Person()"<<endl;
        }

        Person(const Person& p)//拷贝构造
            :_name(p._name)
        {
            cout<<"Person(const Person& p)"<<endl;
        }

        Person& operator=(const Person& p)//赋值重载
        {
            cout<<"Person operator=(const Person& p)"<<endl;
            if(this != &p)
                _name = p._name;
            return *this;
        }

        ~Person()
        {
            cout<<"~Person()"<<endl;
        }

    protected:
        string _name;//姓名
};

class Student : public Person
{
    public:
        Student(const char* name, int num)
            :Person(name)//构造匿名对象的方式
             ,_num(num)
        {
            cout<<"Student()"<<endl;
        }

        Student(const Student& s)
            :Person(s)
             ,_num(s._num)
        {
            cout<<"Student(const Student& s)"<<endl;
        }

        Student& operator=(const Student& s)
        {
            cout<<"Student operator=(const Student& s)"<<endl;
            if(this != &s)
            {
                Person::operator=(s);//与父类构成隐藏,所以要指定域访问
                _num = s._num;
            }
            return *this;
        }
        ~Student()//与父类构成隐藏
        {
            cout<<"~Student()"<<endl;
        }

        void Display()
        {
            cout<<_name<<"-"<<_num<<endl;
        }

    private:
        int _num;//学号
};

void Test()
{
    Student s1("jack", 18);
    s1.Display();
    Student s2(s1);
    s2.Display();
    Student s3("rose", 17);
    s3.Display();
    cout<<endl;
    s1 = s3;
    s1.Display();
    s2.Display();
    s3.Display();
}

int main()
{
    Test();
    return 0;
}
