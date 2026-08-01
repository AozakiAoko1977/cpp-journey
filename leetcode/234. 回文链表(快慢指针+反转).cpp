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
    bool isPalindrome(ListNode* head) {
        ListNode* fast = head;
        ListNode* slow = head;
        while (fast != nullptr && fast->next != nullptr) {
            slow = slow->next;
            fast = fast->next->next;
        }
        // 反转后半段
        ListNode* prev = nullptr;
        while (slow != nullptr) {
            ListNode* next = slow->next;
            slow->next = prev;
            prev = slow;
            slow = next;
        }
        // 比较前后两段
        ListNode* p1 = head;
        ListNode* p2 = prev;
        while (p2 != nullptr) {
            if (p1->val != p2->val) {
                return false;
            }
            p1 = p1->next;
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
