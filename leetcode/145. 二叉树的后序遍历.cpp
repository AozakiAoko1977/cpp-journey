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
    void postorder(TreeNode* node, vector<int>& result) {
    if (node == nullptr) return;
    postorder(node->left, result);    // 1. 走左
    postorder(node->right, result);   // 2. 走右
    result.push_back(node->val);      // 3. 最后访问根
}
public:
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> result;
        postorder(root,result);
        return result;
    }
    vector<int> postorderTraversalIterative(TreeNode* root) {
        vector<int> result;
        if(root == nullptr) return result;
        stack<TreeNode*> st;
        st.push(root);
        while(!st.empty()){
            TreeNode* node = st.top();
            st.pop();
            result.push_back(node -> val);
            if (node -> left){
                st.push(node -> left);
            }
            if (node -> right){
                st.push(node -> right);
            }
        }
        reverse(result.begin(),result.end());
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
