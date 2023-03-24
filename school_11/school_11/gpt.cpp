#include <iostream>

using namespace std;

// ���嵥����ڵ�
struct ListNode {
    int val; // �ڵ��ֵ
    ListNode* next; // ָ����һ���ڵ��ָ��

    ListNode(int x) : val(x), next(NULL) {}
};

int main() {
    // ����һ�������� 1 -> 2 -> 3 -> 4 -> 5
    ListNode* head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);
    head->next->next->next = new ListNode(4);
    head->next->next->next->next = new ListNode(5);

    // ������������ӡÿ���ڵ��ֵ
    ListNode* cur = head;
    while (cur != NULL) {
        cout << cur->val << " ";
        cur = cur->next;
    }
    cout << endl;

    // �ͷŵ�������ڴ�
    cur = head;
    while (cur != NULL) {
        ListNode* temp = cur;
        cur = cur->next;
        delete temp;
    }

    return 0;
}
