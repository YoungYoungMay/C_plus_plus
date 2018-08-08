//智能指针

//特性
    //RAII思想的一种实践
    //像指针一样使用
    //拷贝和赋值
//作用
    //保证资源的正确初始化及释放
    //定义一个类来封装资源的分配及释放
    //在类的构造函数完成资源的分配及初始化 && 在析构函数完成资源的释放


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
            cout<<_ptr<<endl;
            delete _ptr;
        }

        //operator*();
        //operator->();
    private:
        T* _ptr;
};

int main()
{
    vector<int> v;
    v.push_back(1);
    
    string s("hello");

    //v[10] = 1;
    try
    {
        //at用法与[]类似-》访问对应index内容
        v.at(10);
    }
    catch(exception& e)
    {
        cout<<e.what()<<endl;
    }

    int* p = new int;
    AutoPtr<int> ap1(new int);

    //vector<int> v;
    v.at(1);
    delete p;

    return 0;
}
