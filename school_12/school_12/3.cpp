#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main()
{
    ifstream infile("text1.dat"); // �������ļ�
    ofstream outfile("text2.dat"); // ������ļ�
    string line; // �洢ÿ���ַ���

    while (getline(infile, line)) // ���ж�ȡ�����ļ�
    {
        if (line.length() == 0) // �����ǰ��Ϊ���У�ֱ�����
        {
            outfile << endl;
            continue;
        }
        string reversed_line; // �洢�ߵ�˳�����ַ���
        for (int i = line.length() - 1; i >= 0; i--) // �ߵ�˳��
        {
            reversed_line += line[i];
        }
        outfile << reversed_line << endl; // ���������ļ�
    }

    infile.close(); // �ر������ļ�
    outfile.close(); // �ر�����ļ�

    return 0;
}

