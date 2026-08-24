#include <iostream>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};

class Solution {
public:
    // 快慢指针：fast 每次走两步，slow 每次走一步；有环时两指针一定会在环内相遇
    bool hasCycle(ListNode *head) {
        ListNode* fast = head;                              // 快指针
        ListNode* slow = head;                              // 慢指针
        while (fast != nullptr && fast->next != nullptr) {  // fast 还能继续走（没到链表末尾）
            slow = slow->next;                              // 慢指针走一步
            fast = fast->next->next;                        // 快指针走两步
            if (slow == fast) {
                return true;   // 相遇了，有环
            }
        }
        return false;          // fast 走到空，没环
    }
};

int main() {
    Solution s;

    // 无环：1 -> 2 -> 3 -> null
    ListNode* n1 = new ListNode(1);
    n1->next = new ListNode(2);
    n1->next->next = new ListNode(3);
    cout << "无环链表: " << (s.hasCycle(n1) ? "有环" : "没环") << endl;

    // 有环：1 -> 2 -> 3 -> 4，4 指回 2
    ListNode* c1 = new ListNode(1);
    ListNode* c2 = new ListNode(2);
    ListNode* c3 = new ListNode(3);
    ListNode* c4 = new ListNode(4);
    c1->next = c2;
    c2->next = c3;
    c3->next = c4;
    c4->next = c2;  // 成环
    cout << "有环链表: " << (s.hasCycle(c1) ? "有环" : "没环") << endl;

    return 0;
}