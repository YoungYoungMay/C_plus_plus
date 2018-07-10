//类和对象——const


////1->const成员函数
////->在成员函数后面加const,const会指向this指针所指对象，即可保证这个const成员函数的对象在函数内不会被改变
//#include <iostream>
//using namespace std;
//
//class Date
//{
//    public:
//        Date(int year, int month, int day)
//        {
//            _year = year;
//            _month = month;
//            _day = day;
//        }
//        void Display()
//        {
//            cout<<"Display()"<<endl;
//            cout<<_year<<"-"<<_month<<"-"<<_day<<endl;
//        }
//        //编译器会处理为void Display(const Date* this)
//        void Display() const
//        {
//            cout<<"Display() const"<<endl;
//            cout<<_year<<"-"<<_month<<"-"<<_day<<endl;
//        }
//    private:
//        int _year;
//        int _month;
//        int _day;
//};
//
//void Test()
//{
//    Date d1(1998, 1, 1);
//    d1.Display();
//
//    const Date d2(1990, 1, 1);
//    d2.Display();
//}
//
//int main()
//{
//    Test();
//    return 0;
//}


//2."&"运算符
//取地址运算符的重载、const修饰的取地址运算符的重载都不需要重新定义，用系统默认的即可
#include <iostream>
using namespace std;

class Date
{
    public:
        Date(int year, int month, int day)
        {
            _year = year;
            _month = month;
            _day = day;
        }
        Date* operator&()
        {
            return this;
        }
        const Date* operator&() const
        {
            return this;
        }
    private:
        int _year;
        int _month;
        int _day;
};

int main()
{
    Date d(1998,1 ,1);
    cout<<&d<<endl;
    const Date d1(1900, 1, 1);
    cout<<&d1<<endl;
    return 0;
}

