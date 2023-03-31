#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main()
{
    ifstream infile("text1.dat"); // 打开输入文件
    ofstream outfile("text2.dat"); // 打开输出文件
    string line; // 存储每行字符串

    while (getline(infile, line)) // 逐行读取输入文件
    {
        if (line.length() == 0) // 如果当前行为空行，直接输出
        {
            outfile << endl;
            continue;
        }
        string reversed_line; // 存储颠倒顺序后的字符串
        for (int i = line.length() - 1; i >= 0; i--) // 颠倒顺序
        {
            reversed_line += line[i];
        }
        outfile << reversed_line << endl; // 输出到输出文件
    }

    infile.close(); // 关闭输入文件
    outfile.close(); // 关闭输出文件

    return 0;
}

