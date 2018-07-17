#include <iostream>
#include <string.h>
#include <stdlib.h>

using namespace std;
class String
{
    public:
        String(const char* str)
            :_str(new char[strlen(str)+1])
        {
            strcpy(_str, str);
        }

        //s2(s1)
        String(const String& s)
            :_str(NULL)
        {
           String tmp(s._str);
           swap(_str, tmp._str);
        }

        ////s1=s3
        //String& operator=(const String& s)
        //{
        //    if(this != &s)
        //    {
        //        String tmp(s._str);
        //        swap(_str, tmp._str);
        //    }
        //    return *this;
        //}

        //s1=s3
        String& operator=(String s)
        {
            swap(_str, s._str);
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

void TestString()
{
    String s1("YoungJack");
    String s2(s1);

    cout<<"s1# "<<s1.c_str()<<endl;
    cout<<"s2# "<<s2.c_str()<<endl;

    String s3("this is YoungMay");
    s1 = s3;
    cout<<"s1# "<<s1.c_str()<<endl;
    cout<<"s3# "<<s3.c_str()<<endl;
}

int main()
{
    TestString();
    return 0;
}
