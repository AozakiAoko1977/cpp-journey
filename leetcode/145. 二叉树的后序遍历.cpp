#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>
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
    // 辅助函数：递归后序遍历，把结果装进 result
    // 后序顺序：左 -> 右 -> 根
    void postorder(TreeNode* node, vector<int>& result) {
    if (node == nullptr) return;      // 空节点直接返回（递归出口）
    postorder(node->left, result);    // 1. 走左
    postorder(node->right, result);   // 2. 走右
    result.push_back(node->val);      // 3. 最后访问根
}
public:
    // 递归版：从根节点开始，按 左 -> 右 -> 根 的顺序遍历
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> result;                   // 存放遍历结果
        postorder(root,result);               // 从根节点开始递归
        return result;
    }
    // 迭代版：巧用前序变形
    // 先按 根 -> 右 -> 左 的顺序遍历（把前序的压栈顺序反过来），最后整体反转即得 左 -> 右 -> 根 的后序
    vector<int> postorderTraversalIterative(TreeNode* root) {
        vector<int> result;                     // 存放遍历结果
        if(root == nullptr) return result;      // 空树直接返回
        stack<TreeNode*> st;                    // 栈：模拟递归调用
        st.push(root);                          // 根节点入栈
        while(!st.empty()){                     // 栈不空就一直处理
            TreeNode* node = st.top();          // 取出栈顶节点
            st.pop();                           // 弹出栈顶节点
            result.push_back(node -> val);      // 先访问根（得到 根->右->左）
            if (node -> left){
                st.push(node -> left);          // 先压左孩子
            }
            if (node -> right){
                st.push(node -> right);         // 再压右孩子，弹栈顺序为 根->右->左
            }
        }
        reverse(result.begin(),result.end());   // 整体反转，得到 左->右->根 的后序
        return result;
    }
};

int main() {
    // 构建树:
    //     1
    //    / \
    //   2   3
    //  / \
    // 4   5
    // 后序预期: 4 5 2 3 1
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);

    Solution s;
    vector<int> r1 = s.postorderTraversal(root);
    cout << "递归后序: ";
    for (int x : r1) cout << x << " ";
    cout << endl;

    vector<int> r2 = s.postorderTraversalIterative(root);
    cout << "迭代后序: ";
    for (int x : r2) cout << x << " ";
    cout << endl;
    return 0;
}
