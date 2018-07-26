//模板实现栈

#pragma once
#include <iostream>
#include "vector.cc"
#include "list.cc"
using namespace std;

template<class T, class Container>//实现容器适配器
class Stack
{
    public:
        void Push(const T& x)
        {
            _con.PushBack(x);
        }

        void Pop()
        {
            _con.PopBack();
        }

        size_t Size()
        {
            return _con.Size();
        }

        bool Empty()
        {
            return _con.Empty();
        }

        T& Top()
        {
            return _con.Back();
        }

        void Print()
        {
            _con.Print();
        }
    protected:
        Container _con;
};

void TestStack()
{
    Stack<int, Vector<int> > s1;
    Stack<int, List<int> > s2;
    s1.Push(1);
    s1.Push(2);
    s1.Push(3);
    s1.Print();

    while(!s1.Empty())
    {
        cout<<s1.Top()<<" ";
        s1.Pop();
    }
    cout<<endl;
    s1.Print();
    
    s2.Push(6);
    s2.Push(5);
    s2.Push(4);
    s2.Print();

    while(!s2.Empty())
    {
        cout<<s2.Top()<<" ";//??????????????有问题
        s2.Pop();
    }
    cout<<endl;
    s2.Print();
}

int main()
{
    TestStack();
    return 0;
}
