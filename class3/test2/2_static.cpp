//类的静态成员
    //-》类的静态成员被该类的所有对象所共享

////1.静态成员的定义及使用
//#include <iostream>
//using namespace std;
//
//class Date
//{
//    public:
//        Date()
//        {
//            cout<<"Date()"<<endl;
//            ++sum;
//        }
//        void Display()
//        {
//            cout<<_year<<"-"<<_month<<"-"<<_day<<endl;
//        }
//        //静态成员函数
//            //-》只能访问静态成员变量
//            //-》无this指针
//        static void PrintSum()
//        {
//            cout<<sum<<endl;
//        }
//    private:
//        int _year;
//        int _month;
//        int _day;
//    private:
//        //静态成员变量
//            //-》计算对象大小时，不计入其中
//            //-》统计创建时间个数
//        static int sum;
//};
//
////定义并初始化静态成员变量
//int Date::sum = 0;
//
//int main()
//{
//    Date d1,d2;
//    //访问静态成员
//    d1.PrintSum();
//    d2.PrintSum();
//    Date::PrintSum();
//    return 0;
//}


//2.构造函数拷贝赋值函数的N种调用方法
#include <iostream>
using namespace std;

class Date
{
    public:
        Date()//构造
        {
            cout<<"Date()"<<endl;
        }
        Date(const Date& d)//拷贝构造
        {
            cout<<"Date(const Date& d)"<<endl;
        }
        Date& operator=(const Date& d)//赋值重载
        {
            cout<<"Date& operator=(const Date& d)"<<endl;
            return *this;
        }
        ~Date()
        {
            cout<<"~Date()"<<endl;
        }
};

//(1)Date对象作参数-》传值&传引用
void func1(Date d)
//void func1(Date& d)
{}

//(2)Date对象作返回值-》 传值&传引用
Date func2()
//Date& func2()
{
    Date d;
    return d;
}

//(3)Date对象作临时返回值-》 传值&传引用(编译器优化问题)
Date func3()
//Date& func3()
{
    return Date();
}

int main()
{
    Date d1;
    func1(d1);
    cout<<endl;

    Date d2 = func2();
    cout<<endl;

    Date d3;
    d3 = func3();

    return 0;
}
