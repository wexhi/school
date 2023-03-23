#include <iostream>

using namespace std;

// 定义单链表节点
struct ListNode {
    int val; // 节点的值
    ListNode* next; // 指向下一个节点的指针

    ListNode(int x) : val(x), next(NULL) {}
};

int main() {
    // 创建一个单链表 1 -> 2 -> 3 -> 4 -> 5
    ListNode* head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);
    head->next->next->next = new ListNode(4);
    head->next->next->next->next = new ListNode(5);

    // 遍历单链表并打印每个节点的值
    ListNode* cur = head;
    while (cur != NULL) {
        cout << cur->val << " ";
        cur = cur->next;
    }
    cout << endl;

    // 释放单链表的内存
    cur = head;
    while (cur != NULL) {
        ListNode* temp = cur;
        cur = cur->next;
        delete temp;
    }

    return 0;
}
