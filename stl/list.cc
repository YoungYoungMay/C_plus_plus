//STL中的list容器的相关操作
#pragma once
#include <iostream>
#include <list>
#include <algorithm>
#include "common.h"
using namespace std;

void test_list1()
{
    list<int> l;
    l.push_back(1);
    l.push_back(2);
    l.push_back(3);
    l.push_back(4);
    
    ////正向迭代器-》正向打印
    //list<int>::iterator it = l.begin();
    //while(it != l.end())
    //{
    //    cout<<*it<<" ";
    //    ++it;
    //}
    //cout<<endl;
    
    PrintContainer(l);
    
    ////反向迭代器-》反向打印
    //list<int>::reverse_iterator rit = l.rbegin();
    //while(rit != l.rend())
    //{
    //    cout<<*rit<<" ";
    //    ++rit;
    //}
    //cout<<endl;

    list<int>::iterator pos = find(l.begin(), l.end(),3);
    if(pos != l.end())
    {
        l.insert(pos, 30);
    }
    PrintContainer(l);
    l.erase(pos);
    PrintContainer(l);

    l.resize(2);
    PrintContainer(l);
    l.resize(10);
    PrintContainer(l);
}

template<class T>
struct Less
{
    bool operator()(const T& l, const T& r)
    {
        return l<r;
    }
};

template<class T>
struct Greater
{
    bool operator()(const T& l, const T& r)
    {
        return l>r;
    }
};

void test_list2()
{
    list<int> l;
    l.push_back(4);
    l.push_back(2);
    l.push_back(3);
    l.push_back(4);
    l.push_back(1);
    l.push_back(9);
    l.push_back(8);
    PrintContainer(l);
    //排序会改变容器里元素的顺序，不只是打印处来的顺序改变了
    //升序排列
    l.sort(less<int>());
    PrintContainer(l);
    //降序排序
    l.sort(greater<int>());
    PrintContainer(l);
    //逆置
    l.reverse();
    PrintContainer(l);

    //判断两个数的大小
    Less<int> les;
    //下面两句等价
    cout<<les(1,3)<<endl;
    cout<<les.operator()(1,3)<<endl;
}

void test_list3()
{
    list<int> l;
    l.push_back(4);
    l.push_back(2);
    l.push_back(3);
    l.push_back(1);
    l.push_back(9);
    l.push_back(1);
    PrintContainer(l);

    //STL中的默认排序算法为升序
    l.sort();
    PrintContainer(l);
    //删除重复元素
    l.unique();
    PrintContainer(l);
}

void test_list4()
{
    //迭代器失效-》类似野指针
    list<int> l;
    l.push_back(1);
    l.push_back(2);
    l.push_back(3);
    l.push_back(4);
    PrintContainer(l);

    list<int>::iterator it = l.begin();
    while(it != l.end())
    {
        if(*it % 2 == 0)
        //STL中的erase函数会返回下一个元素的迭代器
            l.erase(it++);
            //it = l.erase(it);
        else
            ++it;
    }
    PrintContainer(l);
}

int main()
{
    //test_list1();
    //test_list2();
    //test_list3();
    test_list4();
    return 0;
}
