//IO流

#include <iostream>
#include <fstream>
using namespace std;

void WriteFile(const char* file)//写文件
{
    ofstream ofs(file, ofstream::out);//打开文件
    //写入文件
    string buf("hello\n");
    ofs.write(buf.c_str(), buf.length());//将文件清空重写
    ofs.put('w');
    ofs.put('o');
    ofs.put('r');
    ofs.put('l');
    ofs.put('d');
    ofs.close();//关闭文件
}

void ReadFile(const char* file)//读文件-》一个一个字符读
{
    //打开文件
    ifstream ifs(file, ifstream::in);
    //读文件(一个一个字符读)
    char c;
    while(ifs.get(c))
        cout<<c;

    cout<<endl;
    ifs.close();
}

void ReadFile1(const char* file)//读文件-》一行一行读
{
    //打开文件
    ifstream ifs(file, ifstream::in);
    //读文件(一行一行读)
    char buf[256];
    ifs.seekg(ifs.beg);//定位到文件开头
    ifs.getline(buf, 256);//用于读取一行字符直到换行符
    cout<<buf<<endl;
    cout<<endl; 
    ifs.getline(buf, 256);
    cout<<buf<<endl;
    ifs.close();
}

int main()
{
    //WriteFile("./write_file");
    //ReadFile("./read_file");
    ReadFile1("./read_file");
    return 0;
}
