#include <iostream>
#include <string.h>
#include <assert.h>
#include <stdlib.h>
using namespace std;

class String
{
    public:
        String(const char* str="")
            :_size(strlen(str))
             ,_capacity(_size)
        {
            _str = new char[_size+1];
            strcpy(_str, str);
        }

        //s1.Swap(s2)
        void Swap(String& s)
        {
            swap(_str, s._str);
            swap(_size, s._size);
            swap(_capacity, s._capacity);
        }

        //s2(s1)
        String(const String& s)
            :_str(NULL)
        {
            String tmp(s._str);
            this->Swap(tmp);
        }

        //s1=s3
        String operator=(String s)
        {
            this->Swap(s);
            //s.Swap(*this);
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

        void Expand(size_t n)//扩容函数
        {
            if(n > _capacity)
            {
                char* tmp = new char[n+1];//因为_capacity没有计算"\0",仅是有效字符的大小，'\0'是C语言字符串的结束标记
                strcpy(tmp, _str);
                delete[] _str;
                _str = tmp;
                _capacity = n;
            }
        }
       
        void Insert(size_t pos,char ch)//任意位置，插入一个字符
        {
            assert(pos <= _size);
            if(_capacity == _size)
                Expand(_capacity*2);
            int end = _size;
            while(end >= (int)pos)//注意size_t和int类型的比较，若牵扯到负数很容易出现问题
            {
                _str[end+1] = _str[end];
                --end;
            }
            _str[pos] = ch;
            ++_size;
        }

        void Insert(size_t pos, char* str)//任意位置插入一个字符串
        {
            assert(pos <= _size);
            size_t len = strlen(str);
            if(_size+len > _capacity)
                Expand(_size+len);
            int end = _size;
            while(end >= (int)pos)
            {
                _str[end+len] = _str[end];
                --end;
            }
            strncpy(_str+pos, str, len);
            _size += len;
        }

        void PopBack()//删除最后一个元素
        {
            assert(_size > 0);
            --_size;
            _str[_size] = '\0';
        }

        void Earse(size_t pos, size_t len)//从pos位置删除长度为len的字符串
        {
            assert(pos < _size);//==的位置是'\0'
            if(pos+len >= _size)
            {
                _str[pos] = '\0';
                _size = pos;
            }
            else
            {
                strcpy(_str+pos, _str+pos+len);
                _size -= len;
            }
        }

        size_t Find(char ch) const//查找一个字符
        {
            size_t i = 0;
            //这里最好不要用'\0'判断结束条件，因为字符串种可能刚好包含'\0'
            for(; i<_size; i++)
            {
                if(_str[i] == ch)
                    return i;
            }
            return npos;
        }

        size_t Find(const char* sub) const//查找字符串
        {
            char* src = _str;
            while(*src)
            {
                const char* src_tmp = src;
                const char* sub_tmp = sub;
                while((*sub_tmp) && (*src_tmp==*sub_tmp))
                {
                    ++sub_tmp;
                    ++src_tmp;
                }
                if(*sub_tmp == '\0')
                    return src-_str;//字符减去字符得到的整数
                else
                    ++src;

            }
            return npos;
        }

        void PushBack(char ch)//插入一个字符
        {
            if(_size == _capacity)
                Expand(_capacity*2);
            _str[_size] = ch;
            _str[_size+1] = '\0';
            ++_size;
            //Insert(_size, ch);
        }

        void Append(const char* str)//？
        {
            size_t len = strlen(str);
            if(_size+len > _capacity)
            {
                Expand(_size+len);
            }
            strcpy(_str+_size, str);
            _size += len;
            //Insert(_size, str);
        }

        //Capacity
        void Reserve(size_t n)//保留-》用来重新分配内存大小(在知道要分配多大的内存时使用)
        {
            Expand(n);
        }
        
        //Size+Capacity -》初始化
        void Resize(size_t n, char ch = '\0')
        {
            if(n < _size)
            {
                _size = n;
                _str[_size] = '\0';
            }
            else
            {
                if(n > _capacity)
                    Expand(n);
                size_t i = _size;
                for(; i<n; i++)
                    _str[i] = ch;
                _str[n] = '\0';
                _size = n;
            }
        }

        size_t Size()
        {
            return _size;
        }

        size_t Capacity()
        {
            return _capacity;
        }

        bool Empty()
        {
            return _size==0;
        }

        //s1 += "world"
        String& operator+=(const char* str)
        {
            this->Append(str);
            return *this;
        }

        //s1 += s2
        String& operator+=(const String& s)
        {
            //this->Append(s._str);
            *this += s._str; //this->operator+=(this, s._str)
            return *this;
        }

        //s1 + "hello"
        String operator+(const char* str)
        {
            String ret(*this);
            ret.Append(str);
            return ret;
        }

        //s1+s2
        String operator+(const String& s)
        {
            return *this+s._str;
        }

        char& operator[](size_t pos)
        {
            return _str[pos];
        }

        bool operator<(const String& s) const
        {
            const char* str1 = _str;
            const char* str2 = s._str;
            while(*str1 && *str2)
            {
                if(*str1 < *str2)
                    return true;
                else if(*str1 > *str2)
                    return false;
                else
                {
                    ++str1;
                    ++str2;
                }
            }
            if(*str1=='\0' && *str2=='\0')
                return true;
            return false;
        }
        
        bool operator==(const String& s)
        {
            const char* str1 = _str;
            const char* str2 = s._str;
            while(*str1 && *str2)
            {
                if(*str1 != *str2)
                    return false;
                ++str1;
                ++str2;
            }
            if(*str1=='\0' && *str2=='\0')
                return true;
            return false;
        } 
       
        bool operator<=(const String& s)
        {
            return (*this<s || *this==s);
        } 
        
        bool operator>(const String& s)
        {
            return !(*this <= s);
        } 
        
        bool operator>=(const String& s)
        {
            return !(*this < s);
        }
        
        bool operator!=(const String& s)
        {
            return !(*this == s);
        }

        char* c_str()
        {
            return _str;
        }

    private:
        char* _str;
        size_t _size;
        size_t _capacity;
    public:
        static size_t npos;
};

size_t String::npos = -1;

void TestString1()
{
    String s1("hello");
    String s2(s1);
    String s3("world!!!!!!!!");
    cout<<"s1# "<<s1.c_str()<<endl;
    cout<<"s2# "<<s2.c_str()<<endl;
    cout<<"s3# "<<s3.c_str()<<endl;

    swap(s1, s3);
    cout<<"s1# "<<s1.c_str()<<endl;
    cout<<"s2# "<<s2.c_str()<<endl;
    cout<<"s3# "<<s3.c_str()<<endl;
    
    s1.Swap(s3);
    cout<<"s1# "<<s1.c_str()<<endl;
    cout<<"s2# "<<s2.c_str()<<endl;
    cout<<"s3# "<<s3.c_str()<<endl<<endl;

}

void TestString2()
{
    String s1("hello");
    cout<<s1.c_str()<<endl;
    s1[0] = 'x';
    cout<<"s1[0]=x ->   "<<s1.c_str()<<endl;
    size_t i = 0;
    for(; i<s1.Size(); i++)
    {
        cout<<s1[i]<<"";
    }
    cout<<endl<<endl;
}

void TestString3()
{
    String s1("hello");
    cout<<s1.c_str()<<endl;
    s1.PushBack(' ');
    s1.Append("world");
    cout<<s1.c_str()<<endl;
    s1.Insert(5, ' ');
    cout<<s1.c_str()<<endl;
    s1.Insert(0, '!');
    cout<<s1.c_str()<<endl;
    String s2("!!!!!!");
    s1 += s2;
    cout<<s1.c_str()<<endl;
    cout<<s2.c_str()<<endl;
    String s3 = s2 + "JonyJ";
    cout<<s3.c_str()<<endl;
    cout<<s2.c_str()<<endl;
    s2 += "YoungJack";
    cout<<s2.c_str()<<endl<<endl;
}

void TestString4()
{
    //char buf[128];
    //size_t n = 10000;
    //int begin = clock();
    //String s1;
    //size_t i = 0;
    //for(; i<n; i++)
    //{
    //    itoa(i, buf, 10);//??????????
    //    s1 += buf;
    //}
    //int end = clock();
    //cout<<end-begin<<endl;
    //
    //int begin1 = clock();
    //String s2;
    //s2.Reserve(s1.Capacity());
    //for(i=0; i<n; i++)
    //{
    //    itoa(i, buf, 10);
    //    s2 += buf;
    //}
    //int end1 = clock();
    //cout<<end1-begin1<<endl;
}

void TestString5()
{
    String s1("hello world");
    cout<<s1.c_str()<<endl;
    s1.Earse(5,2);
    cout<<s1.c_str()<<endl;
    s1.Earse(5,10);
    cout<<s1.c_str()<<endl<<endl;
}

void TestString6()
{
    String s1("hello");
    size_t pos = s1.Find("llo");
    if(pos != String::npos)
        cout<<"找到了："<<pos<<endl<<endl;
}

void TestString7()
{
    int begin = clock();
    String s1("111111111111111111111111111111111111111111111111111111111111111");
    size_t i = 0;
    for(; i<1000000; i++)
    {
        String s2(s1);
    }
    int end = clock();
    cout<<end-begin<<endl;
}

int main()
{
    TestString1();
    TestString2();
    TestString3();
    TestString4();
    TestString5();
    TestString6();
    TestString7();
    return 0;
}
