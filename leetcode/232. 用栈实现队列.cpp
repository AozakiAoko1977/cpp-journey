#include <iostream>
#include <stack>
using namespace std;

class MyQueue {
private:
    stack<int> in;   // 输入栈，push 都进这里
    stack<int> out;  // 输出栈，pop/peek 从这里取

public:
    MyQueue() {

    }

    // 入队：直接压入输入栈 in
    void push(int x) {
        in.push(x);
    }

    // 出队：当 out 为空时把 in 全部倒进 out，再取 out 栈顶
    int pop() {
        // out 空了才把 in 全部倒过来
        if (out.empty()) {
            while (!in.empty()) {
                out.push(in.top());
                in.pop();
            }
        }
        int x = out.top();
        out.pop();
        return x;
    }

    // 取队首：与 pop 同样先保证 out 非空，返回 out 栈顶
    int peek() {
        if (out.empty()) {
            while (!in.empty()) {
                out.push(in.top());
                in.pop();
            }
        }
        return out.top();
    }

    // 队列空判断：两个栈都空才是空
    bool empty() {
        return in.empty() && out.empty();  // 两个栈都空才是空
    }
};

int main() {
    MyQueue q;
    q.push(1);
    q.push(2);
    cout << "peek: " << q.peek() << endl;   // 预期 1
    cout << "pop: " << q.pop() << endl;     // 预期 1
    q.push(3);
    cout << "pop: " << q.pop() << endl;     // 预期 2
    cout << "pop: " << q.pop() << endl;     // 预期 3
    cout << "empty: " << (q.empty() ? "空" : "非空") << endl;  // 预期 空
    return 0;
}
