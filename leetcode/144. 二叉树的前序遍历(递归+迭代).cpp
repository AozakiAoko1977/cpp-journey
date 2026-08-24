#include <iostream>
#include <vector>
#include <stack>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
private:
    // 辅助函数：递归遍历，把结果装进 result
    // 前序顺序：根 -> 左 -> 右
    void preorder(TreeNode* node, vector<int>& result) {
        if (node == nullptr) return;          // 空节点直接返回（递归出口）
        result.push_back(node->val);          // 先访问根节点
        preorder(node->left, result);         // 再递归左子树
        preorder(node->right, result);        // 最后递归右子树
    }

public:
    // 递归版：从根节点开始，按 根 -> 左 -> 右 的顺序遍历
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> result;                   // 存放遍历结果
        preorder(root, result);               // 从根节点开始递归
        return result;
    }

    // 迭代版（用栈模拟递归）
    // 栈是后进先出，所以先压右孩子再压左孩子，弹出顺序才是 根 -> 左 -> 右
    vector<int> preorderTraversalIterative(TreeNode* root) {
        vector<int> result;                   // 存放遍历结果
        if (root == nullptr) return result;   // 空树
        stack<TreeNode*> st;                  // 栈：模拟递归调用
        st.push(root);                        // 根节点入栈
        while (!st.empty()) {                 // 栈不空就一直处理
            TreeNode* node = st.top();        // 取出栈顶节点
            st.pop();                         // 弹出栈顶节点
            result.push_back(node->val);          // 访问
            if (node->right) {
                st.push(node->right);             // 先压右
            }
            if (node->left) {
                st.push(node->left);              // 再压左
            }
        }
        return result;                            // 循环结束后返回
    }
};

int main() {
    // 构建树:
    //     1
    //      \
    //       2
    //      /
    //     3
    // 前序预期: 1 2 3
    TreeNode* root = new TreeNode(1);
    root->right = new TreeNode(2);
    root->right->left = new TreeNode(3);

    Solution s;
    vector<int> r1 = s.preorderTraversal(root);
    cout << "递归前序: ";
    for (int x : r1) cout << x << " ";
    cout << endl;

    vector<int> r2 = s.preorderTraversalIterative(root);
    cout << "迭代前序: ";
    for (int x : r2) cout << x << " ";
    cout << endl;
    return 0;
}
