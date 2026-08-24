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
    void inorder(TreeNode* node, vector<int>& result) {
        if (node == nullptr) return;
        inorder(node->left, result);
        result.push_back(node->val);
        inorder(node->right, result);
    }
public:
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> result;
        inorder(root, result);
        return result;
    }
    vector <int> inorderTraversalIterative(TreeNode*root){
        vector <int> result;
        stack<TreeNode*> st;
        TreeNode* cur = root;
        while(cur != nullptr || !st.empty()){
            if(cur != nullptr){
                st.push(cur);
                cur = cur -> left;
            }
            else{
                cur = st.top();
                st.pop();
                result.push_back(cur -> val);
                cur = cur -> right;
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
