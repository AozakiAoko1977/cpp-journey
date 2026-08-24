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
    // 辅助函数：递归中序遍历，把结果装进 result
    // 中序顺序：左 -> 根 -> 右
    void inorder(TreeNode* node, vector<int>& result) {
        if (node == nullptr) return;          // 空节点直接返回（递归出口）
        inorder(node->left, result);          // 先递归左子树
        result.push_back(node->val);          // 再访问根节点
        inorder(node->right, result);         // 最后递归右子树
    }
public:
    // 递归版：从根节点开始，按 左 -> 根 -> 右 的顺序遍历
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> result;                   // 存放遍历结果
        inorder(root, result);                // 从根节点开始递归
        return result;
    }
    // 迭代版：用栈模拟递归
    // 思路：一路向左把节点全部压栈，走到最左端后再弹栈访问，然后转向右子树
    vector <int> inorderTraversalIterative(TreeNode*root){
        vector <int> result;                  // 存放遍历结果
        stack<TreeNode*> st;                  // 栈：保存“路过”的节点
        TreeNode* cur = root;                 // cur 指向当前节点，从根开始
        while(cur != nullptr || !st.empty()){ // 当前节点不为空或栈不空就继续
            if(cur != nullptr){               // 当前节点不为空
                st.push(cur);                 // 当前节点入栈
                cur = cur -> left;            // 继续一路向左
            }
            else{                             // 左边走到头了
                cur = st.top();               // 弹出栈顶节点
                st.pop();
                result.push_back(cur -> val); // 访问它（左 -> 根）
                cur = cur -> right;           // 再转向右子树
            }
        }
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
    // 中序预期: 4 2 5 1 3
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);

    Solution s;
    vector<int> r1 = s.inorderTraversal(root);
    cout << "递归中序: ";
    for (int x : r1) cout << x << " ";
    cout << endl;

    vector<int> r2 = s.inorderTraversalIterative(root);
    cout << "迭代中序: ";
    for (int x : r2) cout << x << " ";
    cout << endl;
    return 0;
}
