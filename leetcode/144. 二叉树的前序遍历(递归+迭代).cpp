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
    void preorder(TreeNode* node, vector<int>& result) {
        if (node == nullptr) return;
        result.push_back(node->val);
        preorder(node->left, result);
        preorder(node->right, result);
    }

public:
    // 递归版
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> result;
        preorder(root, result);
        return result;
    }

    // 迭代版（用栈模拟递归）
    vector<int> preorderTraversalIterative(TreeNode* root) {
        vector<int> result;
        if (root == nullptr) return result;   // 空树
        stack<TreeNode*> st;
        st.push(root);
        while (!st.empty()) {
            TreeNode* node = st.top();
            st.pop();
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
