//智能指针-》auto_ptr(C++98)
#include <iostream>
#include <vector>
using namespace std;

template<class T>
class AutoPtr
{
    public:
        AutoPtr(T* ptr)
            :_ptr(ptr)
        {}

        ~AutoPtr()
        {
            if(_ptr)
            {
                cout<<"delete: "<<_ptr<<endl;
                delete _ptr;
            }
        }

        T& operator*()
        {
            return *_ptr;
        }
        
        T*operator->()
        {
            return _ptr;
        }

        //管理权转移-》ap2(ap1)
        //保证在任意时刻一块空间只有一个指针指向,否则可能出现同一空间释放两次的情况
        //要保证传入的参数不具有常属性(临时变量就具有常属性)-》AutoPtr<int> b(AutoPtr<int> (new int))就会出错
        AutoPtr(AutoPtr<T>& ap)
            :_ptr(ap._ptr)
        {
            ap._ptr = NULL;
        }
        
        //ap3 = ap2
        //要先将ap3指向空间的指向关系释放，再拷贝，再将ap2的指针置空
        AutoPtr<T>& operator=(AutoPtr<T>& ap)
        {
            if(this != &ap)
            {
                if(_ptr)
                    delete _ptr;
                _ptr = ap._ptr;
                ap._ptr = NULL;
            }
            return *this;
        }

    private:
        T* _ptr;
};

struct AA
{
    int _a1;
    int _a2;
};

void Test1()
{
    AutoPtr<int> ap1(new int);
    *ap1 = 10;
    cout<<*ap1<<endl;

    AutoPtr<AA> ap2(new AA);
    (*ap2)._a1 = 10;
    ap2->_a2 = 20;
    //vector<int> v;
    //v.at(1);
}

void Test2()
{
    AutoPtr<int> ap1(new int);
    AutoPtr<int> ap2 = ap1;
    //因为管理权转移，所以走到这时ap1已经置为空了，所以下面再对ap1解引用会出错
    //*ap1 = 10;
    *ap2 = 20;
    ap2 = ap2;

    AutoPtr<int> ap3(new int);
    AutoPtr<int> ap4(new int);
    ap3 = ap4;
}

int main()
{
    //Test1();
    //Test2();
    
    return 0;
}
