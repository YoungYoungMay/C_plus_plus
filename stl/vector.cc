//STL中vector容器的相关操作
#pragma once
#include <iostream>
#include <string>
#include <vector>
#include "common.h"
using namespace std;

//迭代器分类
    //1.正向迭代器
    //2.反向迭代器
    //3.const_正/反

//for+operator[]作用
    //1.遍历
    //2.修改

void Print_Vector(const vector<int>& v)//打印函数
{
    //对于vector最常用
    size_t i = 0;
    for(; i<v.size(); ++i)
    {
        cout<<v[i]<<" ";
    }
    cout<<endl;

    ////偶尔会用-》利用迭代器遍历元素并打印??????????
    //vector<int>::iterator it1 = v.begin();//定义一个迭代器
    //while(it1 != v.end())
    //{
    //    cout<<*it1<<" ";
    //    ++it1;
    //}
    //cout<<endl;

    vector<int>::const_iterator it = v.begin();//定义一个const迭代器
    while(it != v.end())//正向打印
    {
        cout<<*it<<" ";
        ++it;
    }
    cout<<endl;

    int j = v.size()-1;
    for(; j>=0; --j)//反向打印
    {
        cout<<v[j]<<" ";
    }
    cout<<endl;

    vector<int>::const_reverse_iterator rit = v.rbegin();//反向迭代器-》反向打印
    while(rit != v.rend())
    {
        cout<<*rit<<" ";
        ++rit;
    }
    cout<<endl;
}

void test_vector1()
{
    vector<int> v1;
    v1.push_back(1);
    v1.push_back(2);
    v1.push_back(3);
    v1.push_back(4);
    Print_Vector(v1);
    cout<<endl;

    //T& operator[](size_t pos)
    //{
    //    return _first[pos];
    //}
    size_t i = 0;
    for(; i<v1.size(); ++i)
    {
        if(v1[i]%2 == 0)
            v1[i] *= 2;
    }

    vector<int>::iterator it1 = v1.begin();
    while(it1 != v1.end())
    {
       if(*it1%2 != 0)
           *it1 *= 2;
       ++it1;
    }
    Print_Vector(v1);
    cout<<endl;

    //向v2中插入10个100
    vector<int> v2(10, 100);//reserve+for(n)+push_back
    Print_Vector(v2);
}

//面试题：vector如何增容？一定增2倍？
    //SGI 2倍 PJ 1/2倍
//拷贝数据涉及深浅拷贝及类型萃取
//vector与list的区别是什么？vector的缺点是什么
//vector的resize与reserve缓解增容
//resize与reserve的区别

void test_vector2()
{
    vector<int> v1;
    //max_size()表示容器允许的最大元素数
    cout<<v1.max_size()<<endl;
    
    //有效元素+空间大小-》可以看到空间是以2倍形式递增的
    cout<<v1.size()<<" "<<v1.capacity()<<endl;
    v1.push_back(1);
    cout<<v1.size()<<" "<<v1.capacity()<<endl;
    v1.push_back(2);
    cout<<v1.size()<<" "<<v1.capacity()<<endl;
    v1.push_back(3);
    cout<<v1.size()<<" "<<v1.capacity()<<endl;
    v1.push_back(4);
    cout<<v1.size()<<" "<<v1.capacity()<<endl;
    v1.push_back(1);
    cout<<v1.size()<<" "<<v1.capacity()<<endl;

    //assign赋值
    //会先将vector中的数据清空，再插入新元素
    v1.assign(10, 100);
    cout<<v1.size()<<" "<<v1.capacity()<<endl;
    Print_Vector(v1);

    vector<int> v2;
    v2.push_back(10);
    v2.push_back(20);
    v2.push_back(30);
    //将v2的[begin, end)拷贝给v1
    v1.assign(v2.begin(), v2.end());
    Print_Vector(v1);
    Print_Vector(v2);
    cout<<endl;
    //将[++begin, --end)赋值给v2
    v2.assign(++v1.begin(), --v1.end());
    Print_Vector(v1);
    Print_Vector(v2);

    string s("hello");
    //将"hello"转化为ASCII码赋值给了v2
    v2.assign(s.begin(), s.end());
    Print_Vector(v2);
    cout<<endl;

    vector<string> v3;
    v3.push_back("111");
    //v2.assign(v3.begin(), v3.end());

    //在容器里放容器
    vector<vector<int> >vv;
    vv.resize(10);
    size_t i = 0;
    for(; i<10; ++i)
        vv[i].resize(10);
    for(i=0; i<10; ++i)
    {
        size_t j = 0;
        for(; j<10; ++j)
            vv[i][j] = i*j;
    }
    PrintContainer(v3);
    PrintContainer(s);
    cout<<endl;

    size_t j = 0;
    for(i=0; i<10; ++i)
    {
        for(j=0; j<10; ++j)
            cout<<vv[i][j]<<" ";
    }
    cout<<endl;
}

void test_vector3()
{
    vector<int> v;
    v.push_back(1);
    v.push_back(2);
    v.push_back(6);
    v.push_back(4);
    PrintContainer(v);
    vector<int>::iterator it = v.begin();
    while(it != v.end())
    {
        if(*it %2 == 0)
        //vector的earse和insert会引起迭代器失效的问题-》逻辑错误
            it = v.erase(it);
        else
            ++it;
    }
    cout<<endl;
    PrintContainer(v);
}

int main()
{
    //test_vector1();
    //test_vector2();
    test_vector3();
    return 0;
}
