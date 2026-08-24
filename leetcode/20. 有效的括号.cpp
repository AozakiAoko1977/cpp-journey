#include <iostream>
#include <stack>
#include <string>
using namespace std;

class Solution {
public:
    // 核心思路：用栈匹配括号，左括号入栈，右括号与栈顶配对，配对失败或最后栈非空都无效
    bool isValid(string s) {
        stack<char> st;
        for (char c : s) {
            if (c == '(' || c == '[' || c == '{') {
                st.push(c);                          // 左括号，压入
            } else {
                if (st.empty()) return false;        // 没有可以匹配的左括号
                char top = st.top();
                if ((c == ')' && top != '(') ||
                    (c == ']' && top != '[') ||
                    (c == '}' && top != '{')) {
                    return false;                    // 不匹配
                }
                st.pop();                            // 匹配，弹出
            }
        }
        return st.empty();                           // 全匹配完了 → true
    }
};

int main() {
    Solution s;
    cout << "()       → " << (s.isValid("()") ? "有效" : "无效") << endl;
    cout << "()[]{}   → " << (s.isValid("()[]{}") ? "有效" : "无效") << endl;
    cout << "(]       → " << (s.isValid("(]") ? "有效" : "无效") << endl;
    cout << "([])     → " << (s.isValid("([])") ? "有效" : "无效") << endl;
    cout << "([)]     → " << (s.isValid("([)]") ? "有效" : "无效") << endl;
    return 0;
}
