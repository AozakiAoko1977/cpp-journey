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
    // 思路：快慢指针找中点，反转后半段，再让前后两段逐个比较是否相等
    bool isPalindrome(ListNode* head) {
        ListNode* fast = head;                            // 快指针
        ListNode* slow = head;                            // 慢指针
        while (fast != nullptr && fast->next != nullptr) {
            slow = slow->next;                            // 慢指针走一步
            fast = fast->next->next;                      // 快指针走两步
        }
        // 循环结束时 slow 停在后半段的开头，下面反转后半段
        ListNode* prev = nullptr;                         // prev 记录反转后的新头
        while (slow != nullptr) {                         // 逐个反转 slow 开头的链表
            ListNode* next = slow->next;                  // 暂存下一个节点
            slow->next = prev;                            // 反转指向
            prev = slow;                                  // prev 前进
            slow = next;                                  // slow 前进
        }
        // 比较前后两段
        ListNode* p1 = head;                              // p1 从前半段头出发
        ListNode* p2 = prev;                              // p2 从反转后的后半段头出发
        while (p2 != nullptr) {                           // 后半段走完就结束
            if (p1->val != p2->val) {
                return false;                             // 有一对不相等就不是回文
            }
            p1 = p1->next;                                // 两指针同步前进
            p2 = p2->next;
        }
        return true;
    }
};

int main() {
    Solution s;

    // 偶数回文: 1 -> 2 -> 2 -> 1
    ListNode* n1 = new ListNode(1);
    n1->next = new ListNode(2);
    n1->next->next = new ListNode(2);
    n1->next->next->next = new ListNode(1);
    cout << "1->2->2->1: " << (s.isPalindrome(n1) ? "回文" : "非回文") << endl;

    // 奇数回文: 1 -> 2 -> 3 -> 2 -> 1
    ListNode* n2 = new ListNode(1);
    n2->next = new ListNode(2);
    n2->next->next = new ListNode(3);
    n2->next->next->next = new ListNode(2);
    n2->next->next->next->next = new ListNode(1);
    cout << "1->2->3->2->1: " << (s.isPalindrome(n2) ? "回文" : "非回文") << endl;

    // 非回文: 1 -> 2 -> 3
    ListNode* n3 = new ListNode(1);
    n3->next = new ListNode(2);
    n3->next->next = new ListNode(3);
    cout << "1->2->3: " << (s.isPalindrome(n3) ? "回文" : "非回文") << endl;

    return 0;
}
