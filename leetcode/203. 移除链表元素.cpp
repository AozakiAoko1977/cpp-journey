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
    ListNode* removeElements(ListNode* head, int val) {
        ListNode dummy(0,head);
        ListNode* cur =&dummy;
        while( cur->next != nullptr ){
            if( cur->next->val == val ){
                cur->next = cur->next->next;
            }
            else{
                cur = cur->next;
            }
            
        }
        return dummy.next;
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
    Solution s;

    // 测试1: 1 -> 2 -> 6 -> 3 -> 4 -> 5 -> 6, val = 6
    // 预期：1 -> 2 -> 3 -> 4 -> 5
    ListNode* head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(6);
    head->next->next->next = new ListNode(3);
    head->next->next->next->next = new ListNode(4);
    head->next->next->next->next->next = new ListNode(5);
    head->next->next->next->next->next->next = new ListNode(6);

    cout << "原链表: ";
    printList(head);
    ListNode* result = s.removeElements(head, 6);
    cout << "删6后: ";
    printList(result);

    // 测试2: 头节点被删, 7 -> 7 -> 7 -> 1, val = 7
    // 预期：1
    ListNode* h2 = new ListNode(7);
    h2->next = new ListNode(7);
    h2->next->next = new ListNode(7);
    h2->next->next->next = new ListNode(1);

    cout << "原链表: ";
    printList(h2);
    cout << "删7后: ";
    printList(s.removeElements(h2, 7));

    return 0;
}
