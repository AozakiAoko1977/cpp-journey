#include <iostream>
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
public:
    int maxDepth(TreeNode* root) {
        if (root == nullptr) return 0;                    // 空树，深度 0（递归出口）
        return 1 + max(maxDepth(root->left),              // 1 + 左右子树更深的那个
                       maxDepth(root->right));
    }
};

int main() {
    // 构建树:
    //     3
    //    / \
    //   9  20
    //     /  \
    //    15   7
    // 最大深度预期: 3
    TreeNode* root = new TreeNode(3);
    root->left = new TreeNode(9);
    root->right = new TreeNode(20);
    root->right->left = new TreeNode(15);
    root->right->right = new TreeNode(7);

    Solution s;
    cout << "最大深度: " << s.maxDepth(root) << endl;
    cout << "空树深度: " << s.maxDepth(nullptr) << endl;  // 预期 0
    return 0;
}
