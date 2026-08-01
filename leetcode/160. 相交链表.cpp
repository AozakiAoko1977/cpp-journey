#include <iostream>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};

class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode* pa = headA;
        ListNode* pb = headB;
        while(pa != pb){
            pa = (pa != nullptr ) ? pa->next : headB;
            pb = (pb != nullptr ) ? pb->next : headA;
        }
        return pa;
    }
};

int main() {
    // 构建相交部分: 8 -> 4 -> null
    ListNode* c1 = new ListNode(8);
    c1->next = new ListNode(4);

    // A: 4 -> 1 -> 8 -> 4 -> null
    ListNode* headA = new ListNode(4);
    headA->next = new ListNode(1);
    headA->next->next = c1;

    // B: 5 -> 6 -> 1 -> 8 -> 4 -> null
    ListNode* headB = new ListNode(5);
    headB->next = new ListNode(6);
    headB->next->next = new ListNode(1);
    headB->next->next->next = c1;

    Solution s;
    ListNode* result = s.getIntersectionNode(headA, headB);
    cout << "相交于: " << result->val << endl;

    // 不相交测试
    ListNode* a = new ListNode(1);
    ListNode* b = new ListNode(2);
    cout << "不相交: " << (s.getIntersectionNode(a, b) ? "有交点" : "无交点") << endl;

    return 0;
}