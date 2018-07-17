//写时拷贝

#include <iostream>
#include <string.h>
using namespace std;

class String
{
    public:
        //构造函数
        String(const char* str = "")
        {
            _str = new char[strlen(str)+1];
            strcpy(_str, str);
            _pcount = new int(1);
        }

        //s2(s1)
        String(const String& s)//浅拷贝构造
        {
            _str = s._str;
            _pcount = s._pcount;
            ++(*_pcount);
        }

        //s1 = s2
        String& operator=(const String& s)//赋值运算符
        {
            //if(this != &s)
            if(_str != s._str)
            {
                if(--(*_pcount) == 0)
                {
                    delete[] _str;
                    delete _pcount;
                }
                _str = s._str;
                _pcount = s._pcount;
                ++(*_pcount);
            }
            return *this;
        }

        ~String()//析构函数
        {
            //要保证当前对象是唯一一个使用它的，才可以释放内存
            if(--(*_pcount) == 0)
            {
                delete[] _str;
                delete _pcount;
            }
        }

        void CopyOnWrite()//写时拷贝
        {
            if(*_pcount > 1)
            {
                char* tmp = new char[strlen(_str)+1];
                strcpy(tmp, _str);
                --(*_pcount);

                _str = tmp;
                _pcount = new int(1);
            }
        }

        char& operator[](size_t pos)//重载[]
        {
            CopyOnWrite();
            return _str[pos];
        }

        const char& operator[](size_t pos) const
        {
            return _str[pos];
        }

        char* c_str()
        {
            return _str;
        }

    private:
        char* _str;
        //引用计数要实现内存共享，所以它应该是在堆上的数据，每个对象都有一个指向它的指针
        int* _pcount;//引用计数,使用int*可以使其指向同一块空间，否则只有一个对象能看到当前的引用计数
        size_t _size;
        size_t _capacity;
};

void TestString()
{
    String s1("hello");
    String s2(s1);
    s1[0] = 'x';
    
    //"读时也拷贝"
    cout<<s1[0]<<endl;
    cout<<s1.c_str()<<endl;
    cout<<s2.c_str()<<endl<<endl;
}

void TestString1()
{
    int begin = clock();
    String s1("111111111111111111111111111111111111111111111111111");
    for(size_t i=0; i<1000000; ++i)
        String s2(s1);
    int end = clock();
    cout<<end-begin<<endl;
}

int main()
{
    TestString();
    TestString1();
    return 0;
}
