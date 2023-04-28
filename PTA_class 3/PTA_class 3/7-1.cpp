#include <iostream>
#include <stack>
#include <sstream>
#include <iomanip>

using namespace std;

// �ж��ַ��Ƿ�Ϊ�����
bool isOperator(char ch) {
    return (ch == '+' || ch == '-' || ch == '*' || ch == '/');
}

// �ж���������ȼ�
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

// ��������������������
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

// ���ַ���ת��Ϊ����
double toInt(string str) {
    stringstream ss;
    ss << str;
    double num;
    ss >> num;
    return num;
}

// ������ʽ��ֵ
double evaluateExpression(string expr) {
    stack<double> operandStack; // ������ջ
    stack<char> operatorStack; // �����ջ

    for (int i = 0; i < expr.length(); i++) {
        char ch = expr[i];
        if (ch == ' ') { // ���Կո�
            continue;
        }
        else if (ch == '(') { // ������ֱ����ջ
            operatorStack.push(ch);
        }
        else if (ch == ')') { // �����Ž��м��㣬ֱ�������ų���
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
            operatorStack.pop(); // �����ų�ջ
        }
        else if (isOperator(ch)) { // ������Ĵ���
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
        else { // ���ֵĴ���
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

    while (!operatorStack.empty()) { // �������ļ���
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
