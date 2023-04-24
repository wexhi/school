#include <iostream>
#include <cstring>
using namespace std;

int main() {
    char s[101];  // 定义字符串
    cin >> s;  // 输入字符串

    int count[26] = { 0 };  // 初始化一个长度为26的数组，用于存储每个字母出现的次数

    int len = strlen(s);
    for (int i = 0; i < len; i++) {
        if (isalpha(s[i])) {
            s[i] = toupper(s[i]);  // 转换为大写字母
            count[s[i] - 'A']++;  // 更新对应字母的出现次数
        }
    }

    int max_count = 0;  // 记录出现次数最多的字母的出现次数
    char max_char;  // 记录出现次数最多的字母

    for (int i = 0; i < 26; i++) {
        if (count[i] > max_count) {
            max_count = count[i];
            max_char = i + 'A';
        }
    }

    cout << max_char << endl;  // 输出结果

    return 0;
}
