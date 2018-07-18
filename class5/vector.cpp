//可看作是数组/顺序表
#include <iostream>
#include <string.h>
#include <assert.h>
using namespace std;

#define DEFAULT_CAPACITY 3

typedef int DataType;

class Vector
{
    public:
        Vector()//构造函数
        {
            cout<<"Vector()"<<endl;
            _size = 0;
            _capacity = DEFAULT_CAPACITY;
            _a = new DataType[_capacity];
        }
        //Vector(int size, DataType data)//有参构造
        //{
        //    _size = size;
        //    _capacity = size + 20;
        //    _a = new DataType[_capacity];
        //    int i = 0;
        //    for(; i<_size; i++)
        //        _a[i] = data;
        //}

        Vector(const Vector& v)//拷贝构造函数
        {
            cout<<"Vector(const Vector& v)"<<endl;
            _size = v._size;
            _capacity = v._capacity;
            _a = new DataType[_capacity];
            memcpy(_a, v._a, _size*sizeof(DataType));
        }

        Vector& operator=(const Vector& v)//赋值重载
        {
            cout<<"Vector& operator=(const Vector& v)"<<endl;
            if(this != &v)
            {
                delete[] _a;
                _a = new DataType[v._capacity];
                memcpy(_a, v._a, v._size*sizeof(DataType));
                _size = v._size;
                _capacity = v._capacity;
            }
            return *this;
        }

        ~Vector()
        {
            cout<<"~Vector()"<<endl;
            if(_a != NULL)
                delete[] _a;
        }

        size_t Size()
        {
            cout<<"Size()"<<endl;
            return _size;
        }

        size_t Capacity()
        {
            cout<<"Capacity()"<<endl;
            return _capacity;
        }

        void Expand(size_t n)
        {
            cout<<"Expand()"<<endl;
            if(n > _capacity)
            {
                DataType* tmp = new DataType[n];
                memcpy(tmp, _a, _size*sizeof(DataType));
                delete[] _a;
                _a = tmp;
                _capacity = n;
            }
        }

        void PushBack(DataType x)
        {
            cout<<"PushBack()"<<endl;
            if(_size == _capacity)
                Expand(_capacity*2);
            _a[_size++] = x;
        }

        void Reserve(size_t n)
        {
            cout<<"Reserve()"<<endl;
            Expand(n);
        }

        void PopBack()
        {
            cout<<"PopBack()"<<endl;
            if(_a != NULL)
                _a[_size--];
        }

        void Insert(size_t pos, DataType x)
        {
            cout<<"Insert()"<<endl;
            assert(pos>=0 && pos<_size);
            if(_size == _capacity)
                Expand(_capacity*2);
            //int move = _size-pos;
            //int end = _size;
            //while(move--)
            //{
            //    _a[end] = _a[end-1];
            //    end--;
            //}
            int end = _size;
            while(end > pos)//这里注意不要写成>=号了
            {
                _a[end] = _a[end-1];
                end--;
            }
            _a[pos] = x;
            _size++;
        }

        void Erase(size_t pos)
        {
            assert(pos>=0 && pos<_size);
            int i = pos;
            for(; i<_size-1; i++)
            {
                _a[i] = _a[i+1];
            }
            --_size;
        }

        size_t Find(DataType x)
        {
            int i = 0;
            for(; i<_size; i++)
            {
                if(_a[i] == x)
                    return i;
            }
            return -1;
        }

        void Print()
        {
            cout<<"Print()"<<endl;
            int i = 0;
            for(; i<_size; i++)
                cout<<_a[i]<<" ";
            cout<<endl;
        }

    private:
        DataType* _a;
        size_t _size;
        size_t _capacity;
};

void Test()
{
    Vector v1;
    v1.PushBack(5);
    v1.PushBack(2);
    v1.PushBack(1);
    v1.PushBack(4);
    v1.Print();
    cout<<endl;

    Vector v2;
    v2 = v1;
    v2.Print();
    v2.PopBack();
    v2.Print();
    cout<<endl;
    
    Vector v3(v2);
    v3.Print();
}

void Test1()
{
    Vector v1;
    v1.PushBack(1);
    v1.PushBack(2);
    v1.PushBack(3);
    v1.Insert(0, 4);
    v1.Insert(2, 5);
    v1.Insert(4, 6);
    v1.Print();
    cout<<endl;

    v1.Erase(0);
    v1.Print();
    v1.Erase(4);
    v1.Print();
    v1.Erase(2);
    v1.Print();
    cout<<endl;
}

void Test2()
{
    Vector v1;
    v1.PushBack(1);
    v1.PushBack(2);
    v1.PushBack(3);
    v1.Insert(0, 4);
    v1.Insert(2, 5);
    v1.Insert(4, 6);
    v1.Print();

    size_t ret = v1.Find(1);
    cout<<ret<<endl;
    size_t ret1 = v1.Find(4);
    cout<<ret1<<endl; 
    size_t ret2 = v1.Find(3);
    cout<<ret2<<endl; 
    size_t ret3 = v1.Find(0);
    cout<<ret3<<endl;
}

int main()
{
    //Test();
    //Test1();
    Test2();
    return 0;
}
