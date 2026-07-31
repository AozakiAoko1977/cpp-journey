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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode dummy(0);                // 哨兵节点，避免处理头节点的边界问题
        ListNode* cur = &dummy;           // cur 指向已合并部分的末尾
        // 两个链表都还有节点时，比较大小，接上较小的那个
        while (list1 != nullptr && list2 != nullptr) {
            if (list1->val < list2->val) {
                cur->next = list1;        // 接上 list1 的当前节点
                list1 = list1->next;      // list1 前进
            } else {
                cur->next = list2;        // 接上 list2 的当前节点
                list2 = list2->next;      // list2 前进
            }
            cur = cur->next;              // cur 前进
        }
        // 其中一个走完了，接上另一个剩余的节点
        cur->next = (list1 != nullptr) ? list1 : list2;
        return dummy.next;                // dummy 的下一个才是真正的头节点
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
    ListNode* list1 = new ListNode(1);
    list1->next = new ListNode(3);
    list1->next->next = new ListNode(5);

    ListNode* list2 = new ListNode(2);
    list2->next = new ListNode(4);
    list2->next->next = new ListNode(6);

    cout << "list1: "; printList(list1);
    cout << "list2: "; printList(list2);

    Solution s;
    ListNode* merged = s.mergeTwoLists(list1, list2);
    cout << "合并:  "; printList(merged);
    return 0;
}