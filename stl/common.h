#pragma once
#include <iostream>

//利用适配器打印各个类型的容器中的元素
template<class Container>
void PrintContainer(const Container& c)
{
    //迭代器就类似一个指针
    class Container::const_iterator it = c.begin();
    while(it != c.end())
    {
        std::cout<<(*it)<<" ";
        ++it;
    }
    std::cout<<std::endl;
}
