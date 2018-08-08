//智能指针-》scoped_array(boost)
#include <iostream>
#include <vector>
using namespace std;

template<class T>
class ScopedArray
{
    public:
        ScopedArray(T* ptr)
            :_ptr(ptr)
        {}

        ~ScopedArray()
        {
            delete _ptr;
        }
        
        T& operator[](size_t index)
        {
            return _ptr[index];
        }

        //防拷贝-》不用拷贝构造及赋值重载函数
            //1.只声明不实现
            //2.声明成私有
    private:
        ScopedArray(const ScopedArray<T> & sp);
        ScopedArray<T>& operator=(const ScopedArray<T> sp);
    
    private:
        T* _ptr;
};

struct AA
{
    int _a1;
    int _a2;
};

void Test()
{
    ScopedArray<int> sa(new int[10]);
    sa[10] = 10;

    ScopedArray<AA> sa1(new AA[10]);
    sa1[0]._a1 = 10;
}

int main()
{
    Test();
    return 0;
}
