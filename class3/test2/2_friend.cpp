//类和对象-》友元
    //-》友元函数
    //-》友元类

////1.友元函数
//    //-》友元函数允许在类外访问该类中的任何成员
//    //友元函数不是类的成员函数
//    //友元函数可以通过对象访问所有成员，私有和保护成员也一样
//#include <iostream>
//using namespace std;
//
//class Date
//{
//        friend void Display(const Date& d);
//    private:
//        int _year;
//        int _month;
//        int _day;
//};
//
//void Display(const Date& d)
//{
//    cout<<d._year<<"-"<<d._month<<"-"<<d._day<<endl;
//}
//
//int main()
//{
//    Date d1;
//    Display(d1);
//    return 0;
//}

////2.输入输出运算符重载的友元函数
//#include <iostream>
//using namespace std;
//
//class Date
//{
//    public:
//        friend ostream& operator<<(ostream& out, const Date& d);
//        friend istream& operator>>(istream& in, Date& d);
//    private:
//        int _year;
//        int _month;
//        int _day;
//};
//
//ostream& operator<<(ostream& out, const Date& d)
//{
//    out<<d._year<<"-"<<d._month<<"-"<<d._day<<endl;
//    return out;
//}
//
//istream& operator>>(istream& in, Date& d)
//{
//    in>>d._year;
//    in>>d._month;
//    in>>d._day;
//    return in;
//}
//
//int main()
//{
//    Date d1;
//    cin>>d1;
//    cout<<d1;
//
//    //d1.operator<<(cout);
//    return 0;
//}


//3.友元类
    //-》整个类可以是另一个类的友元
    //-》友元类的所有成员函数都是另一个类的友元函数，都可访问另一个类中的protected/private成员
#include <iostream>
using namespace std;

class Time
{
    //Date是Time的友元，Date可访问Time中所有成员
        friend class Date;
    private:
        int _hour;
        int _minute;
        int _second;
};

class Date
{
    public:
        void Display()
        {
            cout<<_year<<"-"<<_month<<"-"<<_day<<"-"<<_t._hour<<"-"<<_t._minute<<"-"<<_t._second<<endl;
        }
    private:
        int _year;
        int _month;
        int _day;

        Time _t;
};

int main()
{
    Date d;
    d.Display();
    return 0;
}
