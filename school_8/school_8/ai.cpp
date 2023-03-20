#include <iostream>
#include <vector>
using namespace std;

int main() {
    int k;
    cin >> k;

    // 初始化学生标记列表
    vector<char> students = { 'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z' };

    // 初始化报数和游戏轮数
    int count = 1;
    int rounds = 1;

    // 初始化出圈学生列表
    vector<char> out_students;

    // 开始游戏
    while (!students.empty()) {
        // 当前报数学生的索引
        int current_index = (count - 1) % students.size();

        // 当前报数的学生
        char current_student = students[current_index];

        // 判断能否被k整除，如果能则出圈
        if (count % k == 0) {
            out_students.push_back(current_student);
            students.erase(students.begin() + current_index);
            count = 1;
        }
        else {
            count += 1;
        }

        // 如果已经遍历一圈，则增加游戏轮数
        if (current_index == students.size() - 1) {
            rounds += 1;
        }
    }

    // 输出出圈学生的标记
    for (auto student : out_students) {
        cout << student;
    }
    cout << endl;

    return 0;
}
