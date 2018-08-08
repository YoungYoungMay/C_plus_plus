//智能指针-》scoped_ptr(boost)
#include <iostream>
#include <vector>
using namespace std;

template<class T>
class ScopedPtr
{
    public:
        ScopedPtr(T* ptr)
            :_ptr(ptr)
        {}

        ~ScopedPtr()
        {
            delete _ptr;
        }

        T& operator*()
        {
            return *_ptr;
        }

        T*operator->()
        {
            return _ptr;
        }

        //防拷贝-》不用拷贝构造及赋值重载函数
            //1.只声明不实现
            //2.声明成私有
    private:
        ScopedPtr(const ScopedPtr<T> & sp);
        ScopedPtr<T>& operator=(const ScopedPtr<T> sp);
    
    private:
        T* _ptr;
};

//template<class T>
//ScopedPtr<T>::ScopedPtr(const ScopedPtr<T>& sp)
//    :_ptr(sp._ptr)
//{}

void Test()
{
    ScopedPtr<int> sp(new int);
    //ScopedPtr<int> sp1(sp);
}

int main()
{
    Test();
    return 0;
}
