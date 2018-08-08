//智能指针-》shared_ptr(boost)
    //引用计数实现，允许多个指针指向同一对象
    //存在循环引用的问题

#include <iostream>
#include <vector>
using namespace std;

//前置声明
template<class T>
class WeakPtr;

template<class T>
class SharedPtr
{
    friend class WeakPtr<T>;
    public:
        SharedPtr(T* ptr)
            :_ptr(ptr)
        {
            _pcount = new int(1);
        }

        ~SharedPtr()
        {
            if(--(*_pcount) == 0)
            {
                delete _ptr;
                delete _pcount;
            }
        }

        //sp1(sp)
        SharedPtr(const SharedPtr<T>& sp)
            :_ptr(sp._ptr)
             ,_pcount(sp._pcount)
        {
            ++(*_pcount);
        }

        //sp1 = sp2
        //如果sp1是指向当前它指向空间的唯一一个指针，在被sp2覆盖之前，要将sp1与那块空间的联系解除
        SharedPtr<T>& operator=(const SharedPtr<T>& sp)
        {
            //if(this != &sp)
            if(_ptr != sp._ptr)
            {
                if(--(*_pcount) == 0)
                {
                    delete _pcount;
                    delete _ptr;
                }
                _ptr = sp._ptr;
                _pcount = sp._pcount;
                ++(*_pcount);
            }
            return *this;
        }

        T& operator*()
        {
            return *_ptr;
        }

        T* operator->()
        {
            return _ptr;
        }

    private:
        T* _ptr;
        int* _pcount;
};


void Test()
{
    SharedPtr<int> sp(new int(10));
    SharedPtr<int> sp1(sp);

    cout<<*sp<<" "<<*sp1<<endl;

    SharedPtr<int> sp2(new int(20));
    sp = sp1;
    cout<<*sp<<" "<<*sp1<<" "<<*sp2<<endl;
    sp = sp2;
    cout<<*sp<<" "<<*sp1<<" "<<*sp2<<endl;
}

//int main()
//{
//    Test();
//    return 0;
//}
