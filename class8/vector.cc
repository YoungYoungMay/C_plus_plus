//利用模板实现Vector

#include <iostream>
#include <assert.h>

using namespace std;

template<class T>
class Vector
{
    public:
        Vector()//构造函数
            :_first(NULL)
             ,_finish(NULL)
             ,_endofstorage(NULL)
        {}

        Vector(const Vector<T>& v)//拷贝构造
        {
            _first = new T[v.Size()];
            //memcpy(_first, v._first, sizeof(T)*v._Size());
            
            //类型萃取
            //1.内置类型+浅拷贝自定义类型(Date)
            //memcpy(tmp, _first, sizeof(T)*size);

            //2.深拷贝自定义类型
            size_t i = 0;
            for(; i<v.Size(); ++i)
            {
                _first[i] = v._first[i];
            }
            _finish = _first + v.Size();
            _endofstorage = _first + v.Size();
        }

        Vector<T>& operator=(Vector<T> v)//赋值重载
        {
            swap(_first, v._first);
            swap(_finish, v._finish);
            swap(_endofstorage, v._endofstorage);
            return *this;
        }

        T& Back()//返回最后一个
        {
            return *(_finish-1);
        }

        T& Front()//返回第一个
        {
            return *(_first);
        }

        ~Vector()//析构
        {
            if(_first)
                delete[] _first;
            _first = _finish = _endofstorage = NULL;
        }

        void PushBack(const T& x)
        {
            if(_finish == _endofstorage)//空间已满
            {
                size_t new_capacity = Capacity()==0?3:Capacity()*2;
                Expand(new_capacity);
            }
            *_finish = x;
            ++_finish;
        }

        void PopBack()
        {
            Erase(Size()-1);
        }

        void Insert(size_t pos, const T& x)
        {
            assert(pos <= Size());
            if(_finish == _endofstorage)
            {
                size_t new_capacity = Capacity()==0?3:Capacity()*2;
                Expand(new_capacity);
            }
            T* end = _finish - 1;
            while(end >= _first+pos)//要插入的点之后还有元素-》向后挪
            {
                *(end+1) = *end;
                --end;
            }
            _first[pos] = x;
            ++_finish;
        }

        void Erase(size_t pos)
        {
            assert(pos <= Size());
            T* start = _first+pos;
            while(start < _finish-1)
            {
                *start = *(start+1);
                ++start;
            }
            --_finish;
        }

        size_t Size() const
        {
            return _finish-_first;
        }

        size_t Capacity() const
        {
            return _endofstorage-_first;
        }

        bool Empty()
        {
            return _first==_finish;
        }

        T& operator[](size_t pos)
        {
            assert(pos < Size());
            return _first[pos];
        }

        //void Print(const T& x)
        //{
        //    size_t i = 0;
        //    size_t size = Size();
        //    for(; i<size; ++i)
        //    {
        //        cout<<x[i]<<" ";
        //    }
        //    cout<<endl;
        //}

        void Reserve(size_t size);//在确定需要的内存大小时，可一次申请
        void Resize(size_t size, const T& value=T());//改变元素个数，空间多了就销毁，少了就扩容

    protected:
        void Expand(size_t new_capacity)
        {
            if(new_capacity > Capacity())
            {
                size_t size = Size();
                T* tmp = new T[new_capacity];
                if(_first)
                {
                    //类型萃取
                    //1.内置类型+浅拷贝自定义类型(Date)
                    //memcpy(tmp, _first, sizeof(T)*size);
                    
                    //2.深拷贝自定义类型
                    size_t i = 0;
                    for(; i<size; ++i)
                    {
                        tmp[i] = _first[i];
                    }
                    delete[] _first;
                }
                _first = tmp;
                _finish = _first + size;
                _endofstorage = _first + new_capacity;
            }
        }

    protected:
        T* _first;//使用空间的头
        T* _finish;//使用空间的尾
        T* _endofstorage;//使用空间容量的尾
};

//也可以在类外定义，但是不推荐
//template<class T>
//void Vector<T>::PushBack(const T& x)
//{}

void Test()
{
    Vector<int> v1;
    v1.PushBack(1);
    v1.PushBack(2);
    v1.PushBack(3);
    v1.PushBack(4);
    //v1.Print();
    size_t i = 0;
    for(; i<v1.Size(); ++i)
    {
        cout<<v1[i]<<" ";
    }
    cout<<endl;

    Vector<string> v2;
    v2.PushBack("1111");
    v2.PushBack("2222");
    v2.PushBack("3333");
    v2.PushBack("44444444444444444444444444444444444444444444444444444");
    for(i=0; i<v2.Size(); ++i)
    {
        cout<<v2[i]<<" ";
    }
    cout<<endl;

    Vector<string> v3(v2);
    for(i=0; i<v3.Size(); ++i)
    {
        cout<<v3[i]<<" ";
    }
    cout<<endl;
}

int main()
{
    Test();
    return 0;
}
