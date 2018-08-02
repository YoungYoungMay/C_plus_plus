//将字符串中以空格分隔的每个单词逆置
#include <iostream>
#include <algorithm>
using namespace std;

string ReverseStr(const string& s)
{
    string ret = s;
    string::iterator start = ret.begin();
    do
    {
        string::iterator finish = find(start, ret.end(), ' ');
        reverse(start, finish);

        if(finish != ret.end())
            start = finish + 1;
        else
            break;
    }while(1);
    return ret;
}

int main()
{
    cout<<ReverseStr("hello world vector")<<endl;
    return 0;
}
