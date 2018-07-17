//浅拷贝
#include <iostream>
#include <string.h>
#include <stdlib.h>

using namespace std;

class String
{
    public:
        String(const char* str)
            :_str(new char[strlen(str)+1])//+1是给'\0'留空间
        {
            strcpy(_str, str);//将'\0'也拷贝了
        }

        //String(const String&s)
        //    :_str(s._str)
        //{}

        String(const String& s)//将s拷贝给this
            :_str(new char[strlen(s._str)+1])
        {
            strcpy(_str, s._str);
        }

        ////(1)浅拷贝
        //    //-》字符串的默认赋值函数实现的是浅拷贝
        //String& operator=(const String& s)
        //{
        //    if(this != &s)
        //    {
        //        _str = s._str;
        //    }
        //    return *this;
        //}
        
        //(2)深拷贝
        String& operator=(const String& s)
        {
            if(this != &s)//若是自己给自己赋值，虽然内容不会变，但是地址会改变
            {
                char* tmp = new char[strlen(s._str)+1];
                strcpy(tmp, s._str);
                delete[] _str;
                _str = tmp;
            }
            return *this;
        }
        
        ~String()
        {
            if(_str)
            {
                delete[] _str;
                _str = NULL;
            }
        }

        char* c_str()
        {
            return _str;
        }

    private:
        char* _str;
};

int main()
{
    //(2)深拷贝
    String s1("hello");
    char* str1 = "hello";
    cout<<sizeof(s1)<<endl;
    cout<<sizeof(str1)<<endl;

    String s2(s1);
    cout<<"s1# "<<s1.c_str()<<endl;
    cout<<"s2# "<<s2.c_str()<<endl;
    
    String s3("world!!!!!!");
    s1 = s3;
    s1 = s1;
    cout<<"s1# "<<s1.c_str()<<endl;
    cout<<"s3# "<<s3.c_str()<<endl;

    ////(1)浅拷贝
    //String s1("hello");
    //String s2(s1);
    //cout<<"s1# "<<s1.c_str()<<endl;
    //cout<<"s2# "<<s2.c_str()<<endl;

    //String s3("world!!!!!!");
    //s1 = s3;
    //s1 = s1;
    //cout<<"s1# "<<s1.c_str()<<endl;
    //cout<<"s3# "<<s3.c_str()<<endl;
    return 0;
}
