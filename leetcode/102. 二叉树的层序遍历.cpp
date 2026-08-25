#include <iostream>
#include <vector>
#include <queue>
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
    vector<vector<int>> levelOrder(TreeNode* root) {
        queue<TreeNode*> q;
        vector<vector<int>> result;
        if (root == nullptr) return result;   // 空树直接返回
        q.push(root);                          // 根节点先入队
        while (!q.empty()) {
            int size = q.size();               // 当前层的节点个数
            vector<int> level;                 // 装这一层的值
            for (int i = 0; i < size; i++) {
                TreeNode* node = q.front();
                q.pop();
                level.push_back(node->val);
                if (node->left) {
                    q.push(node->left);
                }
                if (node->right) {
                    q.push(node->right);
                }
            }
            result.push_back(level);           // 这一层处理完，存入结果
        }
        return result;
    }
};

int main() {
    // 构建树:
    //     3
    //    / \
    //   9  20
    //     /  \
    //    15   7
    // 层序预期: [3] [9 20] [15 7]
    TreeNode* root = new TreeNode(3);
    root->left = new TreeNode(9);
    root->right = new TreeNode(20);
    root->right->left = new TreeNode(15);
    root->right->right = new TreeNode(7);

    Solution s;
    vector<vector<int>> r = s.levelOrder(root);
    for (const auto& level : r) {
        cout << "[ ";
        for (int x : level) cout << x << " ";
        cout << "] ";
    }
    cout << endl;
    return 0;
}
