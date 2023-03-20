#include <iostream>
#include <vector>
using namespace std;

int main() {
    int k;
    cin >> k;

    // ��ʼ��ѧ������б�
    vector<char> students = { 'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z' };

    // ��ʼ����������Ϸ����
    int count = 1;
    int rounds = 1;

    // ��ʼ����Ȧѧ���б�
    vector<char> out_students;

    // ��ʼ��Ϸ
    while (!students.empty()) {
        // ��ǰ����ѧ��������
        int current_index = (count - 1) % students.size();

        // ��ǰ������ѧ��
        char current_student = students[current_index];

        // �ж��ܷ�k��������������Ȧ
        if (count % k == 0) {
            out_students.push_back(current_student);
            students.erase(students.begin() + current_index);
            count = 1;
        }
        else {
            count += 1;
        }

        // ����Ѿ�����һȦ����������Ϸ����
        if (current_index == students.size() - 1) {
            rounds += 1;
        }
    }

    // �����Ȧѧ���ı��
    for (auto student : out_students) {
        cout << student;
    }
    cout << endl;

    return 0;
}
