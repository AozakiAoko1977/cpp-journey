#include <iostream>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};

class Solution {
public:
    // 双指针交叉走：pa 走完 A 就换到 B 的头，pb 走完 B 就换到 A 的头；
    // 若相交，两指针会同时走到交点；若不相交，会同时走到 nullptr
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode* pa = headA;                          // pa 从 A 的头出发
        ListNode* pb = headB;                          // pb 从 B 的头出发
        while(pa != pb){                               // 两指针相遇（交点或 nullptr）时结束
            pa = (pa != nullptr ) ? pa->next : headB;  // A 走完了就换到 B 的头
            pb = (pb != nullptr ) ? pb->next : headA;  // B 走完了就换到 A 的头
        }
        return pa;                                     // 交点；不相交时两指针都为 nullptr
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