//异常的捕获

#include <iostream>
#include <stdio.h>
#include <errno.h>
#include <stdlib.h>
#include <unistd.h>
using namespace std;

//int main()
//{
//    FILE* fout = fopen("file.txt", "R");
//    if(fout == NULL)
//    {
//        cout<<errno<<endl;
//        cout<<"open faild"<<endl;
//    }
//    return 0;
//}


//class Exception
//{
//    public:
//        Exception(int errld, const char* errMsg)
//            :_errld(errld)
//             ,_errMsg(errMsg)
//        {}
//
//        void What() const
//        {
//            cout<<"errld: "<<_errld<<endl;
//            cout<<"errMsg: "<<_errMsg<<endl;
//        }
//
//    private:
//        int _errld;//错误码
//        string _errMsg;//错误消息
//};
//
//void Test1()
//{
//    FILE* fout = fopen("file.txt", "r");
//    if(fout == NULL)
//    {
//        throw Exception(errno, "文件不存在");//抛出异常
//    }
//}
//
//void Test2()
//{
//    try
//    {
//        Test1();
//    }
//    catch(int errid)
//    {
//        cout<<errid<<__LINE__<<endl;
//    }
//    cout<<"继续执行"<<endl;
//}
//
//int main()
//{
//    try
//    {
//        Test2();
//    }
//    catch(char errid)
//    {
//        cout<<errid<<__LINE__<<endl;
//    }
//    catch(int errid)
//    {
//        cout<<errid<<__LINE__<<endl;
//    }
//    catch(Exception& e)
//    {
//        e.What();
//    }
//    return 0;
//}

class Exception
{

    public:
        Exception(int errid, const string& errmsg)
            :_errid(errid)
             ,_errmsg(errmsg)
        {}

        virtual const char* What()
        {
            return _errmsg.c_str();
        }

        virtual ~Exception()
        {}

    protected:
        int _errid;
        string _errmsg;
};

class SqlException:public Exception
{
    public:
        SqlException(int errid, const string& errmsg)
            :Exception(errid, errmsg)
        {}

        virtual const char* What()
        {
            cout<<"Sql Error: ";
            return _errmsg.c_str();
        }
};

class NetWorkException:public Exception
{
    public:
        NetWorkException(int errid, const string& errmsg)
            :Exception(errid, errmsg)
        {}

        virtual const char* What()
        {
            cout<<"NetWork Error: ";
            return _errmsg.c_str();
        }
};

void Sql()
{
    if(rand()%4 == 0)
    {
        try
        {
            char* p = new char[0x7fffffff];
        }
        //catch(...)
        catch(exception& e)
        {
            throw SqlException(1, "内存不足");
        }
    }

    if(rand()%3 == 0)
    {
        throw SqlException(1, "Sql语句错误");
    }

    if(rand()%7 == 0)
    {
        throw SqlException(2, "主键冗余");
    }
}

void Network()
{
    if(rand()%8 == 0)
    {
        throw NetWorkException(3, "超时请检查网络");
    }

    int* p1 = new int[10];
    try
    {
        Sql();//异常安全
    }
    catch(...)
    {
        delete[] p1;
        throw;//异常的重新抛出
    }
    delete[] p1;
}

int main()
{
    srand((unsigned int)time(NULL));

    while(1)
    {
        try
        {
            Network();
        }
        catch(Exception& e)
        {
            cout<<e.What()<<endl;
        }
        catch(...)
        {
            cout<<"未知异常"<<endl;
        }
        sleep(500);
    }
    return 0;
}
