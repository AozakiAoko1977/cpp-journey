#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
    Node(int x) : data(x), next(nullptr) {}
};

void insert_head(Node*& head, int data) {
    Node*  newhead = new Node (data);
    newhead -> next = head;
    head = newhead;
}

void insert_tail(Node*& head, int data) {
    if(head == nullptr){
        Node*  newhead = new Node (data);
        newhead -> next = head;
        head = newhead;
    }
    else{
        Node* cur = head;
        while(cur -> next != nullptr){
           cur = cur -> next;
        }
        Node * tail = new Node (data);
        cur-> next = tail;
    }
     
};

void delete_node(Node*& head, int data) {
    if(head == nullptr) return;
    while(head != nullptr && head -> data == data){
        head = head -> next;
        if(head == nullptr) return;
    }
    Node* prev = head;
    Node* cur = head -> next;
    while(cur != nullptr){
        if(cur -> data == data){
            prev -> next = cur -> next;
            cur = cur -> next;
        }
        else{
            prev = cur;
            cur = cur -> next;
        }
    }
}

bool find(Node* head, int data) {
    Node* cur = head;
    while(cur != nullptr){
        if(cur -> data == data){
            return true;
        }
        cur = cur -> next;
    }
    return false;
}

void reverse(Node*& head) {
    Node* prev = nullptr;
    Node* cur = head;
    while(cur != nullptr){
        Node* next =  cur -> next;
        cur -> next  = prev;
        prev = cur;
        cur = next;
    }
    head = prev;

}

void print_list(Node* head) {
    while (head != nullptr) {
        cout << head->data;
        head = head->next;
        if (head != nullptr) cout << " -> ";
    }
    cout << endl;
}

int main() {
    Node* head = nullptr;

    // 1. 尾插
    insert_tail(head, 1);
    insert_tail(head, 2);
    insert_tail(head, 3);
    cout << "尾插 1,2,3: ";
    print_list(head);                       // 预期 1 -> 2 -> 3

    // 2. 头插
    insert_head(head, 0);
    cout << "头插 0:    ";
    print_list(head);                       // 预期 0 -> 1 -> 2 -> 3

    // 3. 空链表尾插
    Node* emptyList = nullptr;
    insert_tail(emptyList, 9);
    cout << "空链表尾插9: ";
    print_list(emptyList);                  // 预期 9

    // 4. find
    cout << "找 2: " << (find(head, 2) ? "找到" : "没找到") << endl;   // 预期 找到
    cout << "找 7: " << (find(head, 7) ? "找到" : "没找到") << endl;   // 预期 没找到

    // 5. 删中间
    delete_node(head, 2);
    cout << "删 2(中间): ";
    print_list(head);                       // 预期 0 -> 1 -> 3

    // 6. 删头
    delete_node(head, 0);
    cout << "删 0(头):   ";
    print_list(head);                       // 预期 1 -> 3

    // 7. 删尾
    delete_node(head, 3);
    cout << "删 3(尾):   ";
    print_list(head);                       // 预期 1

    // 8. 全删光
    delete_node(head, 1);
    cout << "删 1(全删光): ";
    print_list(head);                       // 预期 空行
    delete_node(head, 5);
    cout << "空链表再删: ";
    print_list(head);                       // 预期 空行（不崩）

    // 9. reverse
    Node* r = nullptr;
    insert_tail(r, 1);
    insert_tail(r, 2);
    insert_tail(r, 3);
    insert_tail(r, 4);
    reverse(r);
    cout << "反转 1,2,3,4: ";
    print_list(r);                          // 预期 4 -> 3 -> 2 -> 1

    // 10. 连续删除多个相同的
    Node* d = nullptr;
    insert_tail(d, 3);
    insert_tail(d, 3);
    insert_tail(d, 5);
    insert_tail(d, 3);
    delete_node(d, 3);
    cout << "删连续3:   ";
    print_list(d);                          // 预期 5

    return 0;
}
