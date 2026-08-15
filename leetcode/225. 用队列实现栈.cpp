#include <iostream>
#include <queue>
using namespace std;

class MyStack {
private:
    queue<int> q1;  // 主队列，队头永远是栈顶
    queue<int> q2;  // 辅助队列，push 时临时使用

public:
    MyStack() {

    }

    void push(int x) {
        q2.push(x);                        // 1. 新元素放进 q2
        while (!q1.empty()) {              // 2. 把 q1 里的都搬到 q2
            q2.push(q1.front());
            q1.pop();
        }
        swap(q1, q2);                      // 3. 交换，q2 变空备用
    }

    int pop() {
        int x = q1.front();                // 队头 = 栈顶
        q1.pop();
        return x;
    }

    int top() {
        return q1.front();                 // 直接看队头
    }

    bool empty() {
        return q1.empty();
    }
};

int main() {
    MyStack s;
    s.push(1);
    s.push(2);
    cout << "top: " << s.top() << endl;     // 预期 2
    cout << "pop: " << s.pop() << endl;     // 预期 2
    cout << "empty: " << (s.empty() ? "空" : "非空") << endl;  // 预期 非空
    s.push(3);
    cout << "pop: " << s.pop() << endl;     // 预期 3
    cout << "pop: " << s.pop() << endl;     // 预期 1
    cout << "empty: " << (s.empty() ? "空" : "非空") << endl;  // 预期 空
    return 0;
}
