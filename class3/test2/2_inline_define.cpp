//类和对象-》内联inline & 宏

////1.用inline修饰的函数即内联函数，编译时C++编译器会将调用内联函数的地方展开
////-》这样没有函数压栈的开销，提高了程序运行的效率
//
//class Date
//{
//    public:
//        //定义在类中的成员函数默认为内联函数
//        void Func()
//        {}
//        void Display();
//    private:
//        int _year;
//        int _month;
//        int _day;
//};
//
//inline void Date::Display()//成员函数定义为内联
//{
//    cout<<_year<<"-"<<_month<<"-"<<_day<<endl;
//}
//
//inline void Test()//全局函数定义为内联
//{}



//2.C++建议尽量用const/枚举/内联替换掉宏，为什么？
//
//(1)宏的优点：
    //-》增强代码复用性
    //-》提高性能
//(2)宏的缺点
    //-》不方便调试(预编译阶段被替换了)
    //-》代码可读性差、可维护性差、容易误用
    //-》没有类型安全的检查
//#include <iostream>
//using namespace std;
//
//#define add(a,b) a+b
//
//int main()
//{
//    int a = 2;
//    int b = 3;
//    int c = 4;
//    int ret = add(a, b);
//    cout<<"expected is 5, actual is "<<ret<<endl;
//
//    ret = add(a, b)*c;
//    cout<<"expected is 20, actual is "<<ret<<endl;
//}

