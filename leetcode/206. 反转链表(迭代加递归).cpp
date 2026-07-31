#include <iostream>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    // 迭代版本
    ListNode* reverseList(ListNode* head) {
        ListNode* prev = nullptr;
        ListNode* curr = head;
        while (curr != nullptr) {
            ListNode* next = curr->next;  // 暂存下一个
            curr->next = prev;            // 反转指向
            prev = curr;                  // prev 前进
            curr = next;                  // curr 前进
        }
        return prev;  // prev 是新头，curr 已经是 nullptr 了
    }

    // 递归版本
    ListNode* reverseListRecursive(ListNode* head) {
        if (head == nullptr || head->next == nullptr) {
            return head;  // 空链表或只有一个节点，直接返回
        }
        ListNode* newHead = reverseListRecursive(head->next);  // 反转后面的
        head->next->next = head;  // 让下一个节点指向自己
        head->next = nullptr;     // 自己指向空
        return newHead;
    }
};

void printList(ListNode* head) {
    while (head != nullptr) {
        cout << head->val;
        head = head->next;
        if (head != nullptr) cout << " -> ";
    }
    cout << endl;
}

int main() {
    ListNode* head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);
    head->next->next->next = new ListNode(4);
    head->next->next->next->next = new ListNode(5);

    cout << "原链表:  ";
    printList(head);

    Solution s;
    ListNode* reversed = s.reverseList(head);
    cout << "迭代反转:";
    printList(reversed);

    ListNode* back = s.reverseListRecursive(reversed);
    cout << "递归反转回:";
    printList(back);

    return 0;
}