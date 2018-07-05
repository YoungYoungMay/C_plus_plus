//C++的基础知识

////1.命名空间
////->名字隔离，解决全局命名冲突的问题
//
//#include <iostream>
////#include <stdio.h>
//
////using namespace std;//std是C++标准库的命名空间
//
////(2)
////int a = 10;
//
//////(3)定义在不同命名空间的相同变量不会冲突
////namespace name1
////{
////    int a =10;
////}
////
////namespace name2
////{
////    int a = 20;
////}
//
//////(4)将name1中展开到全局中,访问时不指定域也可以访问到
////using namespace name1;
//
//int main()
//{
//    ////(4)展开name1后，可直接访问到
//    //std::cout<<a<<std::endl;
//
//    ////(3)指定命名空间访问就不会冲突
//    //std::cout<<name1::a<<std::endl;
//    //std::cout<<name2::a<<std::endl;
//
//    ////(2)全局变量和局部变量访问时就近原则->结果a=20
//    //int a = 20;
//    //printf("%d\n", a);//只要引入头文件，C的语句也可以执行
//    //cout<<a<<endl;
//    
//    ////(1)这里::为作用域解析符，指定cout使用的命名空间为std
//    //std::cout<<"hello world"<<std::endl;
//    return 0;
//}



////2.C++输入输出
////->C++可以自动识别输入输出类型
//#include <iostream>
//
//using namespace std;
//
//int main()
//{
//    int a = 1;
//    double b = 2.22;
//    cout<<"a="<<a<<endl;
//    cout<<"b="<<b<<endl;
//
//    cout<<"please enter numbers"<<endl;
//    cin>>a>>b;
//    cout<<"a="<<a<<endl;
//    cout<<"b="<<b<<endl;
//    return 0;
//}


//3.函数重载
//->同一作用域类，一组函数的函数名相同，参数列表(个数/类型)不同，返回值可同可不同



//4.缺省参数
#include <iostream>
using namespace std;

//(1)全缺省参数
int Add1(int a=0, int b=0)
{
    return a+b;
}

//(2)半缺省参数
//->从右向左缺省，缺省参数必须连续
int Add2(int a, int b=0)
{
    return a+b;
}

int main()
{
    int a = Add1();
    int b = Add1(1);
    int c = Add1(1, 1);
    int d = Add2(2);
    int e = Add2(2, 2);

    cout<<a<<endl;
    cout<<b<<endl;
    cout<<c<<endl;
    cout<<d<<endl;
    cout<<e<<endl;
    return 0;
}
