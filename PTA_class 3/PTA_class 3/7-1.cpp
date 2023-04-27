#include <iostream>
#include <stack>
#include <sstream>
#include <iomanip>

using namespace std;

// 判断字符是否为运算符
bool isOperator(char ch) {
    return (ch == '+' || ch == '-' || ch == '*' || ch == '/');
}

// 判断运算符优先级
int priority(char op) {
    if (op == '+' || op == '-') {
        return 1;
    }
    else if (op == '*' || op == '/') {
        return 2;
    }
    else {
        return 0;
    }
}

// 计算两个整数的运算结果
double calculate(double op1, double op2, char op) {
    if (op == '+') {
        return op1 + op2;
    }
    else if (op == '-') {
        return op1 - op2;
    }
    else if (op == '*') {
        return op1 * op2;
    }
    else if (op == '/') {
        return op1 / op2;
    }
    else {
        return 0;
    }
}

// 将字符串转化为整数
double toInt(string str) {
    stringstream ss;
    ss << str;
    double num;
    ss >> num;
    return num;
}

// 计算表达式的值
double evaluateExpression(string expr) {
    stack<double> operandStack; // 操作数栈
    stack<char> operatorStack; // 运算符栈

    for (int i = 0; i < expr.length(); i++) {
        char ch = expr[i];
        if (ch == ' ') { // 忽略空格
            continue;
        }
        else if (ch == '(') { // 左括号直接入栈
            operatorStack.push(ch);
        }
        else if (ch == ')') { // 右括号进行计算，直到左括号出现
            while (operatorStack.top() != '(') {
                char op = operatorStack.top();
                operatorStack.pop();
                double op2 = operandStack.top();
                operandStack.pop();
                double op1 = operandStack.top();
                operandStack.pop();
                double result = calculate(op1, op2, op);
                operandStack.push(result);
            }
            operatorStack.pop(); // 左括号出栈
        }
        else if (isOperator(ch)) { // 运算符的处理
            while (!operatorStack.empty() && isOperator(operatorStack.top()) && priority(ch) <= priority(operatorStack.top())) {
                char op = operatorStack.top();
                operatorStack.pop();
                double op2 = operandStack.top();
                operandStack.pop();
                double op1 = operandStack.top();
                operandStack.pop();
                double result = calculate(op1, op2, op);
                operandStack.push(result);
            }
            operatorStack.push(ch);
        }
        else { // 数字的处理
            int start = i;
            while (i < expr.length() && isdigit(expr[i])) {
                i++;
            }
            int end = i - 1;
            string numStr = expr.substr(start, end - start + 1);
            double num = toInt(numStr);
            operandStack.push(num);
            i--;
        }
    }

    while (!operatorStack.empty()) { // 进行最后的计算
        char op = operatorStack.top();
        operatorStack.pop();
        double op2 = operandStack.top();
        operandStack.pop();
        double op1 = operandStack.top();
        operandStack.pop();
        double result = calculate(op1, op2, op);
        operandStack.push(result);
    }

    double finalResult = operandStack.top();
    return finalResult;
}

int main() {
    string expr;
    getline(cin, expr);
    double result = evaluateExpression(expr);
    cout << fixed << setprecision(2) << result << endl;
    return 0;
}
