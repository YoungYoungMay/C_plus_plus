//指针&引用&const

////1.引用
////->给一个已存在的变量起一个别名
//
//#include <iostream>
//using namespace std;
//
//int main()
//{
//    int a = 1;
//    int& b = a;
//    cout<<"a="<<a<<endl;
//    cout<<"b="<<b<<endl;
//    cout<<"a address"<<&a<<endl;
//    cout<<"b address"<<&b<<endl;
//    
//    //可以对一个引用变量再引用，是别名的别名
//    int&c = b;
//    cout<<"c="<<c<<endl;
//    //修改引用变量，对应的原变量的值随之改变
//    c = 4;
//    cout<<"a="<<a<<" b="<<b<<" c="<<c<<endl;
//    cout<<"address "<<"a:"<<&a<<" b:"<<&b<<" c:"<<&c<<endl;
//    return 0;
//}

////2.const引用
//#include <iostream>
//using namespace std;
//
//int main()
//{
//    //int a = 5;
//    //const int& b = a;
//    //cout<<"a="<<a<<" b="<<b<<endl;
//    //a = 6;
//    //cout<<"a="<<a<<" b="<<b<<endl; 
//    ////常量不能被修改
//    ////b = 7;//这句是错误的
//
//    ////定义别名时，权限不能放大，只能缩小
//    //const int a = 5;
//    ////int& b = a;//这句错误，只读变量不能转化为可写可读的
//    //const int&b = a;//只有常属性可以引用常量
//    //cout<<"a="<<a<<" b="<<b<<endl;
//    
//    double a = 1.1;
//    //a赋值给b时要生成一个临时变量，b其实引用的是那个带有常性的临时变量，而不是a，所以不能赋值
//    //int& b = a;//这句是错误的
//    const int& b = a;
//    cout<<"a="<<a<<" b="<<b<<endl;
//    
//    return 0;
//}


////3.引用作为参数
//#include <iostream>
//using namespace std;
//
////(1)值传递->交换不了两个数的值
//void Swap1(int a, int b)
//{
//    int ret = a;
//    a = b;
//    b = ret;
//}
//
////(2)引用传递->可以交换两个数的值
////->可以提高效率
//void Swap2(int& a, int& b)
//{
//    int ret = a;
//    a = b;
//    b = ret;
//}
//
////(3)指针传递->可以交换两个数的值
//void Swap3(int* a, int* b)
//{
//    int ret = *a;
//    *a = *b;
//    *b = ret;
//}
//
//int main()
//{
//    int a = 10;
//    int b = 20;
//    cout<<"a="<<a<<" b="<<b<<endl;
//
//    Swap1(a, b);
//    cout<<"a="<<a<<" b="<<b<<endl;
//    
//    int& c = a;
//    Swap2(a, b);
//    cout<<"a="<<a<<" b="<<b<<endl;
//    
//    Swap3(&a, &b);
//    cout<<"a="<<a<<" b="<<b<<endl;
//    
//    return 0;
//}


////4.测试值传递/引用传递的效率
////->引用传递的效率较高
//#include <iostream>
//#include <time.h>
//using namespace std;
//
//struct Bigdata
//{
//    int arr[1000];
//};
//
//void DealBigdata(Bigdata& x)
//{
//    x.arr[0] = 0;
//    x.arr[1] = 1;
//    x.arr[2] = 2;
//}
//
//void DealBigdata1(Bigdata x)
//{
//    x.arr[0] = 0;
//    x.arr[1] = 1;
//    x.arr[2] = 2;
//}
//
//int main()
//{
//    Bigdata bd;
//    struct timespec ts;
//    //在windows下也可以用GetTickCount()函数
//    clock_t begin = clock();//该函数用于获取从系统启动到执行到该句的毫秒数
//    int  i = 0;
//    for(; i<1000000; i++)
//    {
//        //DealBigdata(bd);
//        DealBigdata1(bd);
//    }
//    clock_t end = clock();
//    cout<<end-begin<<endl;
//    return 0;
//}


////5.传值/传引用作返回值
//#include <iostream>
//using namespace std;
//
////(1)传值作返回值
////->尽量用于出作用域，返回的变量不在了的情况
//int Add(int a, int b)
//{
//    int ret = a + b;
//    //带回返回值的并不是ret,因为出该函数ret已经销毁，开辟了临时变量，复制了ret返回
//    return ret;
//}
//
////(2)传引用作返回值
////->尽量用于出作用域，返回的变量还在的情况
//int ret1;
//int& Add1(int a, int b)
//{
//    ret1 = a + b;
//    //带回返回值的并不是ret,因为出该函数ret已经销毁，开辟了临时变量，复制了ret返回
//    return ret1;
//}
//
//int main()
//{
//    int c = Add(3, 4);
//    cout<<c<<endl;
//    int d = Add1(3, 4);
//    cout<<d<<endl;
//    return 0;
//}


////6.若引用变量已引用了一个固定空间，只要其中的值改变，引用变量就会改变
//#include <iostream>
//using namespace std;
//
//int ret;
//
//int& Add(int a, int b)
//{
//    ret = a + b;
//    return ret;
//}
//
//int main()
//{
//    int& c = Add(20, 30);
//    cout<<c<<endl;
//    Add(200, 300);
//    cout<<c<<endl;
//    return 0;
//}
